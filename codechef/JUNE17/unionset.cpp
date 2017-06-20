#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)

int main(){
	int t;
	icin(t);
	for(int s=0;s<t;s++){
		int n, k;
		icin(n), icin(k);
		vector<vector<int> > arr(n, vector<int>(k, 0));
		int arrsize[n];
		for(int i=0;i<n;i++){
			icin(arrsize[i]);
			for(int j=0;j<arrsize[i];j++){
				int temp;
				icin(temp);
				arr[i][temp-1] = 1;
			}
		}
		int count=0;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				int flag = 0;
				for(int l=0;l<k;l++){
					if(arr[i][l] != 1 && arr[j][l] != 1){
						flag = 1;
						break;
					}
				}
				if(flag == 0){
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
}