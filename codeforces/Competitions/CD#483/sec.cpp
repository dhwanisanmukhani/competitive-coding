#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
#define ccin(x) scanf(" %c", &x)
char arr[101][101];

bool no_of_bombs(int i, int j){
	//printf("%d %d\n", i, j);
	int count=0;
	int allowed;
	if(arr[i][j] == '*')
		return true;
	if(arr[i][j] == '.')
		allowed = 0;
	else
		allowed = arr[i][j] - '0';


	for(int t=-1;t<2;t++){
		if(arr[i-1][j+t] == '*')
			count++;
		if(arr[i+1][j+t] == '*')
			count++;
	}
	if(arr[i][j-1] == '*')
		count++;
	if(arr[i][j+1] == '*')
		count++;
	

	//printf("%d %d %d\n", count, i, j);
	if(count == allowed)
		return true;
	else
		return false;
}

int main(){
	int n, m;
	icin(n), icin(m);
	for(int i=0;i<=n+1;i++){
		arr[i][0]='.';
		arr[i][m+1]='.';
	}
	for(int i=1;i<=m;i++){
		arr[0][i] = '.';
		arr[n+1][i] = '.';
	}

	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ccin(arr[i][j]);
			//printf("%c\n", arr[i][j]);
		}
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((flag = no_of_bombs(i, j)) == false){
				printf("NO\n");
				return 0;
			}
		}
	}
		printf("YES\n");
}