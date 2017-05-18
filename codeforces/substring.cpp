#include <iostream>
using namespace std;

int main()
{
	int l;
	string s;
	cin>>l;
	cin>>s;
	int sum[l];
	int64_t count=0;
	sum[0]=s[0]-'0';
	if(sum[0]%3==0)
	{
		count++;
		cout<<"yes"<<endl;
	}
	for(int i=1;i<l;i++)
	{
		sum[i]=sum[i-1]+(s[i]-'0');
		if(sum[i]%3==0)
		{
			count++;
			cout<<"no"<<endl;
		}
	}
	for(int i=2;i<=l;i++)
	{
		for(int j=1;j<i;j++)
		{
			if((sum[i-1]-sum[j-1])%3==0)
			{
				count++;
				cout<<j<<" "<<i<<endl;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}