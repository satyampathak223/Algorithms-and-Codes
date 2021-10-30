#include<iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout<<"Parent class A constructor called\n";
    }
    ~A()
    {
        cout<<"Parent class A destructor called\n";
    }
};

class B:public A
{
public:
    B()
    {
        cout<<"Child class B constructor called\n";
    }
    ~B()
    {
        cout<<"Child class B destructor called\n";
    }
};

int main()
{
    B obj;
}
