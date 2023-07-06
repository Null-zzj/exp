/*********************************************
* @FileName: fifo.c
* @Author: Null-zzj
* @Mail: zj.zhu.cn@gmail.com
* @CreatedTime: Tue Jul 04 09:15:33 2023
* @Descript:
*/

#include<apue.h>
#include<error.h>
#include<fcntl.h>


int main(int argc, char* argv[])
{
    int fd[2];
    int ret;
    pipe(fd);
    char buf[255] = {0};

    pid_t pid;
    if((pid = fork()) < 0)
        err_sys("fork");
    else if(pid == 0)
    {
        close(fd[1]);
        while(ret = read(fd[0], buf, sizeof(buf)))
        {
            write(STDOUT_FILENO, buf, ret);
        }
    }else{
        close(fd[0]);
        while(ret = read(STDIN_FILENO, buf, sizeof(buf)))
        {
            buf[ret] = '\0';
            write(fd[1], buf, ret);
        }
    }


    return 0;
}