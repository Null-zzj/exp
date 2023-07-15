#include <asm-generic/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>
#include <time.h>

#define BROADADDR "172.28.111.255"
#define BROADPORT 9999
#define PORT 10000

typedef struct{
    int fd;
    struct sockaddr_in addr;
}BROADCAST;


BROADCAST broadcast_init(char* broadaddr, int port);
int serversocket_init(int port);

int main()
{
    int ret;
    time_t _time;
    struct tm* t;
    BROADCAST broad = broadcast_init(BROADADDR, BROADPORT);
    
    int serfd = serversocket_init(PORT);
    
    char buf[1024] = {0};
    char timebuf[30] = {0};
    char readbuf[255] = {0};
    

    while(1)
    {
        bzero(readbuf, sizeof(readbuf));
        bzero(timebuf, sizeof(timebuf));

        ret = read(serfd, readbuf, sizeof(readbuf));
        if(-1 == ret)
        {
            perror("recvfrom");
            exit(-1);
        }
        _time = time(NULL);
         
        t = localtime(&_time);
        strftime(timebuf, sizeof(timebuf), "%D %T\n", t);
        printf("timebuf: %s\n", timebuf);
        printf("buf: %s\n", buf);
        sprintf(buf, "%s  %s", timebuf, readbuf);
        // printf("buf: %s", buf);
        sendto(broad.fd, buf, strlen(buf), 0, (struct sockaddr*)&broad.addr, sizeof(broad.addr));
    }

}


BROADCAST broadcast_init(char* broadaddr, int port)
{
    int ret;
    int fd = socket(AF_INET, SOCK_DGRAM, 0);  // 广播套接字
    if(-1 == fd)
    {
        perror("socket");
        exit(-1);
    }
    int opt = 1;
    ret = setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(opt));
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(broadaddr);

    BROADCAST broad;
    broad.fd = fd;
    broad.addr = addr;

    return broad;
}


int serversocket_init(int port)
{
    int ret;
    int serfd = socket(AF_INET, SOCK_DGRAM, 0);   // 服务端套接字
    if(-1 == serfd)
    {
        perror("socket");
        exit(-1);
    }
    struct sockaddr_in seraddr;
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    seraddr.sin_port = htons(10000);

    int opt = 1;
    ret = setsockopt(serfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if(ret == -1)
    {
        perror("setsockopt");
        exit(-1);
    }


    ret = bind(serfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
    if(-1 == ret)
    {
        perror("bind");
        exit(-1);
    }

    return serfd;
}