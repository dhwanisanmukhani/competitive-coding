#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > tree;
vector<int> dp;

int depth(int i)
{
	if(tree[i].size()==0)
	{
		dp[i]=1;
		//cout<<dp[i]<<"leaf"<<i<<endl<<endl;
		return dp[i];
	}
	else
	{
		for(int j=0;j<tree[i].size();j++)
		{
			dp[tree[i][j]]=depth(tree[i][j]);
		}
		dp[i]=0;
		for(int j=0;j<tree[i].size();j++)
		{
			//cout<<dp[tree[i][j]]<<endl;
			dp[i]=max(dp[i],dp[tree[i][j]]);
		}
		dp[i]=dp[i]+1;
		//cout<<dp[i]<<"node"<<i<<endl;
		return dp[i];
	}
}

int main()
{
	int n;
	cin>>n;
	tree.resize(n+1);
	dp.resize(n+1);
	vector<int> is_root(n+1,0);
	int temp;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		if(temp>0)	
			tree[temp].push_back(i);
		else
			is_root[i]=1;
	}
	int height=0;
	for(int i=1;i<=n;i++)
	{
		if(is_root[i]==1)
		{
			//cout<<depth(i)<<" "<<i<<endl;
			height = max(height, depth(i));
		}
	}
	cout<<height<<endl;
	return 0;
}