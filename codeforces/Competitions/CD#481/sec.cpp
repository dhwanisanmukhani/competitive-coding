#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n;
	icin(n);;
	char str[n];
	cin >> str;
	int count = 0;
	int consecutive_x = 0;
	for(int i=0;i<n;i++){
		if(str[i] != 'x'){
			consecutive_x = 0;
			continue;
		}
		if(consecutive_x == 2){
			count++;
			str[i]='\0';
		}
		else{
			consecutive_x++;
		}
	}
	printf("%d\n", count);
}