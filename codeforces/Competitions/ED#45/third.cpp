#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

ll complete=0;
vector<ll> i_side;
vector<ll> j_side;

void sides(string s){
	ll i=0, j=0;
	for(int x=0;x<s.length();x++){
		if(s[x] == '(')
			i++;
		else{
			if(i>0)
				i--;
			else
				j++;
		}
	}
	if(i>0 && j>0)
		return;
	else if(i>0)
		i_side[i-1]++;
	else if(j>0)
		j_side[j-1]++;
	else
		complete++;
}

int main(){
	int n;
	icin(n);
	i_side.assign(n, 0);
	j_side.assign(n, 0);
	string s;
	for(int i=0;i<n;i++){
		cin >> s;
		sides(s);
	}
	ll count=0;
	count += (complete*complete);
	for(int x=0;x<n;x++)
		count += (i_side[x]*j_side[x]);
	printf("%lld\n", count);
}