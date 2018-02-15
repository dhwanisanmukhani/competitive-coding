#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int t;
	icin(t);
	while(t--){
		int a, b, c, d, e, f, l, r;
		icin(a), icin(b), icin(c), icin(d), icin(e), icin(f), icin(l), icin(r);
		int x, y, mx, my, nx, ny;
		y = min(l, r);
		x = max(l, r);
		mx = max(a, b);
		my = min(a, b);
		nx = max(d, e);
		ny = min(d, e);
		if(mx > x || my > y){
			printf("-1\n");
			continue;
		}
		if(nx > x || ny > y){
			printf("-1\n");
			continue;
		}
		pair<int, int> c1 = make_pair(0, 0);
		pair<int, int> a1 = make_pair(0, my);
		pair<int, int> b1 = make_pair(mx, 0);
		pair<int, int> f2 = make_pair(x, y);
		pair<int, int> e2 = make_pair(x, y-ny);
		pair<int, int> d2 = make_pair(x-nx, y);
		if(a1 == d2 && b1 == e2){
			printf("-1\n");
			continue;
		}
		else if(a1 == d2){
			if(e2.second > 0){
				f2.second--;
				e2.second--;
				d2.second--;
				if(e2 == b1){
					f2 = make_pair(x, 1);
					e2 = make_pair(x, y);
					d2 = make_pair(0, 1);
				}
			}
			else{
				a1.first++;
				b1.first++;
				c1.first++;
				if(e2 == b1){
					b1 = make_pair(0, 0);
					a1 = make_pair(x-1, my);
					c1 = make_pair(x-1, 0);
				}
			}
		}
		else if(e2 == b1){
			if(d2.first > 0){
				f2.first--;
				e2.first--;
				d2.first--;
				if(d2 == a1){
					e2 = make_pair(1, 0);
					f2 = make_pair(1, y);
					d2 = make_pair(x, y);
				}
			}
			else{
				a1.second++;
				b1.second++;
				c1.second++;
				if(d2 == a1){
					c1 = make_pair(0, y-1);
					a1 = make_pair(0, 0);
					b1 = make_pair(x, y-1);
				}
			}
		}
		if(a>b){
			printf("%d %d\n", a1.first, a1.second);
			printf("%d %d\n", b1.first, b1.second);
		}
		else{
			printf("%d %d\n", b1.first, b1.second);
			printf("%d %d\n", a1.first, a1.second);
		}
		printf("%d %d\n", c1.first, c1.second);
		if(e>f){
			printf("%d %d\n", e2.first, e2.second);
			printf("%d %d\n", d2.first, d2.second);
		}
		else{
			printf("%d %d\n", d2.first, d2.second);
			printf("%d %d\n", e2.first, e2.second);
		}
		printf("%d %d\n", f2.first, f2.second);
	}
}