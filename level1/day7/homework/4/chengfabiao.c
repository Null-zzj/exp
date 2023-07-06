/*===============================================
*   文件名称：chengfabiao.c
*   创 建 者：     
*   创建日期：2023年05月30日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= i; j++)
            printf("%d*%d=%d ", i, j, i*j);
       printf("\n");
    }


    return 0;
} 
