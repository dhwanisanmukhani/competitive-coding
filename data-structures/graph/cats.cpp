#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef std::vector<int> vi;

void tour(vi& flag, vector<vector<int> >& graph, vii& dp, vi& visit, int i)
{
	/*if(visit[i]==1)
	{
		return;
	}*/
	visit[i]=1;
	for(int j=0;j<graph[i].size();j++)
	{
		if(visit[graph[i][j]]==1)
		{
			continue;
		}
		if(flag[graph[i][j]]==1)
		{
			dp[graph[i][j]].first = dp[i].first +1;
			dp[graph[i][j]].second = max(dp[graph[i][j]].first, dp[i].second);
			//cout<<dp[graph[i][j]].second<<" "<<graph[i][j]+1<<endl;
		}
		else
		{
			dp[graph[i][j]].first = 0;
			dp[graph[i][j]].second = dp[i].second;
			//cout<<dp[graph[i][j]].second<<" "<<graph[i][j]+1<<endl;
		}
		tour(flag,graph,dp,visit,graph[i][j]);
	}
	return;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vi node_flag(n,0);
	vii dp;
	dp.resize(n);
	vector<vector<int> > graph(n);
	vi node_visit;
	node_visit.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>node_flag[i];
	}
	if(node_flag[0]==1)
	{
		dp[0].first=1;
		dp[0].second=1;
	}
	else
	{
		dp[0].first=0;
		dp[0].second=0;
	}
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}
	tour(node_flag,graph,dp,node_visit,0);
	int count=0;
	for(int i=1;i<n;i++)
	{
		if(graph[i].size()==1)
		{
			if(dp[i].second<=m)
			{
				//cout<<dp[i].second<<" "<<i+1<<endl;
				count++;
			}
		}
	}
	cout<<count<<endl;
}
