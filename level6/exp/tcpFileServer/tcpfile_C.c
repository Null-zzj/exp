#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


void printHelp();
int recvfile(int cfd, char* filename);
int sendfile(int cfd, char *filename);



int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("invalid arguments\n");
        return 0;
    }
    int cfd;
    if ((cfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in seraddr;
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(atoi(argv[2]));
    seraddr.sin_addr.s_addr = inet_addr(argv[1]);

    int ret = connect(cfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    if (ret == -1)
    {
        perror("connect");
        exit(-1);
    }
    
    printf("connect success\n");

    char buf[1024] = {0};
    while (1)
    {   write(STDIN_FILENO, ">", 1);
        bzero(buf, sizeof(buf));
        ret = read(STDIN_FILENO, buf, sizeof(buf));
        buf[ret - 1] = 0;
        // printf("read: %s\n", buf);
        if(ret == -1)
        {
            perror("read");
            exit(-1);
        }
        if (strcmp(buf, "help") == 0)
        {
            printHelp();
            puts("");
        }
        else if (strncmp(buf, "list", 4) == 0)
        {
            printf("File List: \n");
            write(cfd, "list", sizeof("list"));
            ret = read(cfd, buf, sizeof(buf));
            printf("**文件名称******************文件大小***\n");
            write(STDIN_FILENO, buf, ret);
            printf("***************************************\n");
        }
        else if (strncmp(buf, "quit", 4) == 0)
        {
            close(cfd);
            printf("close connect\n");
            break;
        }
        else if (strncmp(buf, "get", 3) == 0)
        {
            char *ptr = buf + 3;
            while(*(++ptr) == ' ');
            
            write(cfd, buf, strlen(buf));
            sleep(1);
            ret = recvfile(cfd, ptr);
            if(ret == 0)
            {
                printf("recvfile success\n\n");
            }
        }
        else if (strncmp(buf, "put", 3) == 0)
        {
            char *ptr = buf + 3;
            while(*(++ptr) == ' ');

            write(cfd, buf, strlen(buf));

            sleep(1);            
            ret = sendfile(cfd, ptr);
            if(ret == 0)
            {
                printf("sendfile success\n\n");
            }

        }
        else
        {
            printf("err\n");
            
        }
    }

    close(cfd);
    return 0;
}

void printHelp()
{
    printf("help:\n\
            help       :显示客户端所有命令和说明\n\
            list       :显示服务器端可下载文件列表\n\
            get <file> :下载文件\n\
            put <file> :上传文件\n\
            quit       :退出客户端\n");
}


int recvfile(int cfd, char* filename)
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
    while((ret = read(cfd, buf, sizeof(buf))) != 0)
    {
        buf[ret] = 0;
        if(ret == -1)
        {
            perror("read");
            return -1;
        }
        write(fd, buf, ret);
        
        sizeCount += ret;
        
        if(sizeCount == filesize)
        {
            break;
        }
    }


    close(fd);
    return 0;
}


int sendfile(int cfd, char *filename)
{
    int ret, fd;
    int filesize;
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
    write(cfd, buf, strlen(buf) + 1);
    sleep(1); 
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }

    
    while ((ret = read(fd, buf, sizeof(buf))) > 0)  // 发送文件
        write(cfd, buf, ret);
    
    
    return 0;
}
