#include<iostream>
#include<string>
using namespace std;

float Convert(float);
int main()
{
    int C, F;
    cout << "输入F：" << endl;
    cin >> F;
    C = Convert(F);
    cout << "C:" << C << endl;
    return 0;
}

float Convert(float n)
{
    return (n - 32) * 5 / 9;
}
