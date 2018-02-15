#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define icin(x) scanf("%d", &x)
typedef long long ll;

int main(){
	int n;
	icin(n);
	vector<double> v(n);
	double sum=0;
	for(int i=0;i<n;i++){
		cin >> v[i];
		sum += v[i];
	}
	
}