#include<iostream>
#include<string>
using namespace std;

int main()
{
    for (int i = 1; i <= 9;i++)
    {
        for (int j = 1; j <= 9;j++)
        {
            if(j >=i)
            {
                int ret = i * j;
                cout << i << "*" << j << "=" << ret<<endl;
            }
        }
    }
}