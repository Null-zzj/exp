#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>
#include <ctype.h>
#include <signal.h>
#include <sys/wait.h>

typedef struct
{
    int cfd;
    struct sockaddr_in cli_addr;
    socklen_t addrlen;
} SOCKMSG;


int sockinit(char *ipaddr, unsigned short port);
void handler(int signo);

int main(int argc, char *argv[])
{
    int ret;
    int lfd = sockinit(NULL, 9999);

    signal(SIGCHLD, handler);

    SOCKMSG cli_msg;
    bzero(&cli_msg, sizeof(cli_msg));
    cli_msg.addrlen = sizeof(cli_msg.addrlen);

    while (1)
    {
        int cfd = accept(lfd, (struct sockaddr *)&cli_msg.cli_addr, &cli_msg.addrlen);
        if (cfd == -1)
        {
            perror("accept");
            exit(-1);
        }
        cli_msg.cfd = cfd;

        printf("client ip: %s, port: %d connect success\n", inet_ntoa(cli_msg.cli_addr.sin_addr), ntohs(cli_msg.cli_addr.sin_port));

        ret = fork();
        if (ret == -1)
        {
            perror("fork");
            exit(-1);
        }
        else if (ret == 0)
        {
            int ret;
            char buf[1024] = {0};
            while (1)
            {
                ret = read(cli_msg.cfd, buf, sizeof(buf));
                if (ret == -1)
                {
                    perror("read");
                    pthread_exit(NULL);
                }
                if (ret == 0)
                {
                    printf("client ip: %s, port: %d disconnect\n", inet_ntoa(cli_msg.cli_addr.sin_addr), ntohs(cli_msg.cli_addr.sin_port));
                    close(cli_msg.cfd);
                    exit(0);
                }

                for (int i = 0; i < ret; i++)
                {
                    buf[i] = toupper(buf[i]);
                }
                write(cli_msg.cfd, buf, ret);
            }
        }
        else
        {
            close(cfd);
        }
    }
    return 0;
}

int sockinit(char *ipaddr, unsigned short port)
{
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1)
    {
        perror("socket");
        return -1;
    }
    struct sockaddr_in seraddr;
    bzero(&seraddr, sizeof(seraddr));
    seraddr.sin_addr.s_addr = INADDR_ANY;
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(port);
    int ret = bind(lfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    if (ret == -1)
    {
        perror("bind");
        exit(-1);
    }
    ret = listen(lfd, 255);
    if (ret == -1)
    {
        perror("listen");
        exit(-1);
    }
    return lfd;
}

void handler(int signo)
{
    int ret;
    while((ret = waitpid(-1, NULL, WNOHANG)) != 0
    )
    {
        printf("wait the child: %d\n", ret);
        
    }
}