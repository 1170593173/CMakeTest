#include <iostream>

using namespace std;

class student
{
private:
    string stu_name;
    int stu_age;
public:
    student(int m_age ,string m_name):stu_name(m_name),stu_age(m_age){};
    student():stu_name("m_name"),stu_age(12){};
    ~student();
    string getname();
    int getage();
};