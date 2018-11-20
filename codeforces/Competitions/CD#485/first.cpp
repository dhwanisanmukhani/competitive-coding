#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n;
	icin(n);
	vector<int> v(6, 0);
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		if(s[0] == 'p')
			v[0]=1;
		else if(s[0] == 'g')
			v[1]=1;
		else if(s[0] == 'b')
			v[2]=1;
		else if(s[0] == 'o')
			v[3]=1;
		else if(s[0] == 'r')
			v[4]=1;
		else
			v[5]=1;
	}
	printf("%d\n", 6-n);
	if(v[0] == 0)
		printf("Power\n");
	if(v[1] == 0)
		printf("Time\n");
	if(v[2] == 0)
		printf("Space\n");
	if(v[3]==0)
		printf("Soul\n");
	if(v[4] == 0)
		printf("Reality\n");
	if(v[5]==0)
		printf("Mind\n");
}