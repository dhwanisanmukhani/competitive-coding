#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<string> names;
	vector<int> visit;
	string s;
	for(int i=0;i<2;i++)
	{
		cin>>s;
		names.push_back(s);
		visit.push_back(0);
	}
	cout<<names[0]<<" "<<names[1]<<endl;
	int n;
	cin>>n;
	for(int j = 0; j < n ; j++)
	{
		cin>>s;
		for (int i = 0; i < names.size(); ++i)
		{	
			if(names[i] == s)
				visit[i]=1;
		}
		cin>>s;
		names.push_back(s);
		visit.push_back(0);
		for (int i = 0; i < names.size(); ++i)
		{
			if(visit[i] == 0)
				cout<<names[i]<<" ";
		}
		cout<<endl;
	}
}