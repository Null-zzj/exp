// 2 请用下面的抽象类实现一个长方体

#include <iostream>
using namespace std;

//立体形状
class Cube
{
  public:
    virtual float area() = 0;   //面积
    virtual float volume() = 0; //体积
};

//长方体
class Cuboid : public Cube
{
  public:
    Cuboid(float len, float width, float height) : m_height(height), m_width(width), m_length(len)
    {
    }
    float area() //面积
    {
        return m_height * m_length * 2 + m_width * m_height * 2 + m_length * m_width;
    }
    float volume() //体积
    {
        return m_height * m_length * m_width;
    }
    void show() //显示面积和体积
    {
        cout << "面积：" << area() << ", 体积：" << volume() << endl;
    }

    float m_width;
    float m_height;
    float m_length;
};

int main(int argc, char *argv[])
{
    Cuboid cub(12, 16, 17);
    cub.show();

    return 0;
}
