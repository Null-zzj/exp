#include <iostream>
using namespace std;

class Point
{
public:
	Point();
	Point(float a, float b);
	void show(); //打印x,y的坐标
    ~Point();


private:
	float x;
	float y;
};

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(float a, float b)
{
    x = a;
    y = b;
}

Point::~Point()
{
    x = 0;
    y = 0;
}

void Point::show()
{
    cout << "x: " << x << "\ny: " << y << endl;
}

int main()
{
    Point p(5, 6);
    Point q;

    p.show();
    q.show();




    return 0;
}