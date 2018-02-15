#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define icin(x) scanf("%d", &x);
#define lcin(x) scanf("%lld", &x);
typedef long long ll;

int main(){
	ll n, L;
	lcin(n);
	lcin(L);
	ll arr[n];
	for(int i=0;i<n;i++){
		lcin(arr[i]);
	}
	vector<ll> dp(n, 1e18);
	dp[0] = arr[0];
	for(int i=1;i<n;i++){
		dp[i] = min(arr[i], 2*dp[i-1]);
	}
	ll ans=1e18, sum=0;
	for(int i=n-1;i>=0;i--){
		ll need = L/(1<<i);
		sum += need*(dp[i]);
		L -= need*(1<<i);
		if(L>0)
			ans = min(ans, sum + dp[i]);
		else
			ans = min(ans, sum);
	}
	printf("%lld\n", ans);
}