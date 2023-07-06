#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buf[1024];
    int i = 0;
    while(i < BUFSIZ)
    {

        printf("%c", 'a');
        i++;
        
    }

    sleep(2);
    puts("");
    printf("%d\n", i);



}