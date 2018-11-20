#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n;
	icin(n);
	map<char, int> m1, m2, m3;
	string a, b, c;
	cin >> a >> b >> c;
	if(a.length() <= n){
		printf("Draw\n");
		return 0;
	}
	int sz = a.length();
	for(int i=0;i<sz;i++){
		m1[a[i]]++;
		m2[b[i]]++;
		m3[c[i]]++;
	}

	int c1=0, c2=0, c3=0;
	for(char ch='a';ch<='z';ch++){
		c1 = max(c1, m1[ch]);
		c2 = max(c2, m2[ch]);
		c3 = max(c3, m3[ch]);
	}
	for(char ch='A';ch<='Z';ch++){
		c1 = max(c1, m1[ch]);
		c2 = max(c2, m2[ch]);
		c3 = max(c3, m3[ch]);
	}

	c1 += n;
	c2 += n;
	c3 += n;
	if(c1 > sz)
		c1 = sz;
	if(c2 > sz)
		c2 = sz;
	if(c3 > sz)
		c3 = sz;

	int ribbon = max(c2, max(c3, c1));
	if(ribbon == c1 && ribbon == c2)
		printf("Draw\n");
	else if(ribbon == c2 && ribbon == c3)
		printf("Draw\n");
	else if(ribbon == c1 && ribbon == c3)
		printf("Draw\n");
	else{
		if(ribbon == c1)
			printf("Kuro\n");
		else if(ribbon == c2)
			printf("Shiro\n");
		else
			printf("Katie\n");
	}
}