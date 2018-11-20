#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	ll n, k1, k2;
	lcin(n);
	lcin(k1), lcin(k2);
	ll a[n], b[n];
	ll diff[n];
	ll error=0, mean=0;
	ll k = k1+k2;
	priority_queue<ll> pq;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	for(int i=0;i<n;i++){
		diff[i] = a[i] - b[i];
		if(diff[i] < 0)
			diff[i]=diff[i]*(-1);
		if(diff[i]!=0)
			pq.push(diff[i]);
	}
	ll top;
	while(k > 0 && !pq.empty()){
		k--;
		top = pq.top();
		top--;
		pq.pop();
		if(top==0){
			continue;
		}
		pq.push(top);
	}
	k = k%2;
	if(!pq.empty()){
	    for(int i=0;i<n;i++){
		    top = pq.top();
		    pq.pop();
	    	error += top*top;
	    }
	}
	printf("%lld\n", error + k);
	return 0;
}