#include<apue.h>
#include<error.h>
#include<fcntl.h>

void strucArgv(char *buf, char **argv)
{
    int j = 0;
    int k;
    int len = strlen(buf);
    for(int i = 0; i < len; i++)
    {
        if(buf[i] == ' ')
            continue;
        
        if(buf[i] != ' ' || buf[i] != '\0')
        {
            argv[j] = &buf[i];
            j++;
            for(k = i; buf[k] != ' ' && buf[k] != '\0'; k++)
            {
                i++;
            }
            buf[k] = '\0';
            
        }
    }
}

int main()
{
    char buf[30] = "ls -l";
    char *argv[20] = {0};
    strucArgv(buf, argv);
    int i = 0;
 
        printf("%d\n", strcmp(argv[0], "ls"));
    return 0;
}

