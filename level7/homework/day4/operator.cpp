#include <iostream>
using namespace std;

void debug()
{
    cout << "--------------------" << endl;
}

class Complex
{
double real;
double imag;
friend Complex operator/=(Complex&, Complex&);
friend Complex operator++(Complex&);
friend Complex operator++(Complex&, int);
friend Complex operator,(Complex&, Complex&);

public:
	Complex(double real, double imag) : real(real), imag(imag){}//构造函数，使用初始化列表
	void show() //显示函数
    {
        cout << "real " << real << ", imag" << imag << endl;
    }
};

// 使用友元运算符重载重载/= （两个对象的实部和实部相除，虚部和虚部相除，结果放到前者的实部和虚部）
// 使用友元运算符重载重载＋＋ （前向＋＋和后向＋＋）
// 使用友元运算符重载重载， （双目运算符，交换２个对象的数据，实部和实部交换，虚部和虚部交换）

Complex operator/=(Complex& a, Complex& b)
{
    a.real /= b.real;
    a.imag /= b.imag;

    return a;
}

Complex operator++(Complex& a)
{
    a.imag++;
    a.real++;
    return a;
}

Complex operator++(Complex& a, int b)
{
    Complex tmp(a);
    a.imag++;
    a.real++;
    return tmp;
}

Complex operator,(Complex& a, Complex& b)
{
    Complex tmp(a);
    a = b;
    b = tmp;
    return b;
}






int main(int argc, char *argv[])
{
    Complex a(5, 6);
    Complex b(7, 8);

    Complex c(a/=b);
    cout << "c: ";
    c.show();
    
    debug();

    a++;
    cout << "a: ";
    a.show();

    debug();

    ++b;
    cout << "b: ";
    b.show();

    debug();

    a,b;
    cout << "a: ";
    a.show();
    cout << "b: ";
    b.show();




    return 0;
}