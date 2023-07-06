#include <bits/types/sigset_t.h>
#include<myinclude.h>
#include<signal.h>
#include <stdio.h>

void handler(int signo)
{
    printf("catch the sig %s\n", strsignal(signo));
}


int main()
{
    struct sigaction act;
    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGQUIT);
    act.sa_flags = 0;
    sigaction(SIGINT, &act, NULL);


    while(1);
}
