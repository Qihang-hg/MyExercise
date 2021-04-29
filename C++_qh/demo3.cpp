#include<iostream>
#include<string>
using namespace std;

//华氏温度转换为摄氏温度
int main()
{
    int F = 0, C=0;
    cout << "请输入华氏温度：";
    cin >> F;
    C = (F - 32) * 5 / 9;
    cout << "摄氏温度为:" << C << endl;
}