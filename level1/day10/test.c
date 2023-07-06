#include <stdio.h>
#include <stdlib.h>

void func1(char *str){
    printf("%lu\n", sizeof(str));

}

void func2(char str[]){
    printf("%lu\n", sizeof(str));
}

void func3(const char str[])
{
    printf("%p %p\n", str, ++str);
//    str[1] = '\2';
    //
    printf("%s", str);
}

void func4(const char const str[])
{
    str++;
    printf("%p %p\n", str, str++);
    
    printf("%s", str);

}


void func5(const char *const str)
{
    str++;
    printf("%p %p\n", str, str++);
    
    printf("%s", str);


int main(int argc, char *argv[])
{   
    char str[] = "hellow";
    func4(str);

    


    
    return EXIT_SUCCESS;
}
