/*===============================================
*   文件名称：shu.c
*   创 建 者：     
*   创建日期：2023年05月30日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    for(int i = 1; i <= 4; i++){
        for(int j = 4 - i;j > 0;j--)
            printf(" ");
        for(int k = 2 * i - 1; k > 0; k--)
            printf("*");
        printf("\n");
    }


    return 0;
} 
