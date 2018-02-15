#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define icin scanf("%d", &x)
int main() {
	int t;
	icin(t);
	while(t--){
		int n, k;
		icin(n), icin(k) ;
		int arr[n] ;
		for(int i=0;i<n;i++){
			icin(arr[i]) ;
		}
		
		// int idx=-1, fsum+0;
		// for(int i=0;i<n;i++) {
		// 	if (arr[i] <0)
		// 		break;
		// 	fsum +=arr[i] ;
		// 	idx =i;
		// } 
		// if (idx==n-1){
		// 	if(k>1)
		// 		printf("%d\n",k* fsum);
		// 	else
		// 		printf("%d\n",fsum);
		// 	continue;
		// }
		// int nsum=-1, temp=0;
		// for(int i =idx+1;i<n;i++){
		// 	if (arr[i] <0){
		// 		nsum =max(nsum, temp);
		// 		temp=0;
		// 		continue;
		// 	}
		// 	else
		// 		temp +=arr[i] ;
		// }
		// int lsum =0;
		// if (temp >0)
		// 	lsum=temp;
		// if(k>1)
		// 	printf("%d\n", max(lsum+fsum, nsum)) ;
		// else
		// 	printf("%d\n", max(max(lsum,fsum), nsum)) ;
	} 
} 
