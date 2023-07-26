#include <cmath>
#include <iostream>
#include <math.h>
using namespace std;

class Line;

class Point
{
    double x;
    double y;

    friend Line;

  public:
    Point(double x = 0, double y = 0) : x(x), y(y)
    {
    } //构造函数，使用初始化列表
};

class Line
{
    Point p1;
    Point p2;
    double len;
  public:
    Line(Point p1, Point p2) : p1(p1), p2(p2)
    {
    } //构造函数，使用初始化列表

    double length()   //求这个线段的长度，
    {
        return sqrt(abs(p1.x - p2.x) * abs(p1.x - p2.x) + abs(p1.y - p2.y) * abs(p1.y - p2.y));
    }
    
    void showLength() //显示线段的长度
    {
        cout << "length is " << length() << endl;
    }
};

int main(int argc, char *argv[])
{
    Point p1(5.5, 6.6);
    Point p2(3.3, 9.4);
    Line l(p1, p2);

    l.showLength();

    return 0;
}