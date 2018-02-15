#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int t;
	icin(t);
	for(int x=0;x<t;x++){
		ll n, d, avg=0;
		lcin(n), lcin(d);
		ll arr[n+1];
		for(int i=1;i<=n;i++){
			lcin(arr[i]);
			avg += arr[i];
 		}
 		if(avg%n != 0){
 			printf("-1\n");
 			continue;
 		}
 		avg = avg/n;
 		int flag=0;
 		ll moves=0, rem=0;
 		for(int i=1;i<=d;i++){
 			rem=0;
 			for(int j=i;j<=n;j+=d){
 				if(rem > 0)
 					moves += rem;
 				else
 					moves -= rem;
 				arr[j] = arr[j]-rem;
 				rem = avg - arr[j];
 			}
 			if(rem != 0){
 				printf("-1\n");
 				flag = 1;
 				break;
 			}
 		}
 		if(flag ==0){
 			printf("%lld\n", moves);
 		}
	}
}