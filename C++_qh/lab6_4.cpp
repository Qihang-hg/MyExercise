/*
使用string类声明字符串对象，编程实现两个字符串的连接。
在string类中已重载了运算符“+=”实现字符串的连接，可以使用这个功能。
*/

#include<string>
#include<iostream>
using namespace std;

int main()
{
    string str1, str2;
    cout << "Input str1" << endl;
    cin >> str1;
    cout << "Input str2" << endl;
    cin >> str2;
    str1 += str2;
    cout << "str1 + str2 =" << str1;
    return 0;
}