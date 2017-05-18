#include <iostream>
#include <inttypes.h>
using namespace std;
int main()
{
	int64_t n,k,num;
	cin>>n>>k;
	if(k<=n/2)
	{

		num=2*k-1;
		cout<<num<<endl;
	}
	else
	{
		num=(k-(n+1)/2)*2;
		cout<<num<<endl;
	}
	return 0;
}