#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=0,w=0;
	char words[100][300]={'\0'};
	
	for(int i=0;i<s.length();)
	{
		if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B')
		{
			i=i+3;
			n++;
			w=0;
		}
		else
		{
			words[n][w++]=s[i];
			words[n][w]='\0';
			i++;
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(strlen(words[i])!=0)
		{
			printf("%s ",words[i]);
		}
		else 
			continue;
	}
	return 0;
}