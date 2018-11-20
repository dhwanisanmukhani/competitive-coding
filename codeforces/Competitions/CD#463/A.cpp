#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	string s;
	cin>>s;
	int sz = s.length();
	for(int i=0;i<sz;i++)
		printf("%c", s[i]);
	for(int i=sz-1;i>=0;i--)
		printf("%c", s[i]);
	printf("\n");
	return 0;
}