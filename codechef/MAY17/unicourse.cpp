#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int j = 0; j < t; j++)
	{
		int n;
		cin>>n;
		int max = 0;
		for(int i = 0; i < n; i++)
		{
			int temp;
			cin>>temp;
			if(temp > max)
				max = temp;
		}
		cout << n - max << endl;
	}
}