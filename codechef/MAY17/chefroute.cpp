#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		string s;
		cin>>s;
		char next;
		int flag = 0;
		for(int j = 0; j < s.length() - 1; j++)
		{
			next = s[j+1];
			if(s[j] == 'E')
			{
				if(next == 'C')
				{
					cout<<"no"<<endl;
					flag = 1;
					break;
				}
			}
			else if(s[j] == 'S')
			{
				if(next == 'C' || next == 'E')
				{
					cout<<"no"<<endl;
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0)
		{
			cout<<"yes"<<endl;
		}
	}
}