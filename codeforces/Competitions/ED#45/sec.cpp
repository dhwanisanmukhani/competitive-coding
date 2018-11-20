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
	int n, k;
	icin(n), icin(k);
	int sz[n];
	for(int i=0;i<n;i++){
		icin(sz[i]);
	}
	sort(sz, sz+n);
	int count=n;
	int prev=1;
	for(int i=1;i<n;i++){
		if(sz[i] > sz[i-1]){
			if(sz[i] <= sz[i-1]+k)
				count -= prev;
			prev = 1;
		}
		if(sz[i] == sz[i-1]){
			prev++;
		}
	}
	printf("%d\n", count);
}