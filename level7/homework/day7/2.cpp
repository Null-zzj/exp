// 2 分别用继承和组合的方式让人能飞行


#include <iostream>
using namespace std;

// 继承的方式：
class Bird  //鸟拥有飞翔的功能
{
public:
	void fly()
    {
        cout << "i can fly!" << endl;
    }
};

class Person : public Bird
{
public:
	string name;
    
};




int main(int argc, char *argv[])
{
    Person p;
    p.fly();
    return 0;
}
