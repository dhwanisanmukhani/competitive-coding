#include <iostream>
#include <vector>
using namespace std;

void preorder(vector<vector<int> >& graph,vector<vector<int> >& flag,int i)
{
	cout<<i<<endl;
	for(int j=0;j<graph[i].size();j++)
	{
		flag[i][graph[i][j]]=1;
		if(flag[graph[i][j]][i]==1)
		{
			continue;
		}
		else
		{
			preorder(graph,flag,graph[i][j]);
		}
		flag[graph[i][j]][i]=1;
	}
	return;
}

int main()
{
	int nodes;
	cin>>nodes;
	int nedges;
	cin>>nedges;
	vector<vector<int> > graph(nodes);
	vector<vector<int> > flag(nodes,vector<int>(nodes,0));
	{
		for(int i=0;i<nedges;i++)
		{
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
	}
	preorder(graph, flag, 0);
	return 0;
}