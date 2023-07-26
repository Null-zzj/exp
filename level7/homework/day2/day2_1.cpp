#include <iostream>
using namespace std;

#define MAX_NUM   10
int g_intArray[10];
int tmp;
int& setValue(int index)
{
    if(index < MAX_NUM)
        return g_intArray[index];
    else
        return tmp;
}

int main()
{
	for (int i = 0; i < MAX_NUM; i++)
	{
	    g_intArray[i] = i + 1;
	}
	
	setValue(3) = 100;    //将g_intArray[3]设置为100，请实现函数setValue(int i),需要数组越界保护
	setValue(8) = 200;
	setValue(20) = 300;
	
	for (int i = 0; i < MAX_NUM; i++)
	{
		cout << g_intArray[i] << ",";
	}
	cout << endl;
}