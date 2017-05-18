#include <iostream>
using namespace std;
int main()
{
	int n,count=0;
	cin>>n;
	int arr[n+1]={0};
	arr[0]=0;
	int p,q;
	cin>>p;
	int x[p];
	for(int i=0;i<p;i++)
	{
		cin>>x[i];
		for(int j=1;j<=n;j++)
		{
			if(j==x[i])
			{
				arr[j]=1;
			}
		}
	}
	cin>>q;
	int y[q];
	for(int i=0;i<q;i++)
	{
		cin>>y[i];
		for(int j=1;j<=n;j++)
		{
			if(j==y[i])
			{
				arr[j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(arr[i]==0)
			count++;
	}
	if(count==0)
		cout<<"I become the guy."<<endl;
	else
		cout<<"Oh, my keyboard!"<<endl;
	return 0;
}