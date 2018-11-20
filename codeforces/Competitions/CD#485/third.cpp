#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

ll count(ll* sz, ll* cost, int n){
	vector<vector<ll> > dp(n, vector<ll>(n, 0));
	for(int i=0;i<n;i++){
		dp[0][i] = cost[i];
	}
	for(int l=1;l<3;l++){
		for(int i=l;i<n;i++){
			dp[l][i]=-1;
			ll x=1e9;
			for(int j=l-1;j<i;j++){
				if(sz[j] < sz[i])
					x=min(x, dp[l-1][j]);
			}
			dp[l][i] = (x + cost[i]);
		}
	}
	ll mini = dp[2][2];
	for(int i=2;i<n;i++){
		mini = min(mini, dp[2][i]);
	}
	return mini;
}

int main(){
	int n;
	icin(n);
	ll sz[n], cost[n];
	for(int i=0;i<n;i++){
		lcin(sz[i]);
	}
	for(int i=0;i<n;i++){
		lcin(cost[i]);
	}
	ll sum = count(sz, cost, n);
	if(sum >= 1e9)
		printf("-1\n");
	else
		printf("%lld\n", sum);
}