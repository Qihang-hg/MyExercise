#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
public:
    Vehicle()
    {
        cout << "构造Vehicle" << endl;
    }
    ~Vehicle()
    {
        cout << "析构Vehicle" << endl;
    }
    virtual void Run(){}

    virtual void Stop(){}
 
};

class bicycle: public Vehicle
{
public:
    void Run()
    {
        cout << "bicyle Run" << endl;
    }
    void Stop()
    {
        cout << "bicyle Stop" << endl;
    }
};

class motorcar:public Vehicle
{
public:
    void Run()
    {
        cout << "motocar Run" << endl;
    }
    void Stop()
    {
        cout << "motocar Stop" << endl;
    }
};

class motorcycle:public bicycle,public motorcar
{
public:
    void Run()
    {
        cout << "motorcycle Run" << endl;
    }
    void Stop()
    {
        cout << "motorcycle  Stop" << endl;
    }

};

int main()
{
  
    bicycle b;
    motorcar m1;
    motorcycle m;

    b.Run();
    m1.Run();
    m.Run();
    return 0;
}