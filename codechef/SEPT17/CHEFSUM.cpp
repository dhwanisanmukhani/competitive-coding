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
	while(t--){
		int n;
		icin(n);
		int sum=1e9, idx=1;
		int temp;
		for(int i=1;i<=n;i++){
			icin(temp);
			if(temp < sum){
				sum=temp;
				idx=i;
			}
		}
		printf("%d\n", idx);
	}
}