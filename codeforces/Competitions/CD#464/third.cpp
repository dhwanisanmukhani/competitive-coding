#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	double R, x1, y1, x2, y2;
	cin >> R >> x1 >> y1 >> x2 >> y2;
	double r, t;
	t = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));
	r = sqrt(t);
	if(r >= R){
		printf("%0.9f %0.9f %0.9f\n", x1, y1, R);
		return 0;
	}
	if(r == 0){
		printf("%0.9f %0.9f %0.9f\n", x1+(R/2), y1, R/2);
		return 0;
	}
	double x, y;
	x = (((x1 - x2)/r)*((R+r)/2)) + x2;
	y = (((y1 - y2)/r)*((R+r)/2)) + y2;
	printf("%0.9f %0.9f %0.9f\n", x, y, (R+r)/2);
}