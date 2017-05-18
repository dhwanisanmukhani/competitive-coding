#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef pair<string, string> ss;
vector<vector<int> > adj(202);

int main()
{
	int n;
	cin >>n;
	string s1, s2, s3;
	vector<string> str;
	queue<int> q;
	str.push_back("polycarp");
	for (int i = 0; i < n; ++i)
	{
		cin>>s1>>s3>>s2;
		for(int j = 0; j < s1.length(); j++)
		{
			s1[j] = tolower(s1[j]);
		}
		int j=0, flag1 = -1;
		for(j = 0; j < str.size(); j++)
		{
			if(s1 == str[j])
				break;
		}
		if(flag1 != 0)
		{
			str.push_back(s1);
		}
		for(int k = 0; k < s2.length(); k++)
		{
			s2[k] = tolower(s2[k]);
		}
		int k=0, flag2 = -1;;
		for(k = 0; k < str.size(); k++)
		{
			if(s2 == str[k])
			{
				flag2 = 0;
				break;
			}
		}
		if(flag2 != 0)
		{
			str.push_back(s2);
		}

		adj[j].push_back(k);
		adj[k].push_back(j);
	}
	q.push(0);
	vector<int> dist(202, -1e9);
	vector<int> parent(202, 0);
	dist[0] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); ++i)
		{
			int v = adj[u][i];
			if (parent[u] == v)
				continue;
			parent[v] = u;
			int d = dist[u] + 1;
			if(dist[v] < d)
			{
				dist[v] = d;
				q.push(v);
			}
		}
	}
	int m = -1;
	for (int i = 0; i < 202; ++i)
	{
		if(dist[i] > m)
			m = dist[i];
	}
	cout<<m<<endl;
}