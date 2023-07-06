#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int num,count = 0;
    int arr[32] = {0};
    printf("请输入一个整数，将会以二进制输出\n");
    scanf("%d", &num);
    while(num != 0){
        arr[count] = num & 1;
        num>>=1;
        count++;
    }

    for(int i = count - 1;i >= 0; i--){
      printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
} 
