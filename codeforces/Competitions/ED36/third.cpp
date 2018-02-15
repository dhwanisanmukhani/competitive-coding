#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

bool myfunc(char a, char b){
	return a>b;
}

int main(){
	ll a, b;
	lcin(a), lcin(b);
	ll temp=a;
	int len=0;
	vector<ll> v(10, 0);
	while(temp>0){
		len++;
		v[temp%10]++;
		temp /=10;
	}
	ll mid_max=0, mid_min=0, mid=0;
	for(int i=0;i<len;i++){
		for(ll j=9;j>=0;j--){
			if(v[j]==0)
				continue;
			mid_max = mid_min = mid;
			mid *= 10;
			mid += j;
			mid_max = mid_min = mid;
			v[j]--;
			for(ll k=9;k>=0;k--){
				for(int m=0;m<v[k];m++){
					mid_max *=10;
					mid_max +=k;
				}
			}
			for(ll k=0;k<=9;k++){
				for(int m=0;m<v[k];m++){
					mid_min *= 10;
					mid_min += k;
				}
			}
			if(b>=mid_min)
				break;
			else{
				mid/=10;
				v[j]++;
			}
		}
	}
	printf("%lld\n", mid);
}