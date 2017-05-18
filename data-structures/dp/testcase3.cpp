#include <iostream>
using namespace std;

int main()
{
	int l;
	cin>>l;
	string s;
	cin>>s;
	int64_t count=0;
	for(int i=0;i<l;i++)
	{
		for(int j=i;j<l;j++)
		{
			int sum=0;
			for(int k=i;k<=j;k++)
			{
				sum+=s[k] - '0';
			}
			if(sum % 3 == 0)
			{
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}