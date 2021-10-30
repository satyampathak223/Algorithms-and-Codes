#include <bits/stdc++.h>
using namespace std;

int dx[]={1,0,-1,0,-1,-1,1,1};
int dy[]={0,1,0,-1,-1,1,-1,1};

bool isValid(int x,int y,int n,int m,vector<vector<int>> &v)
{
    if(x<1||x>n||y<1||y>m)
        return false;
    if(v[x][y])
        return false;
    return true;
}

void bfs(int x,int y,int n,int m,vector<vector<int>> &a,vector<vector<int>> &v,vector<vector<int>> &dist)
{
    v[x][y]=1;
    dist[x][y]=0;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty())
    {
        int tempX=q.front().first;
        int tempY=q.front().second;
        q.pop();

        for(int i=0;i<8;i++)
        {
            int childX=tempX+dx[i];
            int childY=tempY+dy[i];

            if(isValid(childX,childY,n,m,v))
            {
                q.push({childX,childY});
                dist[childX][childY]=dist[tempX][tempY]+1;
                v[childX][childY]=1;
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(m+1,0)),v(n+1,vector<int>(m+1,0)),dist(n+1,vector<int>(m+1,0));
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=m;j++)
    //         cin>>a[i][j];
    bfs(3,3,n,m,a,v,dist);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<dist[i][j]<<" ";
        cout<<"\n";
    }
}