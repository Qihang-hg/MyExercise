#include<math.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int x, y;
    cout << "请输入x，y：" << endl;
    cin >> x >> y;
    int ret = pow(x, y);
    cout << "x^y="<< ret << endl;
}