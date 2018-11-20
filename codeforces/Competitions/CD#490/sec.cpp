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
	int n;
	icin(n);
	string s;
	cin >> s;
	string t=s;
	for(int i=1;i<=n;i++){
		if(n%i==0){
			for(int j=0;j<i;j++){
				t[i-1-j] = s[j];
			}
			s = t;
		}
	}
	cout << t <<'\n';
}