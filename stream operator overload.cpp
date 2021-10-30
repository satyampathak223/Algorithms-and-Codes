#include<iostream>
using namespace std;

class A
{
    int a,b;
public:
    friend void print(A);
    void Set(int x,int y)
    {
        a=x;
        b=y;
    }
    friend ostream& operator<<(ostream&,const A&);
    friend istream& operator>>(istream&,A&);
};

// Overloaded stream extraction ( << ) operator for class A;
ostream& operator<<(ostream& out, const  A& c)
{
    out<<c.a<<" + "<<c.b<<" i\n";
    return out;
}

// Overloaded stream insertion ( >> ) operator for class A;
istream& operator>>(istream& in,A &c)
{
    cout<<"Enter the real and imaginary part \n";
    in>>c.a>>c.b;
    return in;
}

void print(A c)
{
    cout<<c.a<<" + "<<c.b<<" i\n";
}

int main()
{
    A o1,o2;
//    o1.Set(3,4);
    cin>>o1>>o2;
//    o2.Set(5,6);
    cout<<"Complex numbers are\n"<<o1<<o2;
//    print(o1);
}
