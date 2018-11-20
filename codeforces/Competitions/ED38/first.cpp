#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int icheck(char c){
	if(c == 'a' | c=='e'|c=='i'|c=='o'|c=='u'|c=='y')
		return 1;
	else
		return 0;
}

int main(){
	string s;
	int len;
	icin(len);
	cin >> s;
	int flag=0;
	if(icheck(s[0]))
		flag=1;
	printf("%c", s[0]);
	for(int i=1;i<len;i++){
		if(icheck(s[i])){
			if(flag==1)
				continue;
			else{
				flag=1;
				printf("%c", s[i]);
			}
		}
		else{
			flag=0;
			printf("%c", s[i]);
		}
	}
	printf("\n");
}