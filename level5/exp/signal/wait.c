#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

void handler(int signo)
{
    int ret;
    while((ret = waitpid(-1, NULL, 0)) != -1)
    {
        printf("wait the child: %d\n", ret);
        
    }
}
int main()
{

    pid_t pid;
       
    signal(SIGCHLD, handler);    
        
    for(int i = 0; i < 15; i++)
    {
        if((pid = fork()) == 0)
        {
            sleep(2);
            exit(0);
        }
        
    
    }
    
    sleep(5);


}
