#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j)
	{
		int n;
		cin>>n;
		int a[(2*n)+1];
		for(int i = 1; i <= (2*n); i++)
		{
			cin >> a[i];
		}
		sort(a + 1, a + (2*n) + 1);
		// for (int i = 0; i < 2*n; ++i)
		// {
		// 	cout<<a[i+1]<<endl;
		// }
		if(n%2 == 0 && (n/2) >= 1)
		{
			int mean = a[(2*n) - (n/2)] + a[(2*n) - (n/2) + 1];
			cout<< mean/2 <<endl;
		}
		else
		{
			cout << a[(2*n) - (n)/2] << endl;
		}
		for(int i = 1; i <= n; i++)
		{
			cout << a[i] << " " << a[n + i] <<" ";
		}
		cout<<endl;
	}
}