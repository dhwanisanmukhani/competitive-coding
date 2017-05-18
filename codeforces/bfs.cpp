#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > adjlist;

int main()
{
	int n;
	cin>>n;
	int edges;
	cin>>edges;
	int u,v;
	adjlist.resize(n+1);
	for(int i=0;i<edges;i++)
	{
		cin>>u>>v;
		adjlist[u].push_back(v);
	}
	vector<int> d(n+1,-1);
	d[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int j=0;j<adjlist[u].size();j++)
		{
			int v = adjlist[u][j];
			if(d[v]==-1)
			{
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	cout<<d[2]<<endl;
	return 0;
}