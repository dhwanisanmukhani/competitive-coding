#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n, k;
	icin(n), icin(k);
	vector<int> v;
	map<int, int> m;
	int count=0;
	for(int i=0;i<n;i++){
		int temp;
		icin(temp);
		if(m[temp]==100)
			continue;
		count++;
		m[temp]=100;
		v.push_back(i+1);
	}
	if(count >= k){
		printf("YES\n");
		for(int i=0;i<k;i++){
			printf("%d\t", v[i]);
		}
	}
	else
		printf("NO\n");
}