#include<iostream>
using namespace std;

int Max1(int, int);
int Max1(int, int, int);
double Max1(double, double);
double Max1(double, double, double);


int main()
{
    int x1, x2;
    cout << "请输入两个整数：" << endl;
    cin >> x1 >> x2;
    cout << "最大值为：" << Max1(x1, x2) << endl;
}

int Max1(int a,int b)
{
    return a > b ? a : b;
}

int Max1(int a,int b,int c)
{
    int Max1 = a > b ? a : b;
    return Max1 > c ? Max1 : c;
}

double Max1(double a,double b)
{
    return a > b ? a : b;
}
double Max1(double a,double b,double c)
{
    int Max1 = a > b ? a : b;
    return Max1 > c ? Max1 : c;
}