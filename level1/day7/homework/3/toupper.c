/*===============================================
*   文件名称：toupper.c
*   创 建 者：     
*   创建日期：2023年05月30日
*   描    述：
================================================*/
#include <stdio.h>


char _toupper(char i);

int main(int argc, char *argv[])
{ 
    char ch;
    printf("请输入一个字母\n");
    while(scanf("%c", &ch)){
        printf("%c\n",_toupper(ch));

    }

    return 0;
} 

char _toupper(char i)
{
    if(i > 'A' && i < 'Z' )
        return i;
    if(i > 'a' && i < 'z')
        return i - 32;
    return 0;
    


}



