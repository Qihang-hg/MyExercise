#include "stdio.h"
#include <math.h>

void down_hill();

int main(int argc, char* argv[])
{

	down_hill();
	return 0;
}
//最速下降法
void down_hill()
{
	int i,k;
	double xk[10], Fxk[10], phi;
	double J[10][10];
	double alpha;
	double xk1[10], Fxk1[10], phi1, phi2;
	double a, b;
	double epsilon;

	epsilon=0.0000000001;
	
	//初始化
	xk[1]=1;
	xk[2]=1;
	xk[3]=1;
	xk[4]=1;
	xk[5]=1;

	//计算phi函数
	Fxk[1] = 2*xk[1] - xk[4]*xk[2]*xk[2] - 2*xk[5]*xk[1];
	Fxk[2] = 2*xk[2] - 2*xk[4]*xk[1]*xk[2] + 4*xk[5]*xk[2];
	Fxk[3] = 4*xk[3] + 2*xk[4] + 2*xk[5];
	Fxk[4] = xk[1]*xk[2]*xk[2] - 2*xk[3] + 5;
	Fxk[5] = xk[1]*xk[1] - 2*xk[2]*xk[2] -2*xk[3] + 7;
	
	//计算雅可比矩阵
	J[1][1] = 2-2*xk[5];	
	J[1][2] = -2*xk[4]*xk[2];
	J[1][3] = 0;
	J[1][4] = -xk[2]*xk[2];
	J[1][5] = -2*xk[1];

	J[2][1] = -2*xk[4]*xk[2];	
	J[2][2] = 2-2*xk[4]*xk[1]+4*xk[5];
	J[2][3] = 0;
	J[2][4] = -2*xk[1]*xk[2];
	J[2][5] = 4*xk[2];

	J[3][1] = 0;	
	J[3][2] = 0;
	J[3][3] = 4;
	J[3][4] = 2;
	J[3][5] = 2;

	J[4][1] = xk[2]*xk[2];	
	J[4][2] = 2*xk[1]*xk[2];
	J[4][3] = -2;
	J[4][4] = 0;
	J[4][5] = 0;

	J[5][1] = 2*xk[1];	
	J[5][2] = -4*xk[2];
	J[5][3] = -2;
	J[5][4] = 0;
	J[5][5] = 0;

	//构造函数的值
	phi=0.5*(Fxk[1]*Fxk[1] + Fxk[2]*Fxk[2] + Fxk[3]*Fxk[3] + Fxk[4]*Fxk[4] + Fxk[5]*Fxk[5]);
	//起始点：
	printf("k=%d, xk=[%f, %f, %f, %f, %f], phi=%f\n", 0, xk[1], xk[2], xk[3], xk[4], xk[5], phi);
	//最速下降迭代k=1,2,3,...
	for(k=1;;k++)
	{
		//确定区间[a, b];
		a=0;
		b=0.0001;
		for(;;)
		{
			for(i=1;i<=5;i++)
			{
				xk1[i] = xk[i] - b*(Fxk[1]*J[1][i] + Fxk[2]*J[2][i] + Fxk[3]*J[3][i] + Fxk[4]*J[4][i] +Fxk[5]*J[5][i]);
			}

			Fxk1[1] = 2*xk1[1] - xk1[4]*xk1[2]*xk1[2] - 2*xk1[5]*xk1[1];
			Fxk1[2] = 2*xk1[2] - 2*xk1[4]*xk1[1]*xk1[2] + 4*xk1[5]*xk1[2];
			Fxk1[3] = 4*xk1[3] + 2*xk1[4] + 2*xk1[5];
			Fxk1[4] = xk1[1]*xk1[2]*xk1[2] - 2*xk1[3] + 5;
			Fxk1[5] = xk1[1]*xk1[1] - 2*xk1[2]*xk1[2] -2*xk1[3] + 7;

			phi1=0;
			for(i=1;i<=5;i++)phi1 = phi1 + 0.5*Fxk1[i]*Fxk1[i];
			if(phi1>phi)	//变坏
			{
				break;
			}
			else
			{
				b = b * 2;
			}
		}
		//0.618法查找[a, b]之间的最优点alpha
		if(b - a <= epsilon) 
		{
			alpha = (b + a)/2;
		}
		else
		{
			double a1, b1;
			double m1, m2;
			a1=a; b1=b;
			for(;;)
			{
				m1 = a1 + 0.382*(b1 - a1);
				m2 = a1 + 0.618*(b1 - a1);
				//计算左边点
				for(i=1;i<=5;i++)
				{
					xk1[i] = xk[i] - m1*(Fxk[1]*J[1][i] + Fxk[2]*J[2][i] + Fxk[3]*J[3][i] + Fxk[4]*J[4][i] +Fxk[5]*J[5][i]);
				}

				Fxk1[1] = 2*xk1[1] - xk1[4]*xk1[2]*xk1[2] - 2*xk1[5]*xk1[1];
				Fxk1[2] = 2*xk1[2] - 2*xk1[4]*xk1[1]*xk1[2] + 4*xk1[5]*xk1[2];
				Fxk1[3] = 4*xk1[3] + 2*xk1[4] + 2*xk1[5];
				Fxk1[4] = xk1[1]*xk1[2]*xk1[2] - 2*xk1[3] + 5;
				Fxk1[5] = xk1[1]*xk1[1] - 2*xk1[2]*xk1[2] -2*xk1[3] + 7;
				phi1=0;
				for(i=1;i<=5;i++)phi1 = phi1 + 0.5*Fxk1[i]*Fxk1[i];
				
				//计算右边点
				for(i=1;i<=5;i++)
				{
					xk1[i] = xk[i] - m2*(Fxk[1]*J[1][i] + Fxk[2]*J[2][i] + Fxk[3]*J[3][i] + Fxk[4]*J[4][i] +Fxk[5]*J[5][i]);
				}

				Fxk1[1] = 2*xk1[1] - xk1[4]*xk1[2]*xk1[2] - 2*xk1[5]*xk1[1];
				Fxk1[2] = 2*xk1[2] - 2*xk1[4]*xk1[1]*xk1[2] + 4*xk1[5]*xk1[2];
				Fxk1[3] = 4*xk1[3] + 2*xk1[4] + 2*xk1[5];
				Fxk1[4] = xk1[1]*xk1[2]*xk1[2] - 2*xk1[3] + 5;
				Fxk1[5] = xk1[1]*xk1[1] - 2*xk1[2]*xk1[2] -2*xk1[3] + 7;
				phi2=0;
				for(i=1;i<=5;i++)phi2 = phi2 + 0.5*Fxk1[i]*Fxk1[i];
				
				if(phi1>phi2)
				{
					a1=m1;
				}
				else
				{
					b1=m2;
				}
				if( b1-a1 <= epsilon ) break;
			}
			alpha = (b1+a1)/2;
		}
		//计算
		for(i=1;i<=5;i++)
		{
			xk1[i] = xk[i] - alpha*(Fxk[1]*J[1][i] + Fxk[2]*J[2][i] + Fxk[3]*J[3][i] + Fxk[4]*J[4][i] +Fxk[5]*J[5][i]);
		}

		Fxk1[1] = 2*xk1[1] - xk1[4]*xk1[2]*xk1[2] - 2*xk1[5]*xk1[1];
		Fxk1[2] = 2*xk1[2] - 2*xk1[4]*xk1[1]*xk1[2] + 4*xk1[5]*xk1[2];
		Fxk1[3] = 4*xk1[3] + 2*xk1[4] + 2*xk1[5];
		Fxk1[4] = xk1[1]*xk1[2]*xk1[2] - 2*xk1[3] + 5;
		Fxk1[5] = xk1[1]*xk1[1] - 2*xk1[2]*xk1[2] -2*xk1[3] + 7;
		phi1=0;
		for(i=1;i<=5;i++)phi1 = phi1 + 0.5*Fxk1[i]*Fxk1[i];
		printf("k=%d, alpha=%f, xk=[%f, %f, %f, %f, %f], phi=%f\n", k, alpha, xk1[1], xk1[2], xk1[3], xk1[4], xk1[5], phi1);


		//k = k+1
		for(i=1;i<=5;i++)
		{
			xk[i]=xk1[i];
			Fxk[i]=Fxk1[i];
		}

		J[1][1] = 2-2*xk[5];	
		J[1][2] = -2*xk[4]*xk[2];
		J[1][3] = 0;
		J[1][4] = -xk[2]*xk[2];
		J[1][5] = -2*xk[1];

		J[2][1] = -2*xk[4]*xk[2];	
		J[2][2] = 2-2*xk[4]*xk[1]+4*xk[5];
		J[2][3] = 0;
		J[2][4] = -2*xk[1]*xk[2];
		J[2][5] = 4*xk[2];

		J[3][1] = 0;	
		J[3][2] = 0;
		J[3][3] = 4;
		J[3][4] = 2;
		J[3][5] = 2;

		J[4][1] = xk[2]*xk[2];	
		J[4][2] = 2*xk[1]*xk[2];
		J[4][3] = -2;
		J[4][4] = 0;
		J[4][5] = 0;

		J[5][1] = 2*xk[1];	
		J[5][2] = -4*xk[2];
		J[5][3] = -2;
		J[5][4] = 0;
		J[5][5] = 0;

		phi=phi1;
		if (phi1<=0.000001) 
		{
			break;
		}
	}
	getchar();
}

