/*===============================================
*   文件名称：test2.c
*   创 建 者：     
*   创建日期：2023年06月07日
*   描    述：
================================================*/
#include <stdio.h>

void func()
{
    static int a = 0;

    a++;
    printf("%d", a);

}

int main(int argc, char *argv[])
{ 
    
    for(int i = 0; i < 5; i++)
        func();


    return 0;
} 
