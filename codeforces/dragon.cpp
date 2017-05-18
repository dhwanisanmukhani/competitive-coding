#include <iostream>
using namespace std;
int main()
{
	int d,count=0;	
	int a[4];
	for(int i=0;i<4;i++)
	{
		cin>>a[i];
	}
	cin>>d;
	int arr[d+1]={0};
	for(int i=0;i<4;i++)
	{
		for(int j=a[i];j<=d;j=j+a[i])
		{
			if(arr[j]==0)
			{
				arr[j]=1;
			}
		}
	}
	for(int i=1;i<=d;i++)
	{
		if(arr[i]==1)
		{
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}