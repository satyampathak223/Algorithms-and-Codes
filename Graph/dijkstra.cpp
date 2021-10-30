#include<bits/stdc++.h>
#define pii pair<int,int> 
using namespace std;

map<int,vector<pii>> g;
vector<int> dist;

void dijkstra(int node)
{
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,node});
	dist[node]=0;
	while(!pq.empty())
	{
		pii p=pq.top();
		pq.pop();
		for(auto it:g[p.second])
		{
			if(it.second+p.first<dist[it.first])
			{
				dist[it.first]=p.first+it.second;
				pq.push({dist[it.first],it.first});
			}
		}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		g[a].push_back({b,w});
		g[b].push_back({a,w});
	}
	const int inf=1e9;
	dist.assign(n+1,inf);
	dijkstra(1);
	for(int i=1;i<=n;i++)
		cout<<dist[i]<<" ";
	cout<<"\n";
}