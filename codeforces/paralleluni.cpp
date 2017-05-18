#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > v(1e4+1, vector<int>(2,0));

int main()
{
	int n, m, k;
	cin >> n>> m;
	char flag;
	for (int i = 0; i < m; ++i)
	{
		flag = 'y';
		cin >>k;
		for (int j = 0; j < k; ++j)
		{
			int num;
			cin >>num;
			if(num > 0)
				v[num][1] = 1;
			else
				v[-num][0] = 1;
		}
		for (int l = 0; l <= n; l++)
		{
			if(v[l][0] == 1)
			{
				if(v[l][1] == 1)
				{
					flag = 'n';
				}
			}
			v[l][0] = 0;
			v[l][1] = 0;
		}
		if(flag == 'y')
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}