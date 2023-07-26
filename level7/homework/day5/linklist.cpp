#include <iostream>
using namespace std;

template <typename T> class Link
{
    struct Node
    {
        T data;
        Node *next;
    };

    Node *head;

  public:
    Link() : head(nullptr)
    {
        head = new Node;
        head->data = 0;
        head->next = nullptr;
    }
    void insert(T a); //新插入的输入放在头节点
    void remove();    //删除数据,删除头节点的数据，让下一个数据变成头节点
    void show();      //显示链表里所有的数据
};

template <typename T> void Link<T>::insert(T a)
{
    Node *node = new Node;
    if(node != nullptr)
    {
        node->data = a;
        node->next = head->next;
        head->next = node;
    }
    
}

template <typename T> void Link<T>::remove()
{
    if(this->head == nullptr)
    {
        cout << "the linklist is empty!" << endl;
        return ;
    }

    Node *p = head->next;
    head->next = p->next;
    delete p;
}

template <typename T> void Link<T>::show()
{
    if(this->head == nullptr)
    {
        cout << "the linklist is empty!" << endl;
        return ;
    }
    Node *p = head->next;
    while(p)
    {
        cout << p->data << " | ";
        p = p->next;
    }
    cout << endl;

}

class Point
{
  private:
    int x;
    int y;

  public:
    Point(double x = 0, double y = 0) : x(x), y(y)
    {
    }
    
    friend ostream &operator<<(ostream&, const Point&);
};

ostream& operator<<(ostream& out, const Point& p)
{
    out << "x= " << p.x << ", y= " << p.y;
    return out;
}


int main(int argc, char *argv[])
{
    Link<int> intList;
    for(int i = 0 ; i < 20; i ++)
        intList.insert(i + 10);

    intList.show();
    
    for(int i = 0; i < 5; i++)
        intList.remove();

    intList.show();


    Link<Point> PList;
    for(int i = 0; i < 20; i++)
    {
        PList.insert(Point(i + 6, i + 18));
    }
    PList.show();
    return 0;
}