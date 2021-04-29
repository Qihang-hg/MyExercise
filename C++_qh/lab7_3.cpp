#include<iostream>
#include<string>
using namespace std;


/*
定义一个车（vehicle）基类，
具有MaxSpeed、Weight等成员变量，Run、Stop等成员函数，
由此派生出自行车（bicycle）类、汽车（motorcar）类。
自行车（bicycle）类有高度（Height）等属性，
汽车（motorcar）类有座位数（SeatNum）等属性。
从bicycle和motorcar派生出摩托车（motorcycle）类，
在继承过程中，注意把vehicle设置为虚基类。
如果不把vehicle设置为虚基类，会有什么问题？编程试试看。

*/
class vehicle
{
public:
	void Run(){cout<<"车开始运行"<<endl;}
	void Stop(){cout<<"车停止运行"<<endl;}
protected:
	int MaxSpeed;
	int Weight;	
};

class bicycle:virtual public vehicle
{
protected:
	int Height;
};

class motorcar:virtual public vehicle
{
protected:
	int SeatNum;
};

class motorcycle:public bicycle,public motorcar
{
public:
	motorcycle(int m,int w,int h,int s)
	{
		MaxSpeed=m,Weight=w,Height=h,SeatNum=s;
	}
	void show()
	{
		cout<<"MaxSpeed: "<<MaxSpeed<<"\nWeight: "<<Weight
		<<"\nHeight: "<<Height<<"\nSeatNum:"<<SeatNum<<endl;
	}
};

int main()
{
	motorcycle mo(100,150,130,2);
	mo.Run();
	mo.show();
	mo.Stop();
	return 0;
}
