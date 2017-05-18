#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int f=0;
	int n=s.length();
	std::vector<char> v(0);
	for(int i=0;i<n;i=i+2)
	{
		v.push_back(s[i]);
	}
	sort(v.begin(),v.end());
		for(int k=0;k<((n+1)/2-1);k++)
			cout<<v[k]<<"+";
		cout<<v[(n+1)/2-1]<<endl;

	return 0;
	
}