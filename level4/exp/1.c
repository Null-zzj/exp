#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    char ch[4] = { '3', 0};
    char buf[1024];

    FILE* fp = fopen("1.txt", "r+");
    
    int len  = fread(buf, 1, sizeof(buf), fp);
   
    for(int i = 0; i <= len; i++)
    {
        printf("%d\n", buf[i]);
    }
   

    int i; 
    for(i = 0; i <= len; i+=2)
    {
        if(buf[i] > ch[0])
            break;
    }
    
    for(int j = len; j >= i; j --)
    {
       buf[j+2] = buf[j];
       

    }

    for(int i = 0; i <= strlen(buf); i++)
    {
        printf("%d\n", buf[i]);
    }
    

    buf[i] = '3';
    buf[i+1] = '\n';
    buf[strlen(buf)] = 0;
    fseek(fp, 0, SEEK_SET);

    fwrite(buf, 1, strlen(buf), fp);








    return 0;
}
