/*===============================================
*   文件名称：goto.c
*   创 建 者：     
*   创建日期：2023年05月29日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int a = 50;
tothis:
    printf("%d\n",a);
    if(a--){
    goto tothis;
    }

    return 0;
} 
