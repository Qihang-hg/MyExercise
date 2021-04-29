#include<iostream>
#include<string>
using namespace std;

int fbn(int);
int main()
{
    int n;
    cout << "输入一个数n：" << endl;
    cin >> n;
    cout << fbn(n) << endl;

    return 0;
}

int fbn(int n)
{
    cout << "调用fbn("<<n<<")的过程" << endl;
    if(n==1||n==2)
    {
        cout << "返回1" << endl;
        return 1;
    }
    else
    {
        cout << "调用fbn(" << n - 1 << ")和fbn(" << n - 2 << ")的过程" << endl;
        return fbn(n - 1) + fbn(n - 2);
    }
}

