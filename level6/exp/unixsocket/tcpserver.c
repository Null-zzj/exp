#include <ctype.h>
#include <string.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/un.h>
#include <stddef.h>



#define PATH "serv.socket"

int main()
{
    int lfd;
    if((lfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_un seraddr;
    bzero(&seraddr, sizeof(seraddr));
    seraddr.sun_family = AF_UNIX;
    strcpy(seraddr.sun_path, PATH);
    unlink(PATH);    
    int ret = bind(lfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
    if(ret == -1)
    {
        perror("bind");
        exit(-1);
    }
    listen(lfd, 255);

    
    struct sockaddr_un cliaddr;
    socklen_t clilen = sizeof(cliaddr);
    memset(&cliaddr, 0, sizeof(cliaddr));

    int cfd = accept(lfd, (struct sockaddr*)&cfd, &clilen);
    if(cfd == -1)
    {
        perror("accept");
        exit(-1);
    }
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
