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
			if(a[i-1]<a[i])
			{
				dp[i]=1+dp[i-1];
			}
			else 
			{
				dp[i]=1;
			}
		}
		sort(dp,dp+n);
		cout<<dp[n-1]<<endl;;
		return 0;
}