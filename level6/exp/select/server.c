#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/select.h>
#include <arpa/inet.h>

int sockinit(char *ipaddr, unsigned short port);
int main()
{
    int nread, ret;
    int lfd = sockinit(NULL, 9999);
    
    struct sockaddr_in cliaddr;
    bzero(&cliaddr, sizeof(cliaddr));
    socklen_t clilen = sizeof(cliaddr);

    fd_set r_set, all_set;
    int maxfd = lfd;
    FD_ZERO(&all_set);
    FD_SET(lfd, &all_set);

    char buf[1024] = {0};

    struct timeval time;
    time.tv_sec = 1;
    time.tv_usec = 10000000;
    while(1)
    {
        r_set = all_set;
        nread = select(maxfd + 1, &r_set, NULL, NULL, &time);
        if(nread == 0)
        {
            perror("select");
            continue;
        }
    
        for(int i = lfd; i <= maxfd; i++)
        {
            if(FD_ISSET(i, &r_set))
            {
                printf("%d\n", i);
            }
        }
        printf("nread = %d\n", nread);
        if(nread > 0)
        {
            if(FD_ISSET(lfd, &r_set))
            {
                int cfd = accept(lfd, (struct sockaddr*)&cliaddr, &clilen);
                if(cfd == -1)
                {
                    perror("accept");
                    exit(-1);
                }
                FD_SET(cfd, &all_set);
                printf("ip: %s, port: %d connect success\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                if(cfd > maxfd)
                {
                    maxfd = cfd;
                }
                nread --;
            }
            
            if(!nread)
            {
                continue;
            }
            // printf("nread > 1\n");
            for(int i = lfd+1; i <= maxfd; i++)
            {
                if(FD_ISSET(i, &r_set))
                {
                    ret = read(i, buf, sizeof(buf));
                    if(ret == -1)
                    {
                        perror("read");
                        exit(-1);
                    }
                    if(ret == 0)
                    {
                        FD_CLR(i, &all_set);
                        close(i);
                        printf("the client close\n");
                        
                    }
                    for(int i = 0; i < ret; i++)
                    {
                        buf[i] = toupper(buf[i]);
                    }
                    write(i, buf, ret);           
                }
                

            }
        }
    }

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
        perror("bind");
        exit(-1);
    }
    return lfd;
}


