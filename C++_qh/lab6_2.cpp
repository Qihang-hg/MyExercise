#include<iostream>
using namespace std;

//使用动态内存分配生成动态数组来重新完成任务1,使用指针完成函数的功能
void transpose(int **a,int **b,int row,int col)
{
    for (int i = 0; i < row;i++)
    {
        for (int j = 0; j < row;j++)
        {
            b[j][i] = a[i][j];
        }
    }
}

int main()
{
    int row, col;
    cout << "输入 行和列：" << endl;
    cin >> row >> col;
    //开辟行
    int **p = new int *[row];
    for (int i = 0; i < row;i++)
    {
        //列
        p[i] = new int[col];     
    }
    //输入矩阵
    cout << "输入数据" << endl;
    for (int i = 0; i < row;i++)
    {    
        for (int j = 0; j < col; j++)
        {
            cin >> p[i][j];
        }
    }
//保存转置后
        int **p2 = new int *[row];
    for (int i = 0; i < row;i++)
    {
        //列
        p2[i] = new int[col];     
    }
 

    //转置
    transpose(p, p2, row, col);
    cout << "转置矩阵为" << endl;
    for (int i = 0; i < col;i++)
    {
        for (int j = 0; j < row;j++)
        {
            cout << p2[i][j] << " ";
        }
        cout << endl;
    }
}