#include <iostream>
using namespace std;
bool condition(string s)
{
	for(int i=1;i<s.length();i++)
		if(s[i]>='A'&&s[i]<='Z')
		{
			continue;
		}
		else
		{
			return 1;
		}
	return 0;	
}
int main()
{
	string s;
	cin>>s;
	if(condition(s)==0)
		{
			if(s[0]>='a'&&s[0]<='z')
			{
				s[0]=toupper(s[0]);
			}
			else
			{
				s[0]=tolower(s[0]);
			}
			for(int i=1;i<s.length();i++)
			{
				s[i]=tolower(s[i]);
			}
		}
	cout<<s<<endl;
	return 0;	
}
