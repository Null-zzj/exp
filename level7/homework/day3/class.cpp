/*********************************************
* @FileName: class.cpp
* @Author: Null-zzj
* @Mail: zj.zhu.cn@gmail.com
* @CreatedTime: 周四 7月 20 18:34:56 2023
* @Descript:
*/

#include <iostream>
using namespace std;

class Rectange
{
    public:
        Rectange(double length, double width) : length(length), width(width)
        {
        }

        double circumference() //计算周长
        {
            return length * 2 + width * 2;
        }
	    double area()     //计算面积
        {
            return length * width;
        }
	    void show()     //将计算结果打印出来
        {
            cout << "周长: " << circumference() << endl;
            cout << "面积: " << area() << endl;
        }
    private:
        double length;
        double width;
};

int main(int argc, char *argv[])
{
    Rectange rec(12, 11);
    rec.show();

    return 0;
}