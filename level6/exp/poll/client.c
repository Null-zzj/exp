#include <math.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/select.h>

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

    int maxfd = cfd;
    fd_set r_set, all_set;
    FD_ZERO(&all_set);

    FD_SET(0, &all_set);
    FD_SET(cfd, &all_set);
    int nread;
    while (1)
    {
        r_set = all_set;
        nread = select(maxfd + 1, &r_set, NULL, NULL, NULL);
        if (nread > 0)
        {
            if (FD_ISSET(STDIN_FILENO, &r_set))
            {
                // ret = read(STDIN_FILENO, buf, sizeof(buf));
                fgets(buf, sizeof(buf), stdin);
                if (ret == -1)
                {
                    perror("read");
                    exit(-1);
                }

                if (strncmp(buf, "quit", 4) == 0)
                {
                    close(cfd);
                    break;
                }
                write(cfd, buf, strlen(buf));

                
            }
            if(FD_ISSET(cfd, &r_set))
            {
                ret = read(cfd, buf, sizeof(buf));
                if(ret == 0)
                {
                    printf("server close\n");
                    exit(0);
                }
                buf[ret] = 0;
                printf("recv server: %s", buf);
            }
            
        }
        
    }

    return 0;
}
