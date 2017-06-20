#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
long long csize = 0;
 
int check(long long sum, long long num){
	if((sum+num)*(csize+1) <(sum*csize)+num)
		return -1;
	else
		return 0;
}
 
int main(){
	int t;
	icin(t);
	for(int s=0;s<t;s++){
		int n;
		icin(n);
		long long arr[n];
		long long sum=0;
		long long final=0;
		csize=0;
		for(int i=0;i<n;i++){
			lcin(arr[i]);
		}
		sort(arr, arr+n);
		int flag = -1;
		for(int i=n-1;i>=0;i--){
			if(check(sum, arr[i]) == -1){
				flag = i;
				break;
			}
			sum+=arr[i];
			csize++;
		}
		if(flag != -1){
			for(int i=flag;i>=0;i--){
				final+=arr[i];
			}
		}
		final += sum*csize;
		printf("%lld\n", final);
	}
} 
