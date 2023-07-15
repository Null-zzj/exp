#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <poll.h>
#include <arpa/inet.h>
#include <limits.h>

int sockinit(char *ipaddr, unsigned short port);
int main()
{
    int nread, ret, cfd, i;
    int lfd = sockinit(NULL, 9999);
    
    struct sockaddr_in cliaddr;
    bzero(&cliaddr, sizeof(cliaddr));
    socklen_t clilen = sizeof(cliaddr);
    
    struct pollfd fds[__FD_SETSIZE];
    for(i = 0; i < __FD_SETSIZE; i++)
    {
        fds[i].fd = -1;
    }

    
    fds[0].fd = lfd;
    fds[0].events = POLLIN;
    int lastfd = 0;

    
    char buf[1024];

    while(1)
    {
        
        nread = poll(fds, lastfd + 1, -1);
        // printf("nread = %d\n", nread);
        // for(i = 0; i <= lastfd; i++)
        //     if(fds[i].fd != -1)
        //     {
        //         printf("fd= %d  ", fds[i].fd);
        //         printf("revent= %d\n", fds[i].revents);
        //     }
            
    
        
        if(nread > 0)
        {
            if(fds[0].revents & POLLIN)  // 建立连接
            {
                cfd = accept(lfd, (struct sockaddr*)&cliaddr, &clilen);
                if(cfd == -1)
                {
                    perror("accept");
                    exit(-1);
                }
                for(i = 0; i < __FD_SETSIZE; i++)
                {
                    if(fds[i].fd == -1)
                    {
                        fds[i].fd = cfd;
                        fds[i].events = POLLIN;
                        fds[i].revents = 0;
                        printf("i = %d\n", i);
                        break;
                    }
                }
                if(i > lastfd)
                {
                    lastfd = i;
                }
                printf("ip: %s, port: %d connect success\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                
                if(--nread == 0)
                    continue;
            }
                
            for(int i = 1; i <= lastfd; i++)
            {
                if(fds[i].revents & POLLIN)
                {
                    printf("read fd= %d\n", fds[i].fd);
                    ret = read(fds[i].fd, buf, sizeof(buf));
                    if(ret == -1)
                    {
                        perror("read");
                        exit(-1);
                    }
                    printf("read over\n");
                    if(ret == 0)
                    {
                        fds[i].fd = -1;
                        printf("close: i= %d\n", i);
                        close(i);
                        printf("the client close\n");
                        
                    }
                    for(int i = 0; i < ret; i++)
                    {
                        buf[i] = toupper(buf[i]);
                    }
                    write(fds[i].fd, buf, ret); 
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


