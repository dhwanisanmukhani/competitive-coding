#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj(150050);
vector<int> visited;
long long int vertices = 0, edges = 0;
int flag =-1;
void dfs(int n)
{
	visited[n] = 0;
	vertices++;
	edges +=adj[n].size();
	for (int i = 0; i < adj[n].size(); ++i)
	{
		if(visited[adj[n][i]] == 0)
			continue;
		dfs(adj[n][i]);
	}
	if(vertices * (vertices - 1) > edges)
		flag = 0;
	return;
}

int main()
{
	int n, m;
	cin >>n >>m;
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >>a >>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	visited.assign(150050, -1);
	for (int i = 1; i < n+1; ++i)
	{
		if(visited[i] == 0)
			continue;
		dfs(i);
		if(flag == 0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		else
		{
			vertices = 0;
			edges = 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}