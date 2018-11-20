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

ll gcd(ll a, ll b){
	// int d=0;
	// while((a%2==0)&&(b%2==0)){
	// 	a /= 2;
	// 	b /= 2;
	// 	d++;
	// }
	// while(a != b){
	// 	if(a%2==0)
	// 		a /= 2;
	// 	else if(b%2 == 0)
	// 		b /= 2;
	// 	else if(a>b)
	// 		a = (a-b)/2;
	// 	else
	// 		b= (b-a)/2;
	// } 
	// return (a>>d);
	if(a==0)
		return b;
	return gcd(b%a, a);
}

int main(){
	ll l, r, a, b;
	lcin(l), lcin(r), lcin(a), lcin(b);
	ll ab= a*b;
	int count=0;
	ll local = sqrt(ab);
	for(ll i=l; i<=min(local, r); i++){
		if(ab%i == 0){
			ll x = min(i, ab/i);
			ll y = max(i, ab/i);
			if(gcd(x, y) == a){
				if(x == y)
					count++;
				else
					count += 2;
			}
		}
	}
	printf("%d\n", count);
}