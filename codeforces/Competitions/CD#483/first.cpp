#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)

int main(){
	int n;
	icin(n);
	int arr[n];
	for(int i=0;i<n;i++){
		icin(arr[i]);
	}
	sort(arr, arr+n);
	if(n==1){
		printf("%d\n", arr[0]);
		return 0;
	}
	if(n%2 != 0){
		printf("%d\n", arr[n/2]);
	}
	else{
		printf("%d\n",arr[(n/2) - 1]);
	}
}