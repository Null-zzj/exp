#include <stdio.h>

int main()
{
    int num;
    printf("请输入一个整数：\n");
    scanf("%d", &num);
    
    int i = 32;
    int j;
    while (i--) {
      j = 1;
      j <<= i;

      if(j & num){
        printf("1");
      }else{
        printf("0");
      }
    }


  printf("\n");

  
     



}
