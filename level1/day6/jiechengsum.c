/*===============================================
*   文件名称：jiechengsum.c
*   创 建 者：     
*   创建日期：2023年05月29日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    long long total;
    long long sum = 1;
    for(int i = 1; i <= 20; i++){
        sum *= i;
        printf("%d的阶乘为%lld\n", i, sum);
        total += sum;
    }
    printf("1！+2！+3！+...+20!的和为:\n%lld\n", total);
    return 0;
} 
