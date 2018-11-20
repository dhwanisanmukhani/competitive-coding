#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)

bool is_finite(double p,double q,double b){
	map<double, int> m;
	if(q==1)
		return true;
	double frac = ((int)p%(int)q)/q;
	printf("%lf\n", frac);
	m[frac] = -1;
	while(frac){
		frac = frac*b;
		frac -= floor(frac);
		printf("%d %lf\n", m[frac], frac);
		if(m[frac] == -1)
			return false;
		m[frac] = -1;
	}
	return true;
}

int main(){
	int n;
	icin(n);
	double p, q, b;
	for(int i=0;i<n;i++){
		scanf("%lf %lf %lf", &p, &q, &b);
		if(is_finite(p, q, b))
			printf("Finite\n");
		else
			printf("Infinite\n");
	}
}