#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
#define icin(x) scanf("%d", &x);
#define lcin(x) scanf("%lld", &x);
typedef long long ll;
long long m=1000000007;

int main(){
	int t;
	icin(t);
	while(t--){
		string s;
		cin >> s;
		ll p = 36-s.length();
		ll ans=1;
		for(ll i=1;i<=p;i++){
			ans = ((ans%m)*(i%m))%(m);
		}
		printf("%lld\n", ans);
	}
}