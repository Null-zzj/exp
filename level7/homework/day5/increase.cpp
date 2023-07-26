#include <iostream>
using namespace std;

template <typename T> T increase(T& a)
{
    a += 10;
    return a;
}

class Point
{
  private:
    int x;
    int y;

  public:
    Point(double x = 0, double y = 0) : x(x), y(y)
    {
    }
    Point operator+=(int num)
    {
        this->x += 10;
        this->y += 10;
        return *this;
    }
    
    friend ostream &operator<<(ostream&, const Point&);
};

ostream& operator<<(ostream& out, const Point& p)
{
    out << "x= " << p.x << ", y= " << p.y;
    return out;
}

int main()
{
    int a = 100;
    cout << a << endl;
    cout << increase(a) << endl;
cout << a << endl;
    Point p1(1.1, 1.2);
    cout << p1 << endl;           // 1.1---1.2
    cout << increase(p1) << endl; // 11.1---12.2
}
