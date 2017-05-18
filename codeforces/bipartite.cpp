#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > adjlist;
vector<int> color;

int main()
{
	int n;
	cin>>n;
	int edges;
	cin>>edges;
	int u,v;
	adjlist.resize(n+1);
	color.assign(n+1,-1);
	for(int i=0;i<edges;i++)
	{
		cin>>u>>v;
		adjlist[u].push_back(v);
	}
	color[1]=0;
	queue<int> q;
	q.push(1);
	bool isBiparite=true;
	while(!q.empty() && isBiparite)
	{
		int u = q.front();
		q.pop();
		for(int j=0;j<adjlist[u].size();j++)
		{
			int v = adjlist[u][j];
			if(color[v]==-1)
			{
				color[v]=1-color[u];
				q.push(v);
			}
			else if(color[v]==color[u])
			{
				isBiparite=false;
				break;
			}
		}
	}
	cout<<color[2]<<endl;
	return 0;
}