#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int ret;
    int cfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (cfd == -1)
    {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_family = htonl(INADDR_ANY);
    addr.sin_port = htons(9999);
    socklen_t len = sizeof(addr);

    ret = bind(cfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1)
    {
        perror("bind");
        exit(-1);
    }
    bzero(&addr, sizeof(addr));

    fd_set all_set;
    bzero(&all_set, sizeof(all_set));
    int maxfd;
    FD_SET(STDIN_FILENO, &all_set);
 
    FD_SET(cfd, &all_set);
    int nfds = cfd +1;
    int nread;
    char buf[128] = {0};
    while (1)
    {      
        nread = select(nfds, &all_set, NULL, NULL, NULL);
        if (nread == -1)
        {
            perror("select");
            exit(-1);
        }
        
        
        if (FD_ISSET(STDIN_FILENO, &all_set))
        {
            fgets(buf, sizeof(buf), stdin);

            if (strncmp(buf, "quit", 4) == 0)
            {
                break;
            }
        }
        
       
            
        if ((FD_ISSET(cfd, &all_set)))
        {
            ret = recvfrom(cfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, &len);
            if(ret == -1)
            {
                perror("recvfrom");
                break;
            }
            sendto(cfd, buf, ret, 0, (struct sockaddr *)&addr, len);
        }
        
        
    }


    close(cfd);

    return 0;
}
