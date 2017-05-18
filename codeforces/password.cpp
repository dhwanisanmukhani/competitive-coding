#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
	int n,t=0,k,sum=0,m;
	cin>>n>>k;
	string s[n+1];
	int arr[n+1]={0};
	int csize[100]={0};
	int size[n+1];
	for(int i=0;i<n+1;i++)
	{
		cin>>s[i];
		size[i]=s[i].length();
		csize[s[i].length()]++;
	}
	sort(size,size+n+1);
	m=size[n];
	for(int i=0;i<size[n];i++)
	{
		sum=sum+csize[i];
	}
	for(int i=0;i<n+1;i++)
	{
		for(int j=i+1;j<n+1;j++)
		{
			if(s[i]==s[j])
			{
				arr[j]=-1;
				if(s[j].length()==m)
				{
					continue;
				}	
				else
				{
					sum=sum-1;
				}
			}
		}
	}

	for(int i=0;i<n+1;i++)
	{
		
		if(arr[i]==-1)
		{
			continue;
		}
		else 
		{
			t++;
		}
	}
	cout<<sum+1<<" "<<t+(((t-1)/k)*5)<<endl;
	return 0;
}