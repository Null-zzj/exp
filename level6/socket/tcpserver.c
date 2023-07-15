#include <ctype.h>
#include <string.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
    int lfd;
    if((lfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in seraddr;
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    seraddr.sin_port = htons(7899);
    
        
    int ret = bind(lfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
    listen(lfd, 255);

    
    struct sockaddr_in cliaddr;
    socklen_t clilen = sizeof(cliaddr);
    memset(&cliaddr, 0, sizeof(cliaddr));

    int cfd = accept(lfd, (struct sockaddr*)&cfd, &clilen);
    char buf[1024] = {0};
    while(1)
    {
        ret = read(cfd, buf, sizeof(buf));
        if(ret == -1)
        {
            perror("read");
            exit(-1);
        }
        if(ret == 0)
        {
            printf("connect ulink\n");
            break;
        }

        for(int i = 0; i < ret; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        
        write(cfd, buf, ret);

    }



}
