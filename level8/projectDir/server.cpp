#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <thread>
#include <arpa/inet.h>
#include "processor.h"



typedef struct
{
    int cfd;
    struct sockaddr_in cli_addr;
    socklen_t addrlen;
} SOCKMSG;




void *thread(void *msg);
int sockinit(char *ipaddr, unsigned short port);

int main(int argc, char *argv[])
{
    int ret;
    pthread_t tid;

    int lfd = sockinit(NULL, 9999);

    SOCKMSG cli_msg;
    bzero(&cli_msg, sizeof(cli_msg));
    cli_msg.addrlen = sizeof(cli_msg.addrlen);

    while (1)
    {
        int cfd = accept(lfd, (struct sockaddr *)&cli_msg.cli_addr, &cli_msg.addrlen);
        if (cfd == -1)
        {
            perror("accept");
            exit(-1);
        }
        cli_msg.cfd = cfd;

        printf("client ip: %s, port: %d connect success\n", inet_ntoa(cli_msg.cli_addr.sin_addr),
               ntohs(cli_msg.cli_addr.sin_port));

        ret = pthread_create(&tid, NULL, thread, (void *)&cli_msg);
        if (ret != 0)
        {
            printf("%s\n", strerror(ret));
            exit(-1);
        }
        ret = pthread_detach(tid);
        if (ret != 0)
        {
            printf("%s\n", strerror(ret));
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

void *thread(void *msg)
{
    SOCKMSG *p = (SOCKMSG *)msg;
    SOCKMSG climsg;
    climsg.cfd = p->cfd;
    climsg.cli_addr = p->cli_addr;
    climsg.addrlen = p->addrlen;

    int ret;
    char buf[1024] = {0};

    processor *pro = new processor;
    while (1)
    {

        




    }
}


int sockinit(char *ipaddr, unsigned short port)
{
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1)
    {
        perror("socket");
        return -1;
    }
    struct sockaddr_in seraddr;
    bzero(&seraddr, sizeof(seraddr));
    seraddr.sin_addr.s_addr = INADDR_ANY;
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(port);
    int ret = bind(lfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    if (ret == -1)
    {
        perror("bind");
        exit(-1);
    }
    ret = listen(lfd, 255);
    if (ret == -1)
    {
        perror("listen");
        exit(-1);
    }
    return lfd;
}