#include <iostream>
#include <vector>
void debug(int id)
{
    std::cout << id << "---------------" << std::endl;
}

void print(int id, std::vector<int> v)
{
    for(int item : v)
    {
        std::cout << "|" << item;
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> vInt;
    std::cout << "vInt size: " << vInt.size() << std::endl;
    std::cout << "capacity: " << vInt.capacity() << std::endl;
    


    for(int i = 0; i < 10; i++)
    {
        vInt.push_back(i);
    }
    debug(1);
    std::cout << "vInt size: " << vInt.size() << std::endl;
    std::cout << "capacity: " << vInt.capacity() << std::endl;

    debug(2);
    // 第一种遍历动态数组的方法
    for(int i = 0; i < vInt.size(); i++)
    {
        std::cout << "|" << vInt[i];
    }
    
    std::cout << std::endl;
   
    for(int i = 10; i < 100; i++)
    {
        vInt.push_back(i);
    }

    std::cout << "vInt size: " << vInt.size() << std::endl;
    std::cout << "capacity: " << vInt.capacity() << std::endl;

    debug(3);
    // 第二种遍历方法
    for(int i = 0; i < vInt.size(); i++)
    {
        std::cout << "|" <<  vInt.at(i);
    }
    std::cout << std::endl;
    
    debug(4);
    for(int i = 100; i < 200; i++)
    {
        vInt.push_back(i);
    }
    std::cout << "vInt size: " << vInt.size() << std::endl;
    std::cout << "capacity: " << vInt.capacity() << std::endl;

    debug(5);
    // 第三种方法 for循环
    print(0, vInt);
    std::cout << "vInt size: " << vInt.size() << std::endl;
    std::cout << "capacity: " << vInt.capacity() << std::endl;

    debug(6);
    // 第4种方法， 迭代器
    std::vector<int>::iterator it;
    for(it = vInt.begin(); it != vInt.end(); it++)
    {
        std::cout << "|" << *it;
    }
    debug(7); 
    // 第五种 使用反向迭代器
    for(auto rit = vInt.rbegin(); rit != vInt.rend(); rit++)
    {
        std::cout << "|" << *rit;
    }
    std::cout << std::endl;

    debug(7);

    return 0;
}
