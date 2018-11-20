#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n;
	icin(n);
	if(n==1){
		printf("0\n");
		return 0;
	}
	int pos[n/2];
	for(int i=0;i<n/2;i++){
		icin(pos[i]);
	}
	sort(pos, pos+n/2);
	int black=0, white=0;
	int b=1, w=2;
	for(int i=0;i<n/2;i++){
		black += abs(pos[i] - b);
		b += 2;
		white += abs(pos[i] - w);
		w += 2;
	}
	printf("%d\n", min(black, white));
}
