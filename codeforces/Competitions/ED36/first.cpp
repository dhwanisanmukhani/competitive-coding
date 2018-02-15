#include <iostream>
#include <cstdio>
using namespace std;
#define icin(x) scanf("%d", &x)

int main(){
	int n, k;
	icin(n), icin(k);
	int arr[n];
	for(int i=0;i<n;i++){
		icin(arr[i]);
	}
	sort(arr, arr+n);
	for(int i=n-1;i>=0;i--){
		if(k%arr[i] == 0){
			printf("%d\n", k/arr[i]);
			break;
		}
	}
}