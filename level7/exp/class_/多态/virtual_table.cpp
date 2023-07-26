#include <iostream>
using namespace std;
class A
{
  public:
    virtual void func1()
    {
        cout << "class a" << endl;
    }
};
class B : public A
{
  public:
    void func1()
    {
        cout << "class b" << endl;
    }
};

// int main(int argc, char *argv[])
// {
//     A a;
//     cout << "sizeof(A) " << sizeof(A) << endl;

//     cout << "sizeof(B) " << sizeof(B) << endl;

//     // A a(10);
//     // B b(20);
//     // int *p1 = (int*)&a;
//     // void(*p2)() = (void(*)())*p1;
//     // p2();
//     typedef void (*Fun)(void);

//     B b;

//     Fun pFun = NULL;

//     cout << "虚函数表地址：" << (int *)(&b) << endl;
//     cout << "虚函数表 — 第一个函数地址：" << (int *)*(int *)(&b) << endl;

//     // Invoke the first virtual function
//     pFun = (Fun) * ((int *)*(int *)(&b));
//     pFun();

//     return 0;
// }
int main(int argc, char *argv[])
{
    B b;

    // 获取虚函数表的基地址
    int *vtable_ptr = (int *)&b;

    // 获取第一个虚函数的地址
    void (*pFun)() = (void (*)()) *vtable_ptr;

    // 调用虚函数
    pFun();

    return 0;
}