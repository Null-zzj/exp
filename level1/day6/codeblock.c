/*===============================================
*   文件名称：codeblock.c
*   创 建 者：     
*   创建日期：2023年05月29日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int i = 2;
    printf("%d\n", i);
    {
        int i = 3;
        printf("%d\n", i);
    }
    printf("%d\n", i);

    return 0;
} 
