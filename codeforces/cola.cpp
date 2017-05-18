#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a;
	int sum=0,i=1;
	while(sum<n)
	{
		sum=sum+5*i;
	//	cout<<sum<<endl;
		i=i*2;
	}
	//cout<<i<<endl;
	i=i/2;
	sum=sum-5*i;
	//i=i*2;
	//cout<<n-sum<<'\t'<<i<<endl;
	char names[5][20]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
	if((n-sum)%i==0)
	{
		a=(n-sum)/i;
	//	cout<<a<<endl;
		cout<<names[a-1]<<endl;
	}	
	else
	{
		a=((n-sum)/i)+1;
	//	cout<<a<<endl;
		cout<<names[a-1]<<endl;
	}
	return 0;
}