/*===============================================
*   文件名称：runnian.c
*   创 建 者：     
*   创建日期：2023年05月29日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int year;
    printf("input a year\n");
    scanf("%d", &year);

    if((year%4==0 && year%100)  || (year%100==0 && year%400==0)){
        printf("%d是闰年\n",year);
    }else
        printf("%d不是闰年\n",year);
    return 0;
} 
