#include <iostream>
#include <cstdio>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long LL;

LL power(LL b, LL e, LL mod)
{
	LL res = 1;
	while(e != 0)
	{
		if((e&1) == 1)
		{
			res *= b;
			res %= mod;
		}
		e = e >> 1;
		b *= b;
		b %= mod;
	}
	return res;
}

int main()
{
	int t;
	icin(t);
	for(int a = 0; a < t; a++)
	{
		int n, k, mod;
		icin(n), icin(k), icin(mod);
		if(n % k == 0)
			cout << n/k << "\t1" << endl;
		else
		{
			if(n <= 50 && k <= 50)
			{
				int m = (n/k);
				cout << m + 1 <<"\t";
				int r = n % k;
				int c[55][55];
				for(int i = 1; i < 55; i ++)
				{
					c[i][1] = i % mod;
					c[i][0] = 1 % mod;
					c[i][i] = 1 % mod;
					c[i][i-1] = i % mod;
				}
				for (int i = 3; i < 55; ++i)
				{
					for(int j = 2; j < i; j++)
					{
						c[i][j] = c[i-1][j] + c[i-1][j-1];
						c[i][j] %= mod;
					}
				}
				cout<<c[m+k-r][k-r]<<endl;
			}
			else
			{
				int m = (n/k);
				int r = n % k;
				LL fac = 1;
				int temp = m + k - r;
				while(temp != 1)
				{
					fac *= temp;
					fac = fac % mod;
					temp--;
				}
				LL fac_k_r[k-r+10];
				fac_k_r[1] = 1;
				for(int i = 2; i <= k-r; i++)
				{
					fac_k_r[i] = (fac_k_r[i-1] * power(i,mod-2, mod))%mod;
				}
				LL fac_m[m+10];
				fac_m[1] = 1;
				for(int i = 2; i <= m; i++)
				{
					fac_m[i] = (fac_m[i-1] * power(i,mod-2, mod))%mod;
				}
				cout<< (n/k) + 1 << "\t" << (fac_k_r[k-r] * fac * fac_m[m]) % mod <<endl;
			}
		}
	}
}