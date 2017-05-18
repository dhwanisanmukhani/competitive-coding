#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int s,m;
	cin>>s>>m;
	int arr[m][2];
	for(int i=0;i<m;i++)
	{
		cin>>arr[i][0]>>arr[i][1];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m-i-1;j++)
		{
			if(arr[j][0]>arr[j+1][0])
			{
				int temp1,temp2;
				temp1=arr[j][0];
				temp2=arr[j][1];
				arr[j][0]=arr[j+1][0];
				arr[j+1][0]=temp1;
				arr[j][1]=arr[j+1][1];
				arr[j+1][1]=temp2;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(s<=arr[i][0])
		{
			cout<<"NO"<<endl;
			return 0;
		}
		else
		{
			s=s+arr[i][1];
		}
	}
	cout<<"YES"<<endl;
	return 0;
}