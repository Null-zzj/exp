#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/un.h>

#define PATH "serv.socket"

int main()
{
    int cfd;
    cfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (cfd == -1)
    {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_un cliaddr;
    cliaddr.sun_family = AF_UNIX;
    strcpy(cliaddr.sun_path, PATH);


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
