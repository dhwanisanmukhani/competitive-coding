#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	ll n, m;
	lcin(n), lcin(m);
	ll arr[n];
	vector<ll> count(m, 0);
	vector<pair<ll, ll> > change(m, make_pair(0, 0));
	for(int i=0;i<n;i++){
		lcin(arr[i]);
		count[arr[i]%m]++;
	}
	ll goal = n/m;
	for(int i=0;i<m;i++){
		if(count[i] > goal){
			change[i].second = (count[i]-goal);
			count[i+1] += (count[i]-goal);
			count[i] -= (count[i]-goal);
		}
		else if(count[i] < goal){
			change[i+1].first = (goal-count[i]);
			count[i+1] -= (goal-count[i]);
			count[i] += (goal-count[i]);
		}
	}
	ll corrections = 0;
	for(int i=0;i<m;i++){
		printf("%lld %lld\n", change[i].first, change[i].second);
		corrections += (change[i].first+change[i].second);
	}
	printf("%lld\n", corrections);
	for(int i=0;i<n;i++){
		ll rem = arr[i]%m;
		if(change[rem].first > 0){
			printf("%lld ", arr[i]-1);
			change[rem].first--;
		}
		else if(change[rem].second > 0){
			printf("%lld ", arr[i]+1);
			change[rem].second--;
		}
		else
			printf("%lld ", arr[i]);
	}
}