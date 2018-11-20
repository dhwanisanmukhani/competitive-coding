#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int x, y;
	icin(x), icin(y);
	if(x == 1){
		if(y > x)
			printf("<\n");
		else
			printf("=\n");
		return 0;
	}
	if(y == 1){
		printf(">\n");
		return 0;
	}
	if(log(y*log(x)) > log(x*log(y)))
		printf(">\n");
	if(log(y*log(x)) < log(x*log(y)))
		printf("<\n");
	if(log(y*log(x)) == log(x*log(y)))
		printf("=\n");
}