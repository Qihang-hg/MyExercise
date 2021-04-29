#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class Employee
{
public:
    Employee(const char*a,const char*b,const char*c,const char*d)
    {
        strcpy_s(m_Name, a);
        strcpy_s(m_Address, b);
        strcpy_s(City, c);
        strcpy_s(Zip, d);
    }
    ~Employee(){}

    void display();

    void change_Name(const char *a)
    {
       strcpy_s(m_Name, a); 
    }

private:
    char m_Name[10];
    char m_Address[12];
    char City[8];
    char Zip[6];
};

void Employee::display()
{
    cout << "name:" << m_Name << endl;
    cout << "stree:" << m_Address << endl;
    cout << "city:" << City << endl;
    cout << "zip:" << Zip << endl;

}
