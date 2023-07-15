#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    int cfd;
    cfd = socket(AF_INET, SOCK_STREAM, 0);
    if (cfd == -1)
    {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in cliaddr;
    cliaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    cliaddr.sin_port = htons(9999);
    cliaddr.sin_family = AF_INET;

    int ret = connect(cfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    if (ret == -1)
    {
        perror("connect");
        exit(-1);
    }
    char buf[1024] = {0};

    while (1)
    {
        ret = read(STDIN_FILENO, buf, sizeof(buf));
        if (ret == -1)
        {
            perror("read");
            exit(-1);
        }
        
        if(strncmp(buf, "quit", 4) == 0)
        {
            close(cfd);
            break;
        }
        write(cfd, buf, ret);

        ret = read(cfd, buf, sizeof(buf));
        buf[ret] = 0;
        printf("recv server: %s", buf);
    }

    return 0;
}
