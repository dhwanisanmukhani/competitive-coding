#include <iostream>
using namespace std;

int main()
{
	int l;
	cin>>l;
	string s;
	cin>>s;
	int dp[l][3];
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<3;j++)
		{
			dp[i][j]=0;
		}
	}
	dp[0][s[0]%3]++;
	int m;
	for(int i=1;i<l;i++)
	{
		m = (s[i]-'0') % 3;
		/*
		if m=0, f(i+1,0)=f(i,0)+1
				f(i+1,1)=f(i,1)
				f(i+1,2)=f(i,2)
		if m=1;
				f(i+1,0)=f(i,2);
				f(i+1,1)=f(i,0)+1;
				f(i+1,2)=f(i,1);
		if m=2;
				f(i+1,0)=f(i,1);
				f(i+1,1)=f(i,2);
				f(i+1,2)=f(i,0)+1;
		*/
		dp[i][m] = dp[i-1][0]+1;
		dp[i][(m+1)%3] = dp[i-1][1];
		dp[i][(m+2)%3] = dp[i-1][2];
	}
	int64_t count=0;
	for(int i=0;i<l;i++)
	{
		count+=dp[i][0];
	}
	cout<<count<<endl;
	return 0;
}