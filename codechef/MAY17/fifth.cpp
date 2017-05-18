#include <iostream>
#include <algorithm>
using namespace std;
long long a[31];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	// for (int i = 1; i <= n; ++i)
	// {
	// 	cout << a[i] << endl;
	// }
	int count = 0;
	int i = n;
	while(a[i] > k)
	{
		i--;
		count++;
	}
	temp = k;
	int rem = 1;
	while(rem != 0 && temp > 0)
	{
		rem = temp/a[i];
		temp = temp % a[i];
		i--;
		count++;
	}
	count--;
	
}