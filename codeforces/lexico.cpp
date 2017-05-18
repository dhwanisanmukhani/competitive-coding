#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int i,a,b;
	string l,g,s1,s2;
	cin>>s1>>s2;
	for(i=0;s1[i]!='\0';i++)
	{
		s1[i]=tolower(s1[i]);
	}
	for(i=0;s2[i]!='\0';i++)
	{
		s2[i]=tolower(s2[i]);
	}
	for(i=0;i<max(s2.size(),s1.size());i++)
	{
		if(s1[i]>s2[i])
		{
			cout <<"1"<<endl;
			return 0;
		}
		else if(s1[i]<s2[i])
		{
			cout<<"-1"<<endl;
			return 0;
		}
		else 
			continue;
	}	
	cout<<"0"<<endl;	
	return 0;
}