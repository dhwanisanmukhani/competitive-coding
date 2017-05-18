#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a,int b)
{
	int m=min(a,b);
	for(int i=m;i>=2;i--)
	{
		if(a%i==0&&b%i==0)
			return i;
	}
	return 1;
}

int main()
{
	int a,b,n,chance=0;
	cin>>a>>b>>n;
	while(n>=0)
	{
		if(chance%2==0)
		{
			int taken=gcd(a,n);
			n=n-taken;
		}
		else
		{
			int taken=gcd(b,n);
			n=n-taken;
		}
		chance++;
	}	
	if(chance%2==0)
		cout<<"0"<<endl;
	else
		cout<<"1"<<endl;
	//cout<<chance<<endl;
}