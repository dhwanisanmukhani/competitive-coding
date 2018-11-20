#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	ll n, m, a, b;
	lcin(n), lcin(m), lcin(a), lcin(b);
	n = n%m;
	b = n*b;
	a = (m-n)*a;
	printf("%lld\n", min(a, b));
}