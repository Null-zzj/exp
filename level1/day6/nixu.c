/*===============================================
*   文件名称：nixu.c
*   创 建 者：     
*   创建日期：2023年05月29日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int num;
    printf("请输入一个小于5位的整数:\n");
    scanf("%d", &num);
    while(num){
        printf("%d",num%10);
        num/=10;

    }
    printf("\n");
    return 0;
} 
