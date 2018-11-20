#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n;
	cin >>n;
	float arr[n];
	float sum=0;
	float goal=(float)n*4.5;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr+n);
	int count=0;
	int i=0;
	while(sum < goal){
		if(arr[i] == 5){
			i++;
			continue;
		}
		count++;
		sum += (5 - arr[i]);
		i++;
	}
	printf("%d\n", count);
}