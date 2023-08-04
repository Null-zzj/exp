#include <algorithm>
#include <iostream>
#include <memory>


void debug(int id)
{
    std::cout << id << "--------------" << std::endl;
}
class Array
{
    protected:
        int len;
        int* p;

    public:
        Array(int len) : len(len), p(nullptr)
        {
            std::cout << "Array::Array(int)" << std::endl;
            if(len > 0)
            {
                p = new int[len];
                for(int i = 0; i < len; i++)
                {
                    p[i] = -1;
                }
            }
        } 
        ~Array()
        {
            if(p != nullptr)
            {
                delete [] p;
                p = nullptr;
            }
            std::cout << "Array::~Array()" << std::endl;
        }

        void show()
        {
            for(int i = 0; i < len; i++)
            {   
                std::cout << "|" << p[i];
            }
            std::cout << std::endl;
        }
        int& operator[](int index)
        {
            if(index < len)
            {
                return p[index];
            }
            else{
                throw std::out_of_range("Index is out of range.");
            }
        }

        int getLen()
        {
            return len;
        }
};

void func1()
{
    // 定义了一个共享的智能指针，它指向一个Array的一个对象的地址
    std::shared_ptr<Array> p(new Array(100));
    std::shared_ptr<Array> p1 = std::make_shared<Array>(100);

    debug(1);
    // 重载 ->，来访问Array的成员
    p->show();
    // 重载 * 
    (*p).show();

    // get可以获得原始类型的指针
    Array *pA = p.get();
    pA->show();

    debug(2);
    for(int i = 0; i < p->getLen(); i++)
    {
        (*(p.get()))[i] = i + 500;
    }
    p->show();

    debug(3);
    std::shared_ptr<Array> p2 = p;
    std::cout << "refer: " << p.use_count() << std::endl;
    std::cout << "refer: " << p2.use_count() << std::endl;


    std::shared_ptr<Array> p3 = p;
    std::cout << "refer: " << p2.use_count() << std::endl;
    std::cout << "refer: " << p3.use_count() << std::endl;

    // p3 不再拥有内存的共享
    p3.reset();
    std::cout << "refer: " << p.use_count() << std::endl;
    std::cout << "refer: " << p2.use_count() << std::endl;
    std::cout << "refer: " << p3.use_count() << std::endl;

    debug(4);
    std::cout << "p3: " << p3 << std::endl;

}


int main(int argc, char *argv[])
{
    func1();
    return 0;
}




















