//3*3转置矩阵
#include<iostream>
#include<string>
using namespace std;



int main()
{
    int Arr[3][3] = { 1, 1, 1, 2, 2, 2,3, 3, 3};
    int b[3][3];
    

    for (int i = 0; i <= 2;i++)
    {
        for (int j = 0; j <= 2;j++)
        {
            b[j][i] = Arr[i][j]; 
        }
    }
        for (int i = 0; i <= 2;i++)
    {
        for (int j = 0; j <= 2;j++)
        {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}