#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define icin(x) scanf("%d", &x)
typedef long long ll;

int main(){
	int t;
	icin(t);
	while(t--){
		ll a, k;
		cin >> a >> k;
		ll x[3];
		for(int i=0;i<3;i++){
			cin >> x[i];
		}
		sort(x, x+3);
		ll area=0;
		if(x[2] - x[0] >= (2*k) + a){
			cout<<area<<endl;
			continue;
		}
		else{
			if(x[2]-x[0] <= (2*k))
				area = a*a;
			else{
				area = ((x[0] - x[2]) + (2*k) + a) * a;
			}
			printf("%lld\n",area);
		}
	}
}