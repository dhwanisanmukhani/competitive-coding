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
	int a, b, c, n;
	icin(a), icin(b), icin(c), icin(n);
	if(c > a || c > b){
		printf("-1\n");
		return 0;
	}
	int left = n-(a+b-c);
	if(left < 1)
		printf("-1\n");
	else
		printf("%d\n", left);
}