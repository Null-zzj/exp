#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>

void setnunblock(int fd)
{
    int flag = fcntl(fd, F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
}

int main()
{
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    int ret;
    if(-1 == sfd)
    {
        perror("socket");
        exit(-1);
    }
    struct sockaddr_in seraddr;
    seraddr.sin_port = htons(9999);
    seraddr.sin_addr.s_addr = htons(INADDR_ANY);
    seraddr.sin_family = AF_INET;
    ret = bind(sfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
    if(-1 == ret)
    {
        perror("bind");
        exit(-1);
    }

    setnunblock(sfd);

    char buf[1024] = {0};
    struct sockaddr_in cliaddr;
    socklen_t addr_len = sizeof(cliaddr);
    while(1)
    {
        ret = recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr*)&cliaddr,  &addr_len);
        if(0 == ret)
        {
            printf("client is close\n");
        }
        
        buf[ret] = 0;
        printf("recv client: %s\n", buf);
        for(int i = 0; i < ret; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        sendto(sfd, buf, ret, 0, (struct sockaddr*)&cliaddr, addr_len);
    
    }



    return 0;
}
