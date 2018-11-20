#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n, k;
	ll l;
	icin(n), icin(k);
	lcin(l);
	int m=n*k;
	ll length[m];
	for(int i=0;i<m;i++){
		lcin(length[i]);
	}
	sort(length, length+m);
	int idx;
	for(int i=m-1;i>=0;i--){
		if(length[i] - length[0] <= l){
			idx = i;
			break;
		}
	}
	if(idx+1 < n){
		printf("0\n");
		return 0;
	}
	ll volume=0;
	int count = (idx+1)/k;
	if(((idx+1)/k + (idx+1)%k) >= n){
		int i=0;
		for (int j = 0; j < count; j++){
			volume += length[i];
			i+=k;
		}
		if(count < n){
			while(count != n-1){
				volume += length[idx--];
				count++;
			}
			if((idx+1)/k >= 1)
				volume += length[(((idx+1)/k)-1)*k];
			else
				volume += length[0];
		}
		printf("%lld\n", volume);
		return 0;
	}
	count--;
	int i=0;
	for(int j=0;j<count;j++){
		volume += length[i];
		i+=k;
	}
	while(count != n-1){
		volume += length[idx--];
		count++;
	}
	if((idx+1)/k >= 1)
		volume += length[(((idx+1)/k)-1)*k];
	else
		volume += length[0];
	printf("%lld\n", volume);
}
