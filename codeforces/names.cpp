#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3;
	s4=s1+s2;
	int a=s4.size();
	int b=s3.size();
	if(a!=b)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a-i-1;j++)
		{
			if(s4[j]>s4[j+1])
			{
				char ch;
				ch=s4[j];
				s4[j]=s4[j+1];
				s4[j+1]=ch;
			}
		}
	}
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<b-i-1;j++)
		{
			if(s3[j]>s3[j+1])
			{
				char ch;
				ch=s3[j];
				s3[j]=s3[j+1];
				s3[j+1]=ch;
			}
		}
	}
	for(int k=0;k<b;k++)
	{
		if(s4[k]!=s3[k])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}