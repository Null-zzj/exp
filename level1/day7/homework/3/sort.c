/*===============================================
*   文件名称：sort.c
*   创 建 者：     
*   创建日期：2023年05月30日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int a = 4, b = 1, c = 9;
    int tem;
    if(a > b){
        tem = a;
        a = b;
        b = tem;
    }


    if(b > c){
        tem = b;
        b = c;
        c = tem;
    }

    if(a > b){
        tem = a;
        a = b;
        b = tem;
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
} 
