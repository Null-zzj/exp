#include <iostream>

class Person{
    public:
        int age;
        int high;
        void set()
        {
            heavy = 10;
        }

    private:
        int heavy;

};

class Student : public Person
{
    public:
        int id;
    private:
        int socre;
};

class Goodstudent : public Student
{
    public:
        int money;
    
};

int main()
{
    Person person;
    person.set();

    int *p = (int*)&person;
    printf("%d", *(p+2));

    // Student stu;

    // Goodstudent gstu;

    // printf("sizeof(Person): %lu\nsizeof(Student): %lu\nsizeof(Goodstudent): %lu\n", sizeof(person), sizeof(stu), sizeof(gstu));



    return 0;
}