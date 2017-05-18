#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int count=0;
	for(int i=5;i>=1;i--)
	{
		while(n>=i)
		{
			n=n-i;
			count++;
		}
	}
	cout<<count<<endl;
}