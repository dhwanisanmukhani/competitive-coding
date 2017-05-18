#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,i,value,attempted=0;
	std::vector<int> values;
	cin>>n;
	for(i=1;i<=3*n;i++)
	{
		cin>>value;
		values.push_back(value);
	}
	for(i=0;i<3*n;i=i+3)
	{
		if((values[i]+values[i+1]+values[i+2])>=2)
		{
			attempted++;
		}
	}
	cout<<attempted<<endl;
	return 0;
}