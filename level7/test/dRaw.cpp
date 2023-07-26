/*********************************************
* @FileName: dRaw.cpp
* @Author: Null-zzj
* @Mail: zj.zhu.cn@gmail.com
* @Created Time: Wed Jul 19 10:26:50 2023
*********************************************/

#include<iostream>
using namespace std;

string cardNum = "230719";
string cardPasswd = "11223344";


int main(int argc, char *argv[])
{
    string inputNum;
    cout << "请输入你的卡号: " << endl;
    cin >> inputNum;

    if(inputNum != cardNum)
    {
        cout << "账户不存在" << endl;
        return -1;
    }

    int count  = 0;
    string inputPasswd;
    while(count++ < 3)
    {
        cout << "请输入你的密码: " << endl;
        cin >> inputPasswd;
        if(inputPasswd != cardPasswd)
        {
            cout << "密码错误" << endl;
            if(count == 3)
            {
                cout << "你的银行卡被锁了" << endl;
            }else{
                cout << "你还有" << (3 - count) << "次机会" << endl;
            }
        }else
        {
            cout << "欢迎登录" << endl;
            break;
        }
    }




	return 0;
}
