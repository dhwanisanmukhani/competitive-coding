#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n, k;
	icin(n), icin(k);
	int arr[n];
	for(int i=0;i<n;i++){
		icin(arr[i]);
	}
	int left=0, right=0;
	int i=0;
	while(arr[i] <= k){
		left++;
		i++;
	}
	for(int j=n-1;j>=i;j--){
		if(arr[j] > k)
			break;
		right++;
	}
	printf("%d\n", left+right);
}