#include <iostream>
#include <vector>
using namespace std;
int lucky(int n)
{
	int digits;
	while(n!=0)
	{
		digits=n%10;
		n=n/10;
		if(digits==4||digits==7)
			continue;
		else
			return 1;
	}
	return 0;
}
int main()
{
	int n,num;
	cin>>n;
	if(lucky(n)==0)
		cout<<"YES"<<endl;
	else
	{
		for(int i=2;i<n/2;i++)
		{
			if(n%i==0)
			{
				num=n/i;
				//cout<<num<<endl;
				if(lucky(num)==0)
				{
					cout<<"YES"<<endl;
					return 0;
				}
				else
					continue;
			}
		}
		cout<<"NO"<<endl;
	}
	return 0;
}