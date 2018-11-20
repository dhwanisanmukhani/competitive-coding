#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	ll n;
	lcin(n);
	if(n==0){
		printf("0\n");
		return 0;
	}
	if(n%2 == 0){
		printf("%lld\n", n+1);
	}
	else{
		printf("%lld\n", (n+1)/2);
	}
}