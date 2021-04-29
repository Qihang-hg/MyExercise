#include<iostream>
#include<string>
using namespace std;

class BaseClass
{
public:
    int Number;

    BaseClass()
    {
        cout << "基类构造函数执行" << endl;
    }
    ~BaseClass()
    {
        cout << "基类析构函数执行" << endl;
    }

};

class DerivedClass:public BaseClass
{
public:
    DerivedClass()
    {
        cout << "派生类构造函数执行" << endl;
    }
    ~ DerivedClass()
    {
        cout << "派生类析构函数执行" << endl;
    }
};

int main()
{
    //BaseClass b;

    DerivedClass d;

    return 0;
}


// class BaseClass
// {
// public:
// 	BaseClass(){cout<<"构造了BaseClass类的对象"<<endl;} 
// 	 ~ BaseClass(){cout<<"析构了BaseClass类的对象"<<endl;}
// };
// class DerivedClass:public BaseClass
// {
// public:
// 	 DerivedClass(){cout<<"构造了DerivedClass类的对象"<<endl;} 
// 	 ~ DerivedClass(){cout<<"析构了DerivedClass的对象"<<endl;}
// };
// int main()
// {
// 	 DerivedClass d;
// 	 return 0;
// }
