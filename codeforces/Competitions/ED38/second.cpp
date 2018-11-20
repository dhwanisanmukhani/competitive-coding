#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n;
	icin(n);
	int arr[n];
	int mmax = -1;
	for(int i=0;i<n;i++){
		icin(arr[i]);
		mmax = max(arr[i], mmax);
	}
	if(mmax <= 500000){
		printf("%d\n", arr[n-1]-1);
	}
	else{
		int idx;
		for(int i=0;i<n;i++){
			if(arr[i]>500000){
				idx=i;
				break;
			}
		}
		if(idx == 0)
			printf("%d\n", 1000000-arr[idx]);
		else
			printf("%d\n", max(arr[idx-1]-1, 1000000-arr[idx]));
	}
}