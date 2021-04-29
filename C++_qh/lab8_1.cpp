#include<iostream>
#include<string>
using namespace std;
//定义Point类，有坐标_x，_y两个成员变量；
//对Point类重载“++”（自增）、“–”（自减）运算符，实现对坐标值的改变。

class Point
{
private:
    int x;
    int y;
public:
    Point(int a,int b)
    {
        x = a;
        y = b;
    }
    Point &operator++();
    Point operator++(int);
    Point &operator--();
    Point operator--(int);
    void showPoint();
};

Point&Point::operator++()//前置++
{
    ++x, ++y;
    return *this;
}
Point Point::operator++(int)//后置++ 
{
	x++,y++;
	return *this;
}
Point & Point::operator--()//前置-- 
{	
	--x,--y;
	return *this;
}
Point Point::operator--(int)//后置--
{
	x--,y--;
	return *this;
} 
void Point::showPoint()
{
    cout << "x= " << x << " y = " << y << endl;
}

int main()
{
    Point p(2, 3);
    p.showPoint();
    cout << "++p:" << endl;
    ++p;
    p.showPoint();
    cout << "---------" << endl;
    cout << "p++:" << endl;
    p++;
    p.showPoint();
}
