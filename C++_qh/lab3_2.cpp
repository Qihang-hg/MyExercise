#include <iostream> 
using namespace std; 
enum CPU_rank {P1=1,P2,P3,P4,P5,P6,P7}; 
class CPU 
{   
private: 
	CPU_rank rank; 
	int frequency; 
	float voltage; 
public: 
    CPU (CPU_rank r, int f, float v) 
	{    
		rank = r; 
  		frequency = f; 
  		voltage = v; 
  		cout << "构造了一个CPU!" << endl; 
 	} 
	CPU() {   cout << "构造了一个CPU!" << endl; };   
	~CPU () {    cout << "析构了一个CPU!" << endl; } 
 	void Run() {cout << "CPU开始运行!" << endl; } 
 	void Stop() {cout << "CPU停止运行!" << endl; } 
}; 

class RAM 
{    
public: 
    RAM () {   cout << "构造了一个RAM!" << endl;  }  
	~RAM (){   cout << "析构了一个RAM!" << endl; } 
   	void Run() {cout << "RAM开始运行!" << endl; } 
 	void Stop() {cout << "RAM停止运行!" << endl; } 
}; 

class CDROM 
{   
public: 
    CDROM (){ cout << "构造了一个CDROM!" << endl; }   
	~CDROM () { cout << "析构了一个CDROM!" << endl;  } 
   	void Run() {cout << "CDROM开始运行!" << endl; } 
 	void Stop() {cout << "CDROM停止运行!" << endl; } 
}; 

class computer 
{   
private: 
 	CPU cpu; 
 	RAM ram; 
 	CDROM cdrom; 
public: 
 	computer() {cout << "构造了一个computer!" << endl; }
	~computer () { cout << "析构了一个computer!" << endl; } 
   	void Run()  
 	{   
	 	cout << "computer开始运行!" << endl; 
  		cpu.Run(); 
  		ram.Run(); 
 	} 
 	void Stop()  
 	{   ram.Stop(); 
  		cpu.Stop(); 
  		cout << "computer停止运行!" << endl;  
 	} 
}; 

int main() 
{    
	computer a; 
 	a.Run(); 
 	a.Stop(); 
 	return 0;
} 
