#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	int a1[s1.length()]={0},a2[s2.length()]={0};
	if((s1.length()+s2.length())!=s3.length())
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else
	{
		for(int i=0;i<s3.length();i++)
		{
			for(int j=0;j<s1.length();j++)
			{
				if(s3[i]==s1[j]&&a1[j]==0)
				{
					a1[j]=1;
					break;
				}
			}
			for(int k=0;k<s2.length();k++)
			{
				if(s3[i]==s2[k]&&a2[k]==0)
				{
					a2[k]=1;
					break;
				}
			}
		}
	}
	for(int j=0;j<s1.length();j++)
	{
		if(s1[j]==0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(int j=0;j<s2.length();j++)
	{
		if(s2[j]==0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}