#include <iostream>
#include <cstdio>
using namespace std;
#define icin(x) scanf("%d", &x)

int main(){
	int t;
	icin(t);
	for(int a=1;a<=t;a++){
		int m, n, rx, ry, l;
		icin(m), icin(n), icin(rx), icin(ry), icin(l);
		int x=0, y=0;
		for(int i=0;i<l;i++){
			char c;
			cin >> c;
			if(c == 'U')
				y++;
			else if (c == 'D')
				y--;
			else if(c == 'L')
				x--;
			else
				x++;
		}
		if(x < 0 || x > m){
			printf("Case %d: DANGER\n", a);
			continue;
		}
		if(y < 0 || y > n){
			printf("Case %d: DANGER\n", a);
			continue;
		}
		if(x == rx && y==ry){
			printf("Case %d: REACHED\n", a);
			continue;
		}
		printf("Case %d: SOMEWHERE\n", a);
	}
}