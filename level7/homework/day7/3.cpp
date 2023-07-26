#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

// 组合的方式
class Person;

class PersonalFlyer //个人飞行器
{
  public:
    void fly(Person &person);
};

class Person
{
    PersonalFlyer flyer;
    friend PersonalFlyer;

  public:
    string name;
    Person(string name) : name(name)
    {
    }
    void fly();
};

void Person::fly()
{
    flyer.fly(*this);
}

void PersonalFlyer::fly(Person &person)
{
    cout << person.name << " say: i can fly" << endl;
}

int main(int argc, char *argv[])
{
    Person p("小明");
    p.fly();
    return 0;
}