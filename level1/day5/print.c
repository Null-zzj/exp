/*===============================================
*   文件名称：print.c
*   创 建 者：     
*   创建日期：2023年05月26日
*   描    述：
================================================*/
#include <stdio.h>
#include <unistd.h>
void func1()
{
    int a = 1234;
    float f = 123.456;
    char ch = 'a';
    printf("%ld,%2d\n",(long)a,a);
    printf("%f,%16f,%16.1f,%.2f\n",f,f,f,f);
}

void func2()
{
  
    char *str = "hello word";
    printf("%.5s\n", str);
}
void func3()
{
    printf("please input a chat: \n");
    char ch = getchar();
    char ch2 = getchar();
    printf("%c\n", ch);
    printf("%d\n", ch2);
}
void func4()
{
    char c1,c2,c3;
    scanf("%caaa%cbbb%c",&c1,&c2,&c3);
    printf("%c %c %c",c1,c2,c3);
}
void func5()
{
    int a,b,c;
    printf("input a b c\n");
    scanf("%d%d%d", &a,&b,&c);
}
void func6()
{
    char buf[1024] = {'\0'};
    int len = read(0, buf,sizeof(buf));
    printf("%s", buf);
    printf("%d\n",buf[len-1]);
}
int main(int argc, char *argv[])
{
    func6();
    return 0;
} 
