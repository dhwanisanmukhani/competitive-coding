#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int t;
	icin(t);
	while(t--){
		string s;
		cin >> s;
		vector<int> v(10, 0);
		vector<int> freq(10, 0);
		for(int i=0;i<s.length();i++){
			v[s[i]-'0'] = 1;
			freq[s[i]-'0']++;
		}
		for(int i=65;i<=90;i++){
			if(i%10 == i/10){
				if(freq[i/10] >= 2){
					printf("%c", i);
				}
			}
			else{
				if(v[i%10]==1 && v[i/10]==1){
					printf("%c", i);
				}
			}
		}
		printf("\n");
	}
}