#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int n;
	icin(n);
	string s;
	cin >> s;
	int x=0, y=0;
	int flag=1;
	int count=0;
	if(s[0] == 'U')
		flag=2;
	for(int i=0;i<n;i++){
		if(s[i] == 'U'){
			y++;
			if(x < y){
				if(flag == 1){
					count++;
					flag = 2;
				}
			}
			else if(x > y){
				if(flag == 2){
					count++;
					flag = 1;
				}
			}
		}
		else{
			x++;
			if(x < y){
				if(flag == 1){
					count++;
					flag = 2;
				}
			}
			else if(x > y){
				if(flag == 2){
					count++;
					flag = 1;
				}
			}
		}
	}
	printf("%d\n", count);
}