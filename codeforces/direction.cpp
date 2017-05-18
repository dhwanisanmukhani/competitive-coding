#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int dist=0;
	string dir;
	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp>>dir;
		if(dist%20000==0 && (dir!="North" && dir!="South"))
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(dir=="North")
		{
			dist-=temp;
		}
		if(dir=="South")
		{
			dist+=temp;
		}
		if(dist>20000 || dist<0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if(dist==0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}