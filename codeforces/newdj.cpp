#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef pair<long long int, int> lii;
vector<int> parent;

void printp(int n)
{
	if(parent[n] != -1)
		printp(parent[n]);
	cout<<n<<" ";
}

int main()
{
	int vertices, edges, a, b, c;
	cin >>vertices >>edges;
	vector< vector<ii> > adj(vertices+1);
	for (int i = 0; i < edges; ++i)
	{
		cin >>a >>b >>c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	vector<long long int> dist(vertices+1, 1e18);
	dist[1] = 0;
	parent.assign(vertices +1, -1);
	priority_queue < lii, vector<lii>, greater<lii> > p;
	p.push(lii(0, 1));
	while(!p.empty())
	{
		lii front = p.top();
		p.pop();
		long long int d = front.first;
		int u = front.second;
		if(d > dist[u])
			continue;
		for (int i = 0; i < adj[u].size(); ++i)
		{
			ii v = adj[u][i];
			if(d + v.second < dist[v.first])
			{
				dist[v.first] = d + v.second;
				parent[v.first] = u;
				p.push(lii(dist[v.first], v.first));
			}
		}
	}
	if(dist[vertices] == 1e18)
			cout<<"-1"<<endl;
		else
		{
			printp(vertices);
		}
}