/*===============================================
*   文件名称：judgeou.c
*   创 建 者：     
*   创建日期：2023年05月30日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int ou_sum = 0,ou_total = 0; 
    int ji_sum = 0,ji_total = 0;
    int num;
    while(scanf("%d", &num) && num){
        if(num == 0)
            break;
        if(!(num%2)){
           ou_sum++;
            ou_total+=num;
        }else{
            ji_sum++;
            ji_total+=num;
        }
    }
    
    printf("有%d个偶数 平均值为%f\n", ou_sum, (double)ou_total/ou_sum );
    printf("有%d个奇数 平均值为%f\n", ji_sum, (double)ji_total/ji_sum );


    return 0;
} 
