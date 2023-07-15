#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>


__sighandler_t _signal(int signo, __sighandler_t func)
{
    struct sigaction nact, oact;
    nact.sa_handler = func;
    sigemptyset(&nact.sa_mask);

    if(SIGALRM == signo)
    {
#ifdef SA_INTERRUPT
        nact.sa_flags = SA_INTERRUPT;
#endif
    }
    else
    {
        nact.sa_flags = SA_RESTART;
    }

    sigaction(signo, &nact, &oact);


    return oact.sa_handler;
    
}

void handler(int signo)
{
    printf("catch the signal: %s\n", strsignal(signo));
    alarm(2);
}


int main()
{
    _signal(SIGINT, SIG_IGN);


    while(1);
    return 0;
}

