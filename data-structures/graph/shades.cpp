#include <iostream>
#include <vector>
using namespace std;
//0 White
//1 Grey
//2 Black
vector<vector<int> > dag;
vector<int> visit;
void filling(int i, vector<int>& color)
{
	if(visit[i]==1)
		return;
	color[i]=1;
	visit[i]=1;
	if(dag[i].size()>0)
	{
		for(int j=0;j<dag[i].size();j++)
		{
			if(visit[dag[i][j]]==1)
				continue;
			if(color[dag[i][j]]==1)
			{
				cout<<"BACK EDGE"<<i<<":"<<dag[i][j]<<endl;
			}
			else if(color[dag[i][j]]==2)
			{
				cout<<"CROSS EDGE"<<i<<":"<<dag[i][j]<<endl;
			}
			else
			{
				cout<<"TREE EDGE"<<i<<":"<<dag[i][j]<<endl;
			}
			if(visit[dag[i][j]]==0)
				filling(dag[i][j], color);
		}
		color[i]=2;
		return;
	}
	else
	{
		color[i]=2;
		return;
	}
}
int main()
{
	int n;
	cin>>n;
	int edges;
	cin>>edges;
	dag.resize(n+1);
	visit.resize(n+1);
	vector<int> color(n+1,0);
	int v,u;
	for(int i=0;i<edges;i++)
	{
		cin>>u>>v;
		dag[u].push_back(v);
		dag[v].push_back(u);
	}
	filling(1,color);
	return 0;
}