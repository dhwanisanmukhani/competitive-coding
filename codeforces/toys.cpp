#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int w=0; w<t; w++)
	{
		int rd,gr,bl;
		int64_t p,q,r,s;
		cin >> rd >> gr >> bl;
		cin >> p >> q >> r >> s;
		
		int64_t profit = 0;
		int remgr, remrd, rembl;
		int64_t sum = 0;
		for(int x=0; x<=rd; x++)
		{
			for(int y=0; y<=min(gr-x,bl); y++)
			{
				remrd= rd-x;
				remgr= gr-x-y;
				rembl= bl-y;
				if(r >(3*s))
				{
					sum= (r * min(min(rembl,remgr),remrd) ) + (x * p) + (y * q);
					int temp = min(min(rembl,remgr),remrd);
					remrd -= temp;
					remgr -= temp;
					rembl -= temp;
					cout<<sum<<endl;
					sum += (remrd + rembl + remgr) * s;
					cout<<sum<<endl;
					profit = max(profit,sum);
				}
				else
				{
					sum= (x * p) + (y * q) + ((remrd + rembl + remgr) * s);
					cout<<sum<<endl;
					profit = max(profit,sum);
				}
			}
		}
		cout << profit << endl;
	}
	return 0;
}