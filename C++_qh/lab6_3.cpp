/*
编程实现两个字符串的连接。声明字符数组保存字符串，
在程序中提示用户输入两个字符串，实现两个字符串的连接，
最后用cout语句显示输出。用cin实现输入，
注意，字符串的结束标志是ASCII码0，
使用循环语句进行字符串间的字符拷贝
*/
#include<iostream>
using namespace std;

int main()
{
    int count=0;
    char str1[100], str2[100], str3[200];
    cout << "Input str1(less than 100 characters):" << endl;
    cin >> str1;
    cout << "Input str2(less than 100 characters):" << endl;
    cin >> str2;
    for (int i = 0; str1[i] != '\0';i++)
    {
        str3[i] = str1[i];
        count++;
    }
    int count_1 = 0;
    for (int j = 0; str2[j] != '\0';j++)
    {
        str3[count+j] = str2[j];
        count_1++;
    }
    str3[count+count_1]= '\0';
    cout << "str3=" << str3<<endl;
}