#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

bool visit(int stop, int i, int n)
{
	if(i<n)
	{
		if(i+a[i]==stop)
		{
			return true;
		}
		else
		{
			return visit(stop,i+a[i],n);
		}
	}
	else
		return false;
}

int main()
{
	int n;
	cin>>n;
	int stop;
	cin>>stop;
	a.resize(n);
	for(int i=1;i<=n-1;i++)
	{
		cin>>a[i];
	}
	if(visit(stop,1,n)==true)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}
