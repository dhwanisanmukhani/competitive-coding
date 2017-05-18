#include <iostream>
#include <vector>
using namespace std;

vector<int> visit(26,0);
vector<vector<int> > graph(26);
vector<int> printed(26,0);
vector<int> topo;
vector<int> color(26,0);

int check(int i)
{
	color[i]=1;
	visit[i]=1;
	for(int j=0;j<graph[i].size();j++)
	{
		
		if(color[graph[i][j]]==1)
		{
			//cout<<graph[i][j]<<endl;
			//cout<<i<<"yahoo"<<j<<endl;
			return 1;
		}
		else
		{
			if(visit[graph[i][j]]==1)
				continue;
			if(check(graph[i][j])==1)
				return 1;
		}
	}
	color[i]=0;
	return 0;
}

void print(int i)
{

	printed[i]=1;
	for(int j=0;j<graph[i].size();j++)
	{
		int v=graph[i][j];
		if(printed[v]==0)
			print(v);
	}
	topo.push_back(i);
}

int main()
{
	int l;
	cin>>l;
	vector<string> names(l);
	for(int i=0;i<l;i++)
	{
		cin>>names[i];
	}
	int flag=0;
	for(int i=0;i<l-1;i++)
	{
		for(int l=0;l<(min(names[i].length(),names[i+1].length()));l++)
		{
			if(names[i][l]==names[i+1][l])
				continue;
			else
			{	
				graph[names[i][l]-'a'].push_back(names[i+1][l]-'a');
				flag=1;
			    break;
			}
		}
		if(flag==0)
		{
			if(names[i].length()>names[i+1].length())
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
		}
	}
	for(int i=0;i<26;i++)
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

	for(int i=0;i<26;i++)
	{
		if(printed[i]==0)
			print(i);
	}
	for(int i=topo.size()-1;i>=0;i--)
	{
		char t;
		t=topo[i]+97;
		cout<<t;
	}
	cout<<endl;
	return 0;
}