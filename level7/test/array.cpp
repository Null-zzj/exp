#include <iostream>
#include <iterator>

class Array
{
public: 
    Array(int len);
    ~Array();
    int& set(int index);
    int getlen();
    void show();
private:
    int len;
    int *p;
};

Array::Array(int len)
{
    if(len > 0)
    {
        this->len = len;
        p = new int[len];
    }
}
Array::~Array()
{
    if(p != nullptr)
    {
        delete [] p;
        p = nullptr; 
    }
}
int Array::getlen()
{
    return len;
}

int& Array::set(int index)
{
    if(index < len) 
    {
        return p[index];
    }else
    {
        std::cout << "index is out of array" << std::endl;
        static int tmp;
        return tmp;
    }
}

void Array::show()
{
    if(p != nullptr)
    {
        for(int i = 0; i < len; i++)
        {
            std::cout << p[i] << std::endl;
        }
    }else
    {
        std::cout << "Array is  NULL" << std::endl; 
    }
    

}




int main()
{
    Array arr(100);

    for(int i = 0; i < arr.getlen(); i++)
    {
        arr.set(i) = i;
    }

    arr.show();


    return 0;
}