#include<iostream>
using namespace std;

class test
{
private:
    int a,b;
public:
    test()
    {
        cout<<"Constructor Called\n";
    }
    ~test()
    {
        cout<<"Destructor\n";
    }
};

void solve()
{
    test obj1;
}

int main()
{
    test obj;
    solve();
    test obj1;
}
