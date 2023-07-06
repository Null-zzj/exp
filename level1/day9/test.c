#include <stdio.h>
#include <malloc.h>
int main(void)
{
  int arr[4] = {2};

  printf("%d\n", arr[4]);

  arr[4] = 5;
  printf("%d\n", arr[4]);


  int *p = (int*)malloc(sizeof(int)*4);
  printf("%d", p[4]);
  p[50000] = 5;
  printf("%d\n", p[100]);

  

  return 0;
}
