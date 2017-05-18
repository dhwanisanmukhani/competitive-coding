#include <iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	string ts="hello";
	int a=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==ts[a])
		{
			a++;
			if(a==5)
			{
				cout<<"YES"<<endl;
				return 0;
			}		
		}
		else
			continue;

	}
	cout<<"NO"<<endl;
	return 0;
}

