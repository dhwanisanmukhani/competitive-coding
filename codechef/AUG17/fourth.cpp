#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int t;
	icin(t);
	for(int x=0;x<t;x++){
		string s, t;
		cin>>s>>t;
		map <char, int> m1, m2;
		for(int i=0;i<s.length();i++){
			m1[s[i]]++;
			m2[t[i]]++;
		}
		int flag=0;
		for(char c='a';c<='z';c++){
			if(m1[c]>1 && m2[c]==0){
				flag=1;
				break;
			}
		}
		int sub =1;
		for(char c='a';c<='z';c++){
			if(m2[c] >0){
				if(m1[c] == 0)
					sub=0;
			}
		}
		if(sub == 1){
			for(char c='a';c<='z';c++){
				if(m1[c]>0 && m2[c]==0){
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
			cout<<"A"<<endl;
		else
			cout<<"B"<<endl;
	}
}

