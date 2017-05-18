#include <iostream>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int m;
	if(k<0)
		m=-k;
	else
		m=k;
	int dp[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			dp[i][j]=0;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		
	}
}