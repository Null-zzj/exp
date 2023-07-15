#include <asm-generic/socket.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/select.h>
#include <arpa/inet.h>


int main()
{
    int ret;
    int cfd = socket(AF_INET, SOCK_DGRAM, 0);

    struct ip_mreq mreq;
    bzero(&mreq, sizeof(mreq));
    mreq.imr_multiaddr.s_addr = inet_addr("224.10.10.1");
    mreq.imr_interface.s_addr = inet_addr("0.0.0.0");
    if(-1 == setsockopt(cfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)))
    {
        perror("setsockopt");
        exit(-1);
    }

    struct sockaddr_in ser_addr;
    ser_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(9999);
    socklen_t len = sizeof(ser_addr);

    ret = bind(cfd, (struct sockaddr*)&ser_addr, len);
    if(ret == -1)
    {
        perror("bind");
        exit(-1);
    }
    char buf[1024] = {0};
    while(1)
    {
        read(cfd, buf, sizeof(buf));
        printf("%s\n", buf);
    }
    return 0;
}