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
	int count=0;
	for(int i=1;i<n;i++){
		if(n%i == 0)
			count++;
	}
	printf("%d\n", count);
}