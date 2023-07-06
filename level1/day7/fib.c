/*===============================================
*   文件名称：fib.c
*   创 建 者：     
*   创建日期：2023年05月30日
*   描    述：
================================================*/
#include <stdio.h>

int fib(int i);
    

int m\:ain(int argc, char *argv[])
{
    for(int i = 1; i <= 8; i++)
    printf("%d\n", fib(i));
    return 0;
} 


int fib(int i)
{
    if(i == 1 || i == 2){
        return 1;
    }

    return fib(i - 1) + fib(i - 2);


}
