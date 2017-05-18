#include <iostream>
using namespace std;
int main()
{
	string s1;
	int i,a=1;
	cin>>s1;
	for(i=0;i<s1.size()-1;i++)
	{
		if(s1[i]==s1[i+1])
		{
			++a;
			if(a>=7)
			{
				cout<<"YES"<<endl;
				return 0;
			}		
		}	
		else
		{
			a=1;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}