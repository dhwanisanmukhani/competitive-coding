#include <iostream>
#include <inttypes.h>
using namespace std;
int lucky(int n)
{
	int digits;
	if(n==0)
		return 1;
	while(n!=0)
	{
		digits=n%10;
		n=n/10;
		if(digits==4||digits==7)
			continue;
		else
			return 1;
	}
	return 0;
}

int main()
{
	int64_t n;
	cin>>n;
	int digit,num=0;
	while(n!=0)
	{
		digit=n%10;
		n=n/10;
		if(digit==4||digit==7)
			num++;
	}
	if(lucky(num)==0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;

}