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
		int n;
		icin(n);
		vector<int> cities(3);
		vector<int> type(1);
		vector<int> discount(3, -1);
		for(int i=0;i<n;i++){
			int c, t, d;
			icin(c), icin(t), icin(d);
			if(discount[t-1]<d){
				discount[t-1] = d;
				cities[t-1] = c;
			}
			else if(discount[t-1] == d){
				if(cities[t-1] > c)
					cities[t-1] = c;
			}
		}
		for(int i=0;i<3;i++){
			printf("%d %d\n", discount[i], cities[i]);
		}
	}
}