#include <stdio.h>

int main()
{
    int arr[][3] = {1,2,3,4,5,6,7,8,9};

    int **p = arr[1];

    printf("%d", p[1]);



}
