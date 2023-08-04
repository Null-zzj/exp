#include <iostream>
#include <list>

int main()
{
    std::list<int> lInt;


    for(int i = 0; i < 100; i++)
    {
        if(i % 2)
        {
            lInt.push_front(i);
        }else{
            lInt.push_back(i);
        }
    }

    for(int item : lInt)
    {
        std::cout << "|" << item;
    }
    std::cout << std::endl;
    lInt.erase(lInt.begin());
    lInt.sort();

    for(int item : lInt)
    {
        std::cout << "|" << item;
    }
    std::cout << std::endl;

}
