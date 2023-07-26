// 1，实现基类Vehicle和派生类Car(小汽车）

#include <iostream>
using namespace std;

class Vehicle //声明汽车类
{
  protected:
    int wheel;     //车轮个数
    double weight; //车重 吨
  public:
    Vehicle(int wheel, double weight) : wheel(wheel), weight(weight) //构造函数
    {
    }
    void show()
    { //输出函数
        cout << "车轮个数: " << wheel << ", 车重量: " << weight << endl;
    }
};

class Car : public Vehicle
{
  private:
    int passager_load;   //载人数
    double fuel_consume; //油耗，升
  public:
    Car(int wheel, double weight, int num, double consume) : Vehicle(wheel, weight), passager_load(num), fuel_consume(consume) //构造函数
    {
    }
    void show() //显示出所有的信息
    {
        Vehicle::show();
        cout << "载人数: " << passager_load << ", 油耗: " << fuel_consume << endl;
    }
};

int main(int argc, char *argv[])
{
    Car car(6, 999.9, 60, 3);
    car.show();
    return 0;
}