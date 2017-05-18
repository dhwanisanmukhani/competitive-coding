#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,amax,amin,t,p;
	cin>>n;
	int arr[n];
	amax=-1;
	amin=10000;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]>amax)
		{
			amax=arr[i];
			t=i;
		}
		if(arr[i]<=amin)
		{
			amin=arr[i];
			p=i;
		}
	}
	if(t>p)
		cout<<(n-p-1)+t-1<<endl;
	else
		cout<<(n-p-1)+t<<endl;

}