#include <iostream>
using namespace std;
bool presence(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='H'||s[i]=='Q'||s[i]=='9')	
			return 1;
		else 
			continue;
	}
	return 0;
}
int main()
{
	string s;
	cin>>s;
	if(presence(s)==1)
		cout<<"YES"<<endl;
	else
		cout <<"NO"<<endl;
	return 0;
}