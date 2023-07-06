#include<myinclude.h>
#include<signal.h>
#include<time.h>
#include<sys/time.h>
void handler(int signo)
{
    printf("catch the sig : %d\n", signo);
}

int main()
{
    signal(SIGALRM, handler);
    signal(SIGVTALRM, handler);
    signal(SIGPROF, handler);
    struct itimerval time;
    time.it_value.tv_sec = 2;
    time.it_interval.tv_sec = 0;
    time.it_interval.tv_usec = 0;
    //setitimer(ITIMER_REAL, &time, NULL);

    time.it_interval.tv_sec = 1;

    setitimer(ITIMER_REAL, &time, NULL);
    while(1);





}
