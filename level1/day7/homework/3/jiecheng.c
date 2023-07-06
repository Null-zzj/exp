/*===============================================
*   文件名称：jiecheng.c
*   创 建 者：     
*   创建日期：2023年05月30日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int n;
    scanf("%d", &n);
    int sum = 1;
    for(int i = n; i > 0; i--)
        sum *= i;

    printf("%d\n", sum);
    return 0;
} 
