#include <iostream>
using namespace std;
int main()
{
	long long m,n,a;
	cin >>m>>n;
	a=m*n;
	if((m*n)%2==0)
	{
		cout<<a/2<<endl;
	}
	else
	{
		cout<<(a-1)/2<<endl;
	}
	return 0;
}