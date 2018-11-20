#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	string a, b;
	cin >> a >> b;
	int sz = a.length();
	sz--;
	int count=0;
	if(a[0] == '0' && b[0] == '0'){
		if(a[1] == '0'){
			count++;
			a[1] = 'X';
			a[0] = b[0] = 'X';
		}
		else if(b[1] == '0'){
			count++;
			b[1] = 'X';
			a[0] = b[0] = 'X';
		}
	}
	if(a[sz] == '0' && b[sz] == '0'){
		if(a[sz-1] == '0'){
			count++;
			a[sz-1] = 'X';
			a[sz] = b[sz] = 'X';
		}
		else if(b[sz-1] == '0'){
			count++;
			b[sz-1] = 'X';
			a[sz] = b[sz] = 'X';
		}
	}
	for(int i=1;i<sz;i++){
		if(a[i] == '0' && b[i] == '0'){
			if(a[i-1] == '0'){
				count++;
				a[i-1]='X';
				a[i] = b[i] = 'X';
			}
			else if(b[i-1] == '0'){
				count++;
				b[i-1]='X';
				a[i] = b[i] = 'X';
			}
			else if(a[i+1] == '0'){
				count++;
				a[i+1]='X';
				a[i] = b[i] = 'X';
			}
			else if(b[i+1] == '0'){
				count++;
				b[i+1]='X';
				a[i] = b[i] = 'X';
			}
		}
	}
	printf("%d\n", count);
}