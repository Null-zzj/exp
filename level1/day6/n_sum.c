/*===============================================
*   文件名称：n_sum.c
*   创 建 者：     
*   创建日期：2023年05月29日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    double i = 2, j = 1;
    double total = 0;
    int tem;
    for(int k = 0; k < 100; k++){
        total+= i/j;
        tem = i;
        i = i + j;
        j = tem;
    }
    printf("2/1+3/2+5/3+8/5+13/8+....前100项之和为：\n%lf\n", total);

    return 0;
} 
