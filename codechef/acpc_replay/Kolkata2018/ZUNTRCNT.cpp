#include <iostream>
#include <cstdio>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int t;
	icin(t);
	for(int a=1;a<=t;a++){
		ll l, k;
		lcin(l), lcin(k);
		ll n = (l+1)-k;
		ll sum = (n*(n+1))/2;
		if(k<=l)
			printf("Case %d: %lld\n", a, sum);
		else
			printf("Case %d: 0\n", a);
	}
}