#include <iostream>
using namespace std;

int main()
{
	int n,answer=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if (s=="++X"||s=="X++")
		{
			answer++;
		}
		else
		{
			answer--;
		}
	}
	cout<<answer<<endl;
	return 0;
}