#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

void sys_err(char *str)
{
    perror(str);
    exit(1);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("input err\n");
        exit(0);
    }

    FILE* fp = fopen(argv[1], "r");
    int i = 0;
    while(fgetc(fp) != EOF)
        i++;


    printf("文件%s有%d字节 ", argv[1], i);


     i = 0;
    char buf[BUFSIZ];
    // fseek(fp, 0, SEEK_SET);
    lseek(3, 0, SEEK_SET);
    while(fgets(buf, sizeof(buf), fp))
        i++;
    
    printf("有%d行\n", i);
    
    // while(1);
    
    // lseek(3, 0, SEEK_SET);
    fseek(fp, 0, SEEK_SET);
    read(3, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, strlen(buf));


    return 0;
}