#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int parent[N], sz[N];

void make(int v)
{
	parent[v] = v;
	sz[v] = 1;
}

int find(int v)
{
	if(parent[v] == v)
	{
		return parent[v];
	}
	return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a!=b)
	{
		if(sz[a] < sz[b])
		{
			swap(a,b);
		}
		parent[b] = a;
		sz[a] += sz[b];
	}
}

int main()
{
	int n,m;
	cout<<"Enter number of node - ";
	cin>>n;
	cout<<"Enter number of edges - ";
	cin>>m;
	
	vector<pair<int, pair<int,int> > > edges;
	
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back({w, {u,v}});
	}
	sort(edges.begin(), edges.end());
	
	for(int i=1;i<=n;i++)
	{
		make(i);
	}
	
	int totalCost=0;
	for(auto &it:edges)
	{
		int wt = it.first;
		int u = it.second.first;
		int v = it.second.second;
		
		if(find(u) == find(v))
		{
			continue;
		}
		Union(u,v);
		totalCost += wt;
		cout<<u<<" "<<v<<" "<<endl;
	}
	cout<<totalCost;
}
