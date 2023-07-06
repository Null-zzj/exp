/*===============================================
*   文件名称：b.c
*   创 建 者：     
*   创建日期：2023年05月25日
*   描    述：
================================================*/
#include <stdio.h>

void func1()
{
    int a = 0xaaaaaaaa;
    printf("a HEX = %#x, ~a HEX = %#x\n", a, ~a);
}
void func2()
{
    int b = 0xa5a5;
    int c = b;
    while(c != 0){
        printf("%d", c & 1);
        c >>= 1;
    }  // 输出的为二进制倒序
    printf("\n%#x\n",b);
}

void func3()
{
    unsigned char a = 3;
    char b = 5;
    char r = 3 & 5;
    printf("r HEX = %#x\n", r);
}

void func4()
{
    char a = 3;   //       0000 0011
    short b = 317; // 0001 0011 1101
    char r = a & b;
    printf("r HEX = %#x\n",r);
}

void func5()
{
    char a = 3;  //         0000 0011
    short b = 317;  // 0001 0011 1101
    short r = a | b; 
    printf("r HEX = %#x\n",r);
}

void func6() // 异或  不同的为1
{ 
    char a = 3;  //         0000 0011
    short b = 317;  // 0001 0011 1101
    short r = a ^ b; 
    printf("r HEX = %#x\n",r);
}
void func7()
{
    char a = -5;
    printf("a = %#x\n", a);
    a >>= 1;
    printf("a = %#x\n", a);
    
}
void func8()
{
    unsigned int a = -53;
    printf("a = %#X\n", a);
     a >>= 3;

    printf("a >> 3 = %#X\n", a);
    unsigned int b = -53;
    printf("unsigned int b = %#X\n",b);
    printf("(int)b>>3 = %#X\n", (int)b >> 3) ;   
}
int main(int argc, char *argv[])
{ 
    func8();
    return 0;
} 
