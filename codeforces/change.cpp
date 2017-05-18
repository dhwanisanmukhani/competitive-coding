#include <iostream>
#include <string>
using namespace std;
int main()
{
	string word;
	cin>>word;
	int scount=0,ucount=0,num;
	for(int i=0;i<word.length();i++)
	{
		num=word[i];
		if(num>96&&num<123)
		{
			word[i]=word[i]-32;
			scount++;
		}
		else
		{
			ucount++;	
		}
	}
	if(scount>=ucount)
	{
		for(int i=0;i<word.length();i++)
		{
			word[i]=word[i]+32;
			cout<<word[i];
		}
	}
	else
	{
		cout<<word<<endl;
	}
	return 0;
}