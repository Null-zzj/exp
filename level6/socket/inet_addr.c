#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>


int main()
{
    in_addr_t addr = inet_addr("127.0.0.1");

    printf("addr:%#x\n", addr);


    struct in_addr in_adr;
    in_adr.s_addr = addr;
    printf("in_addr: %s\n", inet_ntoa(in_adr));

    char buf[33] = {0};
    inet_ntop(AF_INET, &in_adr, buf, sizeof(buf));
    printf("ntop: %s\n", buf);

}
