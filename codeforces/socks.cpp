#include <iostream>
using namespace std;
int main()
{
	int n,m,rem=1,sum=0;
	cin>>n>>m;
	sum=n;
	while(rem!=0)
	{
		rem=n/m;
		sum=sum+rem;
		n=rem+n%m;
	}

	cout<<sum<<endl;
} 