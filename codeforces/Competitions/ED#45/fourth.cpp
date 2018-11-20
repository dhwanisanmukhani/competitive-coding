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
	int n, a, b;
	icin(n), icin(a), icin(b);
	int connected_components = max(a, b);
	if(n == 1){
		printf("NO\n");
		return 0;
	}
	if(n <= 3 && connected_components ==1){
		printf("NO\n");
		return 0;
	}
	if(a !=1 && b != 1){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	int adj[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i == j)
				adj[i][j]=0;
			else
				adj[i][j]=1;
		}
	}


	for(int x=0;x<connected_components-1;x++){
		for(int i=0;i<n;i++){
			adj[x][i]=0;
			adj[i][x]=0;
		}
	}
	if(connected_components==1){
		for(int i=0;i<n-1;i++){
			adj[i][i+1]=0;
			adj[i+1][i]=0;
		}
	}


	if(connected_components == b){			//taking compliment
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(adj[i][j] == 1)
					adj[i][j]=0;
				else
					adj[i][j]=1;
			}
			adj[i][i]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d", adj[i][j]);
		}
		printf("\n");
	}
}