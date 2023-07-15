#include <stdio.h>

int main()
{
    int x = 1;
    if (*(char *)&x == 1)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
}
