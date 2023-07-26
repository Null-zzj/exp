#include <iostream>
using namespace std;

class Boss;

class Worker
{
  public:
    Worker(string name) : name(name), workingDay(0), salary(0)
    {
    }
    void work();               //工人开始工作
    void setWorkingDay();      //设置这个工程做了多少天
    void infoBoss(Boss &boss); //告诉老板工程完成了
    void displaySalary();      //显示这个工人获得多少工资

  private:
    string name;
    int workingDay; //工作的天数
    double salary;  //工资
    friend class Boss;
};

class Boss
{
  public:
    Boss() : projectDone(false){}
    bool pay(Worker &); // 工资等于 workingDay*500

  private:
    bool projectDone; // ture 表示已经完工，需要给工人发工资了
    friend void Worker::infoBoss(Boss &);
};

// 场景：
// 工人工作20后，工期完成，工人通知老板，老板根据工人的工作天数给工人发工资，工人显示自己的工资

void Worker::infoBoss(Boss &boss)
{
    boss.projectDone = true;
}
void Worker::work() //工人开始工作
{
    cout << "工人开始工作" << endl;
}
void Worker::setWorkingDay() //设置这个工程做了多少天
{
    int i;
    cin >> i;
    cout << "工作了" << i << "天" << endl;
    workingDay = i;
}
void Worker::displaySalary()
{
    cout << "工人 " << name << "获得工资" << salary << endl;
} 

bool Boss::pay(Worker &work)
{
    if(work.workingDay < 20)
    {
        cout << "工人未完成工作" << endl;
        return false;
    }
    work.salary = work.workingDay * 500;
    return true;
}

int main(int argc, char *argv[])
{
    Worker xiaoming("小明");
    Boss boss;
    xiaoming.work();
    xiaoming.setWorkingDay();
    xiaoming.infoBoss(boss);
    
    if(!boss.pay(xiaoming))
    {
        return 0;
    }
    xiaoming.displaySalary();

    

    return 0;
}