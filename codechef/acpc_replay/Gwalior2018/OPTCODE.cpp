#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define icin(x) scanf("%d", &x)
typedef long long ll;

bool myfunc(pair<int, int> a, pair<int, int> b){
	return (a.second < b.second);
}

int main(){
	int t;
	icin(t);
	while(t--){
		int n;
		icin(n);
		map<int, int> m;
		vector<pair<int, int> > v(n);
		for(int i=0;i<n;i++){
			int x, y;
			icin(x), icin(y);
			v[i].first = x;
			v[i].second = y;
		}
		sort(v.begin(), v.end(), myfunc);
		int res=v[n-1].second, count=1, idx=n-2;
		m[v[n-1].first]=1;;
		while(count != 3 && idx>=0){
			if(m[v[idx].first]>0){
				idx--;
				continue;
			}
			else{
				count++;
				res+= v[idx].second;
				m[v[idx].first]=1;
				idx--;
			}
		}
		if(count==3)
			printf("%d\n", res);
		else
			printf("0\n");
	}
}