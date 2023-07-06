#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    FILE* fp = fopen("./1.txt", "a+");
    
    FILE* fp2 = freopen("1.txt", "w", stdout);

    write(1, "321", 3);
    return 0;
}