#include <iostream>
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
	int j,value;
	for(int i=1;i<n;i++)
	{
		value=arr[i];
		j=i;
		while(j>0 && arr[j-1]>value)
		{
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=value;
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}