#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n, m;
	icin(n), icin(m);
	int map[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char ch;
			scanf(" %c", &ch);
			map[i][j] = ch-'0';
		}
	}	
	int lambs[m];
	for(int i=0;i<m;i++){
		lambs[i]=0;
		for(int j=0;j<n;j++){
			lambs[i] += map[j][i];
		}
	}
	bool switches;
	for(int i=0;i<n;i++){
		switches = true;
		for(int j=0;j<m;j++){
			if(map[i][j] == 1){
				if(lambs[j] == 1)
					switches = false;
			}
		}
		if(switches == true){
			printf("YES\n");
			return 0;;
		}
	}
	printf("NO\n");
}
