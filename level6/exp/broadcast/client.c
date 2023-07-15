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

    struct sockaddr_in ser_addr;
    ser_addr.sin_addr.s_addr = htonl(0);
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
    read(cfd, buf, sizeof(buf));

    printf("%s\n", buf);
    return 0;
}