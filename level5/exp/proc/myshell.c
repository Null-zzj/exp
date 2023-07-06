/*********************************************
* @FileName: myshell.c
* @Author: Null-zzj
* @Mail: zj.zhu.cn@gmail.com
* @CreatedTime: Mon Jul 03 13:17:29 2023
* @Descript:
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<pwd.h>
#include<sys/wait.h>
#include<signal.h>

char *username;
char hostname[255] = {0};
char cwd[255] = {0};


void hander(int sig)
{
    puts("");
    printf("\033[;32m%s@%s\033[0m \033[;34m%s\033[0m $ ", username, hostname, cwd);
}

void strucArgv(char *buf, char **argv);
int main()
{
    signal(SIGINT, hander);
    pid_t pid;
    struct passwd *pwd;
    pwd = getpwuid(getuid());
    username = pwd->pw_name;
    
    int ret = gethostname(hostname, sizeof(hostname) - 1);
    
    getcwd(cwd, sizeof(cwd) - 1);

    char cmd[255] = {0};
    char *argv[20] = {0};
    while(1)
    {
        getcwd(cwd, sizeof(cwd) - 1);
        printf("\033[;32m%s@%s\033[0m \033[;34m%s\033[0m $ ", username, hostname, cwd);
        fflush(stdin);
        fgets(cmd, sizeof(cmd), stdin);
        strucArgv(cmd, argv);
        if(*cmd == '\n')
        {
            continue;
        }

        if((pid = fork()) < 0)
            ;
        else if(pid == 0)
        {
           execvp(argv[0], argv);
           
           
        }else
        {
            wait(NULL);
        }
    }

    return 0;
}

void strucArgv(char *buf, char **argv)
{
    int j = 0;
    int k;
    int len = strlen(buf);
    for(int i = 0; i < len; i++)
    {
        if(buf[i] == ' ')
            continue;
        
        if(buf[i] != ' ')
        {
            argv[j] = &buf[i];
            j++;
            for(k = i; buf[k] != ' ' && buf[k] != '\0' && buf[k] != '\n'; k++)
            {
                i++;
            }
            buf[k] = '\0';
            
        }
    }
}