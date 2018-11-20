#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n, m;
	icin(n), icin(m);
	ll dorm[n+1];
	ll a[n];
	dorm[0] = 0;
	for(int i=0;i<n;i++){
		lcin(a[i]);
		dorm[i+1] = dorm[i] + a[i]; 
	}
	ll b[m];
	for(int i=0;i<m;i++){
		lcin(b[i]);
	}
	int prev_left = 1;
	for(int i=0;i<m;i++){
		int l = prev_left, r = n;
		int mid = (l+r)/2;
		while(l != r){
			//printf("%d\n", l);
			if(b[i] > dorm[mid]){
				l = mid+1;
				mid = (l+r)/2;
			}
			else{
				r = mid;
				mid = (l+r)/2;
			}
		}
		if(dorm[l] ==b[i]){
			printf("%d %lld\n",l, a[l-1]);
		}
		else{
			printf("%d %lld\n",l ,(b[i]-dorm[l-1]));
		}
		prev_left = l;
	}
}