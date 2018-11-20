#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n;
	icin(n);
	vector<ll> neg, pos;;
	ll sum=0;
	ll temp;
	for(int i=0;i<n;i++){
		lcin(temp);
		if(temp>0)
			pos.push_back(temp);
		else
			neg.push_back(temp);
	}
	int count=0;
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());
	for(int i=neg.size()-1;i>=0;i--){
		if(neg[i] == 0)
			continue;
		if(neg[i] - sum == 0)
			continue;
		count++;
		sum += (neg[i]-sum);
		neg[i]=0;
	}
	sum=0;
	for(int i=0;i<pos.size();i++){
		if(pos[i] == 0)
			continue;
		if(pos[i] - sum == 0)
			continue;
		count++;
		sum += (pos[i]-sum);
		pos[i]=0;
	}
	printf("%d\n", count);
}