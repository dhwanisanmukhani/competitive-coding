#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	ll n;
	lcin(n);
	ll l=1, r=n;
	ll mid = (l+r)>>1;
	ll candies, sum;
	while(l!=r){
		ll k=mid;
		candies = n;
		sum=0;
		while(candies > 0){
			ll temp = min(candies, k);
			sum += temp;
			candies -= temp;
			candies -= (candies/10);
		}
		if(sum*2 >= n){
			r = mid;
			mid = (l+r)>>1;
		}
		else{
			l = mid+1;
			mid = (l+r)>>1;
		}
	}
	printf("%lld\n", mid);
}