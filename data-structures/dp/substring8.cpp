#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int w=0;w<t;w++)
	{
		int l;
		cin>>l;
		string s;
		cin>>s;
		int64_t sum,count=0;
		int dp[l][3];
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<3;j++)
			{
				dp[i][j]=0;
			}
		}
		dp[0][(s[0]-'0')%3]++;
		int m;
		for(int i=1;i<l;i++)
		{
			m = (s[i]-'0') % 3;
			dp[i][m] = dp[i-1][0]+1;
			dp[i][(m+1)%3] = dp[i-1][1];
			dp[i][(m+2)%3] = dp[i-1][2];
		}
		for(int i=0;i<l-2;i++)        
		{
			sum=(s[i]-'0')*(100) + (s[i+1]-'0')*(10) + (s[i+2]-'0');        //strings ending at i+2 divisible at 8
			if(sum % 8 == 0)  
			{
				for(int x=0;x<3;x++)
				{
					if((x + (s[i+1]-'0') + (s[i+2]-'0')) % 3 != 0)
					{	
						count+=dp[i][x];
						//cout<<"yeh "<<count<<endl;
					}
				}
			}
		}
		for(int i=0;i<l-1;i++)
		{
			sum=(s[i]-'0')*(10) + (s[i+1]-'0');   //double digit substring
			if(sum % 8 == 0 && ((s[i]-'0') + (s[i+1]-'0')) % 3 != 0 )
			{
				count++;
				//cout<<"2 "<<count<<endl;
			}
			if((s[i]-'0') % 8 == 0 && (s[i]-'0') % 3 != 0)            //single digit substring
			{
				count++;
				//cout<<"single "<<count<<endl;
			}
		}
		if((s[l-1] -'0') % 8 == 0 && (s[l-1] -'0') % 3 != 0)            
		{
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
