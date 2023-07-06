/*===============================================
*   文件名称：test.c
*   创 建 者：     
*   创建日期：2023年06月07日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int arr[] = {1,2,3,4,5,6};
    int *p =arr;

    printf("%d\n",*(++p));
    printf("%p\n", p);
    printf("%d\n", *++p);
    printf("%p\n", p);
    printf("%d\n", ++*p);
    printf("%p\n", p);
    for(int i = 0; i < 6; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
} 
