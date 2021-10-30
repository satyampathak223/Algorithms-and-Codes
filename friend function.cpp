#include<iostream>
using namespace std;

class Complex
{
private:
    int a,b;
public:
    void Set(int x,int y)
    {
        a=x,b=y;
    }
    void Get()
    {
        cout<<a<<" + "<<b<<" i "<<"\n";
    }
    friend void Display();
};

int main()
{
    Complex o1;
    o1.Set(2,3);o1.Get();
}
