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
	string s;
	cin >> s;
	int f=0, k=0, l=0;		//flags
	int a=0, b=0, c=0;		//count
	for(int i=0;i<s.length();i++){
		if(s[i] == 'a'){
			a++;
			if(f == 1){
				continue;
			}
			else
				f=1;
		}
		else if(s[i] == 'b'){
			b++;
			if(f!=1){
				printf("NO\n");
				return 0;
			}
			else
				k=1;
		}
		else{
			c++;
			if(f!=1 || k!=1){
				printf("NO\n");
				return 0;
			}
			else
				l=1;
		}
	}

	if((c == a || c == b) && a!=0 && b!=0){
		printf("YES\n");
	}
	else
		printf("NO\n");
}