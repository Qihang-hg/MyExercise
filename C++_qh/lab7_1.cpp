#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
    int a_Age;

};

class Dog:public Animal
{
public:
    void SetAge(int);
    int GetAge();
};

void Dog::SetAge(int n)
{
    this->a_Age = n;
}
int Dog::GetAge()
{
    return this->a_Age;
}

int main()
{
    Dog dog;
    dog.SetAge(10);
    cout << "dog's age is " << dog.GetAge() << endl;
    return 0;
}