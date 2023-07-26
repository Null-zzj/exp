#include <ios>
#include <iostream>
using namespace std;


class Person
{
    int a;
public:
    Person(int a = 0) : a(a)
    {
        cout << "Person::Person(int) --- " << this << endl;
    }
    ~Person()
    {
        cout << "Person::~Person() --- " << this << endl;
    }

    int getA()
    {
        return a;
    }
     
    
};
int main(int argc, char *argv[])
{
    Person p;
   
    cout << p.getA() << endl;

    p = 30;

    cout << p.getA() << endl;

    return 0;
}
