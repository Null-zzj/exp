#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("input err\n");
        exit(-1);
    }

    FILE* fp1 = fopen(argv[1], "r");
    FILE* fp2 = fopen(argv[2], "w");
    char buf[1024];
    while(!feof(fp1))
    {
        fgets(buf, sizeof(buf), fp1);
        fputs(buf, fp2);
    }

    return 0;
}