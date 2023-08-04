#include <iostream>
#include <memory>
using namespace std;

class B;

class A
{
public:
    A() 
    {
        cout << "A::A()" << endl;
    }
    ~A()
    {
        cout << "A::~A()" << endl;
    }

    void show()
    {
        cout << "A::show()" << endl;
    }

    shared_ptr<B> p;
    
};

class B
{
    
public:
    B()
    {
        cout << "B::B()" << endl;
    }
    ~B()
    {
        cout << "B::~B()" << endl;
    }
    void show()
    {
        cout << "B::show()" << endl;
    }

    shared_ptr<A> p;
    
};

void func1()
{
    shared_ptr<A> pA = make_shared<A>();
    shared_ptr<B> pB = make_shared<B>();
    pA->p = pB;
    pB->p = pA;

}


int main(int argc, char *argv[])
{
    


    return 0;
}
