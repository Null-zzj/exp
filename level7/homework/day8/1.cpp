// 1 请用下面的抽象类实现曹操，诸葛亮和周瑜三个角色


#include <iostream>
#include <string>
using namespace std;

class Role
{
public:
	void virtual who() = 0; //说出我的角色是谁
    void virtual motto() = 0; //角色的座右铭或者说过的最有影响的话
	
	string m_name; //角色的姓名
    Role(string name) : m_name(name)
    {

    }
};

class TKRole : public Role
{
    string m_motto;

    
public:
    TKRole(string name, string motto) : Role(name), m_motto(motto){}
    ~TKRole(){}
    void virtual who() //说出我的角色是谁
    {
        cout << "我是" << m_name << endl;
    }
    void virtual motto()
    {
        cout << "我的座右铭是：" << m_motto << endl;
    }
    
};



int main(int argc, char *argv[])
{
    TKRole zhuge("诸葛亮", "运筹帷幄之中，决胜千里之外");
    zhuge.who();
    zhuge.motto();

    TKRole caocao("曹操", "天命在我，我必统御天下！");
    caocao.who();
    caocao.motto();

    TKRole zhouyu("周瑜", "借东风，破曹操！");
    zhouyu.who();
    zhouyu.motto();


    return 0;
}