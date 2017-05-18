#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	string words;
	cin>>n;
	std::vector<string> v;
	for(int i=1;i<=n;i++)
	{	
		cin>>words;
		v.push_back(words);
	}	
	for(int i=0;i<n;i++)
	{
		if (v[i].size()<=10)
		{
			cout<<v[i]<<endl;
		}
		else
		{
			cout<<v[i][0]<<v[i].size()-2<<v[i][v[i].size()-1]<<endl;
		}
	}
	return 0;
}