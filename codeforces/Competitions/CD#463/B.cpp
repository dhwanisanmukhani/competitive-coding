#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define icin(x) scanf("%d", &x)
typedef long long ll;

#define n 1000001
int arr[10][n];
int ans[n];

int main(){
	int temp=1;
	for(int j=1;j<n;j++){
	    int i=j;
		if(i<10){
			ans[i]=i;
			continue;
		}
		while(i>0){
			if(i%10)
				temp*=(i%10);
			i = i/10;
		}
		ans[j]=ans[temp];
		temp=1;
	}
	for(int i=1;i<10;i++){
		arr[i][1] = 0;
	}
	for(int i=1;i<10;i++){
		arr[i][0] = 0;
	}
	arr[ans[1]][1]++;
	for(int i=1;i<n;i++){
		for(int j=1;j<10;j++){
			arr[j][i] = arr[j][i-1];
			if(ans[i] == j)
				arr[j][i]++;
		}
	}
	int q, l, r, k;
	icin(q);
	for(int i=0;i<q;i++){
		icin(l), icin(r), icin(k);
		printf("%d\n", arr[k][r] - arr[k][l-1]);
	}
}