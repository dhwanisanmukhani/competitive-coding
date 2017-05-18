#include <iostream>
using namespace std;
 
int main()
{
	int n;
	cin>>n;
	int arr[n];
	int f=1,l=1;
	int k=0;
	int64_t sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]!=0)
		{
			k++;
		}
		sum+=arr[i];
	}
	if(sum!=0)
	{
		cout<<"YES"<<endl;
		cout<<"1"<<endl;
		cout<<"1 "<<n<<endl;
		return 0;
	}
	if(sum==0)
	{
	if(k>1)		
	{
		cout<<"YES"<<endl;
		cout<<"2"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
		return 0;
	}

	for(int i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			cout<<"1 "<<i+1<<endl;
			cout<<i+2<<" "<<n<<endl;
			return 0;
		}
	}
}
	return 0;
}