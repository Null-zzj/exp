/*********************************************
* @FileName: test.c
* @Author: Null-zzj
* @Mail: zj.zhu.cn@gmail.com
* @Created Time: Tue Jul  4 14:54:34 2023
*********************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include<signal.h>



void sys_sig(int signo){

  printf("----catch sign %d\n", signo);
  alarm(2);  
}

int main(int argc,char *argv[])
{
  signal(SIGINT,sys_sig);
  signal(SIGQUIT, sys_sig);

    while (1);
  return 0;
}
