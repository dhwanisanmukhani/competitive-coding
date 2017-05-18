#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int v;
	cin>>v;
	int node,edge;
	vector<vector<int> > matrix(n, vector<int>(n,0));
	for(int i=0;i<v;i++)
	{
		int node,edge;
		cin>>node>>edge;
		matrix[node-1][edge-1]=1;
		matrix[edge-1][node-1]=1;
	}
	cout<<"Query"<<endl;
	cin >> node >> edge;

	if(matrix[node-1][edge-1]==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}