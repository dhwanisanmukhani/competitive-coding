#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define icin(x) scanf("%d", &x)
typedef long long ll;

int main(){
	int n, a, b;
	icin(n), icin(a), icin(b);
	int p[n];
	a=min(a, b);
	if(a==1){
		for(int i=1;i<n;i++)
			printf("%d ",i );
	}
	int t=(a);
	for(int i=n;i>0;i--){
		p[t%n] = i;
		t++;
	}
	for(int i=0;i<n;i++){
		printf("%d ", p[i]);
	}
}