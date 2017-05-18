#include <iostream>
using namespace std;
int main()
{
	int m,n,d,t=0;
	cin>>m>>n;
	while(m>=n)
	{
		d=m/n;
		m=d+(m%n);
		t=t+d*n;
		//cout<<m<<endl;	
	}
	cout<<t+m<<endl;
	return 0;
}