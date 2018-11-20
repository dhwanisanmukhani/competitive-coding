#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n;
	icin(n);
	int arr[n];
	map<int, int> m;
	for(int i=0;i<n;i++){
		icin(arr[i]);
	}
	vector<int> v;
	for(int i=n-1;i>=0;i--){
		if(m[arr[i]] == 100)
			continue;
		m[arr[i]]=100;
		v.push_back(arr[i]);
	}
	cout<<v.size()<<endl;
	for(int i=v.size()-1;i>=0;i--){
		printf("%d\t", v[i]);
	}
}