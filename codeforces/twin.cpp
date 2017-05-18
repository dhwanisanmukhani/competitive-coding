#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int csum=0,sum=0,count=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		csum=csum+a[i];
	}
	for(int i=n-1;i>=0;i--)
	{
		count++;
		sum=sum+a[i];
		csum=csum-a[i];
		if(sum>csum)
		{
			cout<<count<<endl;
			return 0;
		}
	}
	return 0;
}
