#include<iostream>
#include<string>
using namespace std;

class CPU
{
private:
    enum CPU_Rank
    {
        P1 = 1,
        P2,
        P3,
        P4,
        P5,
        P6,
        P7
    };
    int freq;
    int vol;

public:
    CPU();
    ~CPU();
    void CPU_Set(int f, float v);//修改数据成员
    int GetFreq(){
        return freq;
    }
    float GetVol()
    {
        return vol;
    }
    void CPU_Run();
    void CPU_Stop();
};

CPU::CPU()//构造函数
{
    cout << "构造CPU" << endl;
}
CPU::~CPU()//构造函数
{
    cout << "析构CPU" << endl;
}

void CPU::CPU_Set(int f,float v)
{
    freq = f;
    vol = v;
}
void CPU::CPU_Run()
{
    cout << "CPU RUN!" << endl;
}
void CPU::CPU_Stop()
{
    cout << "CPU STOP!" << endl;
}

int main()
{
    CPU cpu;
    cpu.CPU_Run();
    cpu.CPU_Stop();
    return 0;
}