#include <iostream>
using namespace std;
int main()
{
	int n,count=0;
	cin>>n;
	string s;
	cin>>s;
	int arr[n]={0};
	for(int i=0;i<n;i++)
	{
		if(arr[i]==-1)
		{
			continue;
		}
		else if(s[i]=='B')
		{
			int j=i+1;
			while(s[j]=='B')
			{
				arr[i]++;
				arr[j]=-1;
				j++;
			}
			count++;
		}
		else
		{
			arr[i]=-1;
		}
	}
	cout<<count<<endl;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>=0)
		{
			cout<<arr[i]+1<<" ";
		}
	}

}