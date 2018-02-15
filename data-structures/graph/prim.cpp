//Prim's algorithm
//Here priority queue library function is actually MAXIMUM binary heap kind

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
priority_queue<ii> p;
vector<vector<ii> > adj;
vector<int> visited;
void process(int v)
{
	visited[v] = 1;
	for (int i = 0; i < adj[v].size(); ++i)
	{
		ii temp = adj[v][i];
		if(visited[temp.first] == 0)
		{
			p.push(ii(-temp.second, -temp.first));				// Negative because priority queue is max priority queue
		}
	}
}

int main()
{
	int vertices, edges, a, b, c;
	cin >>vertices >>edges;
	adj.resize(vertices +1);
	visited.assign(vertices +1, 0);
	for (int i = 0; i < edges; ++i)
	{
		cin >>a >>b >>c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	process(1);
	int total = 0;
	while(!p.empty())
	{
		ii front = p.top();
		p.pop();
		int w = -front.first;
		int u = -front.second;
		if(!visited[u])
		{
			total += w;
			process(u);
		}
	}
	cout<<total<<endl;
	return 0;
}