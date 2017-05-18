#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int dp[n]={1},a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int k=0;k<i;k++)
		{
			if(a[k]<a[i])
				dp[i]=max(dp[i],1+dp[k]);
			else 
				continue;
		}	
		//cout<<dp[i]<<endl;
	}
	sort(dp,dp+n);
	cout<<dp[n-1]<<endl;
	return 0 ;
}
