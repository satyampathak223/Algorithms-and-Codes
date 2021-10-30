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
        cout<<a<<" + "<<b<<" i\n";
    }
    Complex operator+(Complex c)
    {
        Complex sum;
        sum.a=a+c.a;
        sum.b=b+c.b;
        return sum;
    }
    Complex operator^(Complex c)
    {
        Complex Or;
        Or.a=a^c.a;
        Or.b=b^c.b;
        return Or;
    }

    Complex operator++()
    {
        Complex res;
        res.a=(this.a)+1;
        res.b=(this.b)+1;
    }

};

int main()
{
    Complex o1,o2;
    o1.Set(1,3);
//    o2.Set(1,3);
    o1.Get();
//    o2.Get();
    Complex pre=o1++;
    pre.Get();
}
