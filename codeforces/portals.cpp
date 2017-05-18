#include <iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n-1;i++)
	{
		cin>>arr[i];
	}
	int cell[n+1]={0};
	cell[1]=1;
	int i=1,j,sum=0;
	while(i<n)
	{
		i=i+arr[i-1];
		cell[i]=1;
	}
	if(cell[k]==1)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}