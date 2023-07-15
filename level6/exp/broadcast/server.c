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

int main(int argc, char *argv[])
{
    int ret;
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    int opt = 1;
    ret = setsockopt(sfd, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(opt));

    struct sockaddr_in cli_addr;
    bzero(&cli_addr, sizeof(cli_addr));
    cli_addr.sin_addr.s_addr = inet_addr("172.28.111.255");
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_port = htons(9999);

    ret = sendto(sfd, "broadcast message", sizeof("broadcast message"), 0, (struct sockaddr*)&cli_addr, sizeof(cli_addr));
    printf("send to %d\n", ret);





    return 0;
}