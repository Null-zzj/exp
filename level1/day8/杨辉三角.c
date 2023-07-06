#include <stdio.h>
int main()
{
    int arr[11][11] = {0};

    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1 || j == i){
                arr[i][j] = 1;
                printf("%d ", arr[i][j]);
            }else{
              arr[i][j] = arr[i-1][j-1] + arr[i - 1][j];
              printf("%d ", arr[i][j]);
            }
        }
      printf("\n");

  }


}
