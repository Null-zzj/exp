#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int sockinit(char *ipaddr, unsigned short port)
{
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if(lfd == -1)
    {
        perror("socket");
        return -1;
    }
    struct sockaddr_in seraddr;
    bzero(&seraddr, sizeof(seraddr));
    seraddr.sin_addr.s_addr = INADDR_ANY;
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(port);
    int ret = bind(lfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
    if(ret == -1)
    {
        perror("bind");
        exit(-1);

    }
    ret = listen(lfd, 255);
    if(ret == -1)
    {
        perror("listen");
        exit(-1);

    }
    return lfd;
}

int main()
{

}

int sockinit(char *ipaddr, unsigned short port)
{
int lfd = socket(AF_INET, SOCK_STREAM, 0);
if(lfd == -1)
{
perror("socket");
return -1;
}
struct sockaddr_in seraddr;
bzero(&seraddr, sizeof(seraddr));
seraddr.sin_addr.s_addr = INADDR_ANY;
seraddr.sin_family = AF_INET;
seraddr.sin_port = htons(port);
int ret = bind(lfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
if(ret == -1)
{
perror("bind");
exit(-1);
}
ret = listen(lfd, 255);
if(ret == -1)
{
perror("listen");
exit(-1);
}
return lfd;
}
int sockinit(char *ipaddr, unsigned short port)
{
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if(lfd == -1)
    {
        perror("socket");
        return -1;
    }
    struct sockaddr_in seraddr;
    bzero(&seraddr, sizeof(seraddr));
    seraddr.sin_addr.s_addr = INADDR_ANY;
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(port);
    int ret = bind(lfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
    if(ret == -1)
    {
        perror("bind");
        exit(-1);
    }
    ret = listen(lfd, 255);
    if(ret == -1)
    {
        perror("listen");
        exit(-1);
    }
    return lfd;
}