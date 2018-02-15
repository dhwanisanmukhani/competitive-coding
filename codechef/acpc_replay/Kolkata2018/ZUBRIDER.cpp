#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;
ll mod=1000000007;

int main(){
	int t;
	icin(t);
	for(int a=1;a<=t;a++){
		ll kp, ks, n;
		lcin(kp), lcin(ks), lcin(n);
		ll g[n], s[n];
		for(int i=0;i<n;i++){
			lcin(g[i]);
		}
		for(int i=0;i<n;i++){
			lcin(s[i]);
		}
		sort(g, g+n);
		sort(s, s+n);
		ll kmin = kp*ks;
		vector<ll> dp(n, 0);
		int idx=0;
		ll temp=0;
		for(int i=n-1;i>=0;i--){
			temp = g[idx]*s[i];
			if(temp > kmin)
				dp[idx]++;
			else{
				while(temp <= kmin){
					idx++;
					dp[idx]=dp[idx-1];
					temp = g[idx]*s[i];
				}
				dp[idx]++;
			}
		}
		if(idx != n-1){
			for(int i=idx;i<n;i++){
				dp[i]=dp[idx];
			}
		}
		// for(int i=0;i<n;i++){
		// 	cout<<g[i]<<dp[i]<<endl;
		// }
		ll arrangements=1;
		for(int i=0;i<n;i++){
			arrangements = ((arrangements%mod)*((dp[i]-i)%mod))%mod;
		}
		printf("Case %d: %lld\n", a, arrangements);
	}
}

