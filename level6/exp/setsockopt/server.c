#include <asm-generic/socket.h>
#include <bits/types/struct_timeval.h>
#include <ctype.h>
#include <string.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
    int lfd;
    if((lfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(-1);
    }
    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
   
    int len = sizeof(opt);
    getsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, (socklen_t*)&len);
    printf("opt: %d\n", opt);
    

    struct sockaddr_in seraddr;
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    seraddr.sin_port = htons(7899);
    
        
    int ret = bind(lfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
    listen(lfd, 255);

    
    struct sockaddr_in cliaddr;
    socklen_t clilen = sizeof(cliaddr);
    memset(&cliaddr, 0, sizeof(cliaddr));

    int cfd = accept(lfd, (struct sockaddr*)&cfd, &clilen);

    struct timeval time;
    time.tv_sec = 1;
    time.tv_usec = 0;
    ret = setsockopt(cfd, SOL_SOCKET, SO_RCVTIMEO, &time, sizeof(time));
    if(-1 == ret)
    {
        perror("setsockopt");
        exit(1);
    }
    char buf[1024] = {0};
    while(1)
    {
        ret = read(cfd, buf, sizeof(buf));
        if(ret == -1)
        {
            perror("read");
            continue;
        }
        if(ret == 0)
        {
            printf("connect ulink\n");
            break;
        }

        for(int i = 0; i < ret; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        
        write(cfd, buf, ret);

    }

}
