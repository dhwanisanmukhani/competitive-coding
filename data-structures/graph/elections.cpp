#include <iostream>
#include <vector>
using namespace std;
#define MAX 100010
vector<vector<int> > tree(MAX);
vector<vector<pair<int, int> > > adj(MAX);
vector<int> parent(MAX);
vector<int> flag;
vector<int> subset;
int total;

void recurse(int n)
{
	if(flag[n] == 1)
	{
		subset[n] = 1;
		total++;
	}
	for(int i = 0; i < tree[n].size(); i++)
	{
		recurse(tree[n][i]);
		if(subset[tree[n][i]] == 1)
		{
			if(subset[n] == 1)
				total--;
			subset[n] = 10;
		}
		else if(subset[tree[n][i]] == 10)
		{
			if(subset[n] == 1)
				total--;
			subset[n] = 10;
		}
	}
}

void parentisize(int n)
{
	for (int i = 0; i < adj[n].size(); ++i)
	{
		if(parent[n] == adj[n][i].first)
			continue;
		else
		{
			parent[adj[n][i].first] = n;
			tree[n].push_back((adj[n][i]).first);
			if(adj[n][i].second == 2)
				flag[adj[n][i].first] = 1;
			parentisize(adj[n][i].first);
		}
	}
}

int main()
{
	int n, a, b, f;
	cin>>n;
	flag.assign(n+1, 0);
	subset.assign(n+1, -1);
	for (int i = 0; i < n-1; ++i)
	{
		cin >>a >>b >>f;
		adj[a].push_back(make_pair(b, f));
		adj[b].push_back(make_pair(a, f));
	}
	parentisize(1);
	recurse(1);
	cout<<total<<endl;
	for (int i = 1; i <= n; ++i)
	{
		if(subset[i] == 1)
			cout<<i<<" ";
	}
	cout<<endl;
}