#include <stdio.h>

int* sort(int *arr, int len);

int main()
{
    int arr[10] = {0};
    printf("请输入10个整数\n");
    for(int i = 0; i < 10; i++)
      scanf("%d", &arr[i]);

    sort(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i = 0; i < 10; i++)
      printf("%d ", arr[i]);
    
    printf("\n");
  


}
int* sort(int *arr, int len){
    for(int i = 0; i < len; i++){
        for(int j = 1; j < len - i; j++){
            int tem = 0;
              if(arr[j] < arr[j - 1]){
                  tem = arr[j];
                  arr[j] = arr[j - 1];
                  arr[j - 1] = tem;
              }
        }
    }
 

}
