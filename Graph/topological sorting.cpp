#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> g;
vector<int> indegree,ans;

void toposort(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        ans.push_back(temp);
        for(auto &it:g[temp])
        {
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    indegree.assign(n+1,0);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indegree[b]++;
    }
    toposort(n);
    for(auto it:ans)
        cout<<it<<" ";
}