#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v ;

void binary_search(int val,int l,int r)
{
	if(l==r)
	{
		return l;
	}
	int mid=(l+r)>>1;
	if(val>=v[mid])
	{
		return binary_search(val,mid+1,r);
	}
	else
	{
		return binary_search(val,l,mid);
	}
}

int main()
{
	int n;
	cin>>n;
	v.resize(n+2);
	for(int i=0;i<n;i++)
	{
	    cin>>v[i];
	}
	v[n]=0;
	v[n+1]=1e9;
	sort(v.begin(),v.end());
	int days;
	cin>>days;
	int val;
	for(int i=0;i<days;i++)
	{
		cin>>val;
		cout<<binary_search(val,0,n+1)-1<<endl;
	}
	return 0;
}


