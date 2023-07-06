/*===============================================
*   文件名称：if-else.c
*   创 建 者：     
*   创建日期：2023年05月29日
*   描    述：
================================================*/
#include <stdio.h>

void func1(int);


int main(int argc, char *argv[])
{ 
    int a;
    printf("input a:\n");
    scanf("%d", &a);
    func1(a);
    return 0;
}

void func1(int a)
{
    if(a > 60)
        printf("pass\n");
    else
        printf("no pass\n");

}
