#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n, k;
	icin(n), icin(k);
	string s, t;
	cin >> t;
	s = t;
	map<char, int> m;
	for(char ch = 'a';ch<='z';ch++)
		m[ch]=0;
	sort(s.begin(), s.end());
	for(int i=0;i<k;i++){
		m[s[i]]++;
	}
	for(int i=0;i<n;i++){
		if(m[t[i]] > 0){
			m[t[i]]--;
			continue;
		}
		printf("%c", t[i]);
	}
	printf("\n");
}