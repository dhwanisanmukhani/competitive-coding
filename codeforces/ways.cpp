#include <iostream>
#include <vector>
using namespace std;
int n;

long long count_ways(vector<long long>& a)
{
	long long count=0,s=0;
	if(a[n-1]%3!=0)
	{
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		if (a[i]==(2*a[n-1])/3)
		{
			count=count+s;
		}
		if(a[i]==a[n-1]/3)
		{
			s++;
		}
	}
	return count;
}

int main()
{
	cin>>n;
	vector<int> v;
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	if(n<3)
	{
		cout<<"0"<<endl;
		return 0;
	}
	vector<long long> a;
	a.resize(n);
	a[0]=v[0];
	for(int i=1;i<n;i++)
	{
		a[i]=v[i]+a[i-1];
	}
	cout<<count_ways(a)<<endl;
	return 0;
}