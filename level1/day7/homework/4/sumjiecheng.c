/*===============================================
*   文件名称：sumjiecheng.c
*   创 建 者：     
*   创建日期：2023年05月30日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int total = 0;
    int num = 1;
    for(int i = 1; i <= 4; i++){
        num *= i;
        total += num;
    }

    printf("1!+2!+3!+4! = %d\n", total);
    return 0;
} 
