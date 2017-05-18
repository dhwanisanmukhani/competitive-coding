#include <iostream>
#include <vector>
using namespace std;

void preorder(vector<vector<int> >& v,int i)
{
	cout<<i<<endl;
	for(int j=0;j<v[i].size();j++)
	{
		preorder(v,v[i][j]);
	}
	return;
}
int main()
{
	int n;
	cin>>n;
	int u;
	cin>>u;
	vector<vector<int> >v(n);
	int edge,node;
	for(int i=0;i<u;i++)
	{
		cin>>node>>edge;
		v[node].push_back(edge);
	}
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" : "<<v[i].size()+1<<endl;
	}
	preorder(v,0);
	return 0;
}