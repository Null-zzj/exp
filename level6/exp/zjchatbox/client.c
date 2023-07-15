#include <arpa/inet.h>
#include <asm-generic/socket.h>
#include <bits/pthreadtypes.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SER_ADDR "127.0.0.1"
#define SER_PORT 10000

char readbuf[1024] = {0};

void *pthread(void *args);

typedef struct
{
    int cfd;
    struct sockaddr_in cli_addr;
} SOCKMSG;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    int ret;
    int cfd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in ser_addr;
    ser_addr.sin_addr.s_addr = htonl(0);
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(9999);
    socklen_t len = sizeof(ser_addr);

    int opt = 1;
    ret = setsockopt(cfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if(ret == -1)
    {
        perror("setsockopt");
        exit(-1);
    }
    ret = bind(cfd, (struct sockaddr *)&ser_addr, len);
    if (ret == -1)
    {
        perror("bind");
        exit(-1);
    }

    ser_addr.sin_addr.s_addr = inet_addr(SER_ADDR);
    ser_addr.sin_port = htons(SER_PORT);

    char buf[1024] = {0};

    if (ret == -1)
    {
        perror("fcntl");
        exit(-1);
    }

    pthread_t tid;
    SOCKMSG msg;
    msg.cfd = cfd;
    msg.cli_addr = ser_addr;

    tid = pthread_create(&tid, 0, pthread, (void *)&msg);

    while (1)
    {
        
        ret = read(cfd, buf, sizeof(buf));
        if(ret == -1)
        {
            perror("read");
            pthread_mutex_destroy(&mutex);
            close(cfd);
            pthread_join(tid, NULL);
            exit(-1);
        }
        buf[ret] = 0;

        pthread_mutex_lock(&mutex);
        printf("%s\n", buf);
        pthread_mutex_unlock(&mutex);
    }

    return 0;
}

void *pthread(void *args)
{
    int ret = 0;
    SOCKMSG *p = (SOCKMSG *)args;
    while (1)
    {
        pthread_mutex_lock(&mutex);
        ret = write(STDOUT_FILENO, ">", 1);
        if(ret == -1)
        {
            perror("write");
            pthread_exit(NULL);
        }
        fgets(readbuf, sizeof(readbuf) - 1, stdin);
        pthread_mutex_unlock(&mutex);
        readbuf[strlen(readbuf) - 1] = 0;
        sendto(p->cfd, readbuf, strlen(readbuf), 0, (struct sockaddr *)&p->cli_addr, sizeof(p->cli_addr));
        
    }
}