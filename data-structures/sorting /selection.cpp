#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int minimum_i=0;
	for(int i=0;i<n-1;i++)
	{
		int minimum=arr[i];
		for(int j=i+1;j<n;j++)
		{
			if(minimum>arr[j])
			{
				minimum=arr[j];
				minimum_i=j;
			}
		}
		if(minimum_i!=i)
		{
			int temp=arr[minimum_i];
			arr[minimum_i]=arr[i];
			arr[i]=temp;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}