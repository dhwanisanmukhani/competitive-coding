#include <iostream>
using namespace std;
int main()
{
	int n;
	int sum=0;
	int change,division;
	int min_bound=-1e9;
	int max_bound=1e9;
	cin>>n;
	cin>>change>>division;
	if(n==1)
	{
		if(division==1)
			cout<<"Infinity"<<endl;
		else
			cout<<1899+change<<endl;
		return 0;
	}
	if(division==1)
		min_bound=1900;
	else
		max_bound=1899;
	for(int i=1;i<n;i++)
	{
		sum+=change;
		cin>>change>>division;
		if(division==1)
			min_bound=max(min_bound,1900-sum);
		else
			max_bound=min(max_bound,1899-sum);
		//cout<<sum<<endl;
	}
	sum+=change;
	if(max_bound<min_bound)
		cout<<"Impossible"<<endl;
	else
		if(max_bound>=1e9)
			cout<<"Infinity"<<endl;
		else
		{
			if((max_bound+sum)>1e9)
				cout<<"Infinity"<<endl;
			else
				cout<<max_bound+sum<<endl;
		}		
	return 0;
}