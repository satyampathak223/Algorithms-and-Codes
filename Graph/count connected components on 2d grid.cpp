#include <bits/stdc++.h>
using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

bool isValid(int x,int y,int n,int m,vector<vector<int>> &a,vector<vector<int>> &v)
{
    if(x<1||x>n||y<1||y>m)
        return false;
    if(v[x][y]||a[x][y]==0)
        return false;
    return true;
}

void dfs(int x,int y,int n,int m,vector<vector<int>> &a,vector<vector<int>> &v)
{
    v[x][y]=1;
    for(int i=0;i<4;i++)
    {
        if(isValid(x+dx[i],y+dy[i],n,m,a,v))
            dfs(x+dx[i],y+dy[i],n,m,a,v);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int> (m+1,0)),v(n+1,vector<int> (m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    }
    int c=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i][j]==false&&a[i][j]==1)
                c++,dfs(i,j,n,m,a,v);
        }
    }
    cout<<c<<"\n";
}