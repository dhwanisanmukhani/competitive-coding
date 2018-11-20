#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

ll digit(vector<ll> d, ll num){
	int n=d.size();
	n--;
	while(n >= 0){
		//printf("hey\n");
		if(d[n]%2 != 0)
			break;;
		n--;
	}
	if(n < 0)
		return num;
	else{
		ll small = 0, large=0;
		int i;
		for(i=d.size()-1;i>n;i--){
			small *= 10;
			small += d[i];
		}
		large = small;
		small *= 10;
		small += d[i]-1;
		large *= 10;
		large += d[i]+1;
		i--;
		while(i>=0){
			small *= 10;
			small += 8;
			large *= 10;
			i--;
		}
		small = num - small;
		large = large - num;
		if(small > large)
			return large;
		else
			return small;
	}
}

int main(){
	int t;
	icin(t);
	for(int x=1;x<=t;x++){
		ll n;
		lcin(n);
		ll num = n;
		vector<ll> digits;
		while(n != 0){
			digits.push_back(n%10);
			n /= 10;
		}
		ll ret = digit(digits, num);
		printf("Case #%d: %lld\n", x, ret);
	}
}
