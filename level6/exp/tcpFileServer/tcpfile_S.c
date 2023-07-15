#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int sendfile(int cfd, char *filename);
int recvfile(int cfd, char *filename);
int getList(int cfd);

int main()
{
    int lfd, cfd;
    if ((lfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in seraddr;
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = INADDR_ANY;
    seraddr.sin_port = htons(9999);

    int ret = bind(lfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    if (ret == -1)
    {
        perror("bind");
        exit(-1);
    }

    ret = listen(lfd, 255);
    if (ret == -1)
    {
        perror("bind");
        exit(-1);
    }

    struct sockaddr_in cliaddr;
    socklen_t clilen = sizeof(cliaddr);
    cfd = accept(lfd, (struct sockaddr *)&cliaddr, &clilen);
    if (cfd == -1)
    {
        perror("accept");
        exit(-1);
    }
    printf("the client connect success\n");

    char buf[1024] = {0};
    while (1)
    {
        bzero(buf, sizeof(buf));
        ret = read(cfd, buf, sizeof(buf));
        buf[ret] = 0;
        printf("recv: %s\n", buf);
        if (ret == -1)
        {
            perror("read");
            exit(-1);
        }
        //printf("read: %s\n", buf);
        if (ret == 0)
        {
            printf("client quit\n");
            break;
        }
        
        if (strncmp(buf, "get", 3) == 0)
        {
            printf("get\n");
            char *ptr = buf + 3;
            while(*(++ptr) == ' ');
            printf("file name: %s\n", ptr);
            sendfile(cfd, ptr);
        }
        else if (strncmp(buf, "put", 3) == 0)
        {
            char *ptr = buf + 3;
            while(*(++ptr) == ' ');
            
            
            ret = recvfile(cfd, ptr);
            if(ret == 0)
            {
                printf("recvfile success\n");
            }
        }
        else if (strncmp(buf, "list", 4) == 0)
        {
            getList(cfd);            
        }
        else
        {
            printf("err");
        }
    }


    close(lfd);
    close(cfd);
    return 0;
}

int sendfile(int cfd, char *filename)
{
    int ret, filesize, fd;
    struct stat fstat;
    char buf[1024] = {0};
    ret = stat(filename, &fstat);
    if(ret == -1)
    {
        printf("没有这个文件\n");
        write(cfd, "没有这个文件", sizeof("没有这个文件"));
        return -1;
    }

    filesize = fstat.st_size;
    sprintf(buf, "%d", filesize);
    sleep(1);
    write(cfd, buf, strlen(buf) + 1);
    sleep(1);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return -1;

    
    while ((ret = read(fd, buf, sizeof(buf))) > 0){  // 发送文件
        write(cfd, buf, ret);    
    }

    close(fd);
    printf("send success\n");
    return 0;
}

int recvfile(int cfd, char *filename)
{
    int ret;
    int filesize;
    char buf[1024] = {0};

    ret = read(cfd, buf, sizeof(buf));
    buf[ret] = 0;
    if(strcmp(buf, "没有这个文件") == 0)
    {
        printf("没有这个文件\n");
        return -1;
    }

    filesize = atoi(buf);
    printf("文件大小为 %d\n", filesize);
    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0664);
    if(fd == -1)
    {
        perror("open");
        return -1;
    }

    
    lseek(fd, 0, SEEK_SET);
    int sizeCount = 0;
    while((ret = read(cfd, buf, sizeof(buf))) > 0)
    {
        buf[ret] = 0;
        
        int i = write(fd, buf, ret);
        // printf("写入 = %d字节\n", i);
        sizeCount += ret;
        
        if(sizeCount == filesize)
        {
            break;
        }
    }
    close(fd);
    return 0;
}


int getList(int cfd)
{ 
    struct dirent *sdp;
    DIR* dp = opendir("./");
    int ret;
    char buf[1024] = {0};
    while((sdp = readdir(dp)) != 0)
    {
        if (!strcmp(sdp->d_name, ".") | !strcmp(sdp->d_name, ".."))
            continue;
        struct stat fstat;
        stat(sdp->d_name, &fstat);
        sprintf(buf, "%s%-30s%-10ld\n", buf, sdp->d_name, fstat.st_size);
        
    }
    
    write(cfd, buf, strlen(buf));
        
    return 0;
}

