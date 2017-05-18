#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > graph;
vector<int> flag;
vector<int> series;

void topo_tour(int u)
{
	flag[u]=1;
	for(int j=0;j<graph[u].size();j++)
	{
		if(flag[graph[u][j]]==0)
		{
			topo_tour(graph[u][j]);
		}
	}
	series.push_back(u);
	return;
}

int main()
{
	int n;
	cin>>n;
	int edges;
	cin>>edges;
	graph.resize(n);
	flag.assign(n, 0);
	int u,v;
	for(int i=0;i<edges;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
	}
	for(int i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			topo_tour(i);
		}
	}
	for(int i=0;i<series.size();i++)
	{
		cout<<series[i]<<" ";
	}
	return 0;
}