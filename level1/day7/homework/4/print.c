/*===============================================
*   文件名称：print.c
*   创 建 者：     
*   创建日期：2023年05月30日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int n = 5;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            printf("*");
        }
      printf("\n");
    }
    return 0;
} 
