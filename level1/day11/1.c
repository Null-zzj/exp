#include <stdio.h>

void func1(int (*p)[3])
{

    for (int i = 0;i < 5;i ++) 
    {
        for (int j = 0; j < 3; j++) {
            printf("%d\n", p[i][j]);
        }
    } 
}

void func2()
{
    int arr[5];



}


int main()
{
    func2();
	while(1);
}
