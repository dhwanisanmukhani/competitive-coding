#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > graph;
vector<int> visit(26,0);
vector<int> color(26,0);

int check(int i)
{
	color[i]=1;
	visit[i]=1;
	for(int j=0;j<graph[i].size();j++)
	{
		if(color[graph[i][j]]==1)
			return 1;
		else
			return check(graph[i][j]);
	}
	color[i]=2;
	return 0;
}

int main()
{
	int l;
	int u,v;
	graph.resize(l);
	for(int i=0;i<l;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
	}
	for(int i=0;i<l;i++)
	{
		if(visit[i]==1)
			continue;
		else
		{
			if(check(i)==1)
			{	
				cout<<"Impossible"<<endl;
				return 0;
			}
		}
	}
}