#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define icin(x) scanf("%d", &x)

int main(){
	int n, pos, l, r;
	icin(n), icin(pos), icin(l), icin(r);
	int a=1, b=n;
	int ldiff, rdiff;
	if(pos-l > 0)
		ldiff = pos-l;
	else
		ldiff = l-pos;
	if(pos-r > 0)
		rdiff = pos-r;
	else
		rdiff = r-pos;
	int diff;
	if(a==l){
		diff=rdiff;
		if(b==r){
			printf("0\n");
			return 0;
		}
		printf("%d\n", diff+1);
		return 0;
	}
	else if(b==r){
		diff = ldiff;
		printf("%d\n", diff+1);
		return 0;
	}
	if(ldiff > rdiff)
		diff = rdiff;
	else
		diff = ldiff;
	printf("%d\n",2+diff+(r-l));
	return 0;
}