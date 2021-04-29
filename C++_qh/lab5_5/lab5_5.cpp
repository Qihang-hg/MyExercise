/*
在employee.h文件中声明Employee类。
Employee类具有姓名、街道地址、城市和邮编等私有数据成员，
都可以用字符型数组来表示，
在成员函数中，构造函数用来初始化所有成员数组，
对字符数组的赋值可以使用字符串拷贝函数strcpy(char*,char *name);
display()中使用cout显示姓名、街道地址、城市和邮编等属性，
change_name()改变类中表示姓名属性的字符数组类型的数据成员。
在主程序中声明这个类的对象并对其进行操作。
*/
#include<iostream>
#include"employee.h"
#include<cstring>
using namespace std;
int main()
{
    Employee a1("yqh", "guiyanghuaguoyuan", "guizhou", "14834");
    a1.display();
    cout << endl;
    a1.change_Name((char*)"qh");
    a1.display();
    cout << endl;
    return 0;
}