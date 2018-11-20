#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

// bool myfunction(string a, string b){
// 	if(a.length() > b.length())
// 		return false;
// 	else if(a.length() < b.length())
// 		return true;
// 	else{
// 		string temp[2];
// 		temp[0]=a;
// 		temp[1]=b;
// 		sort(temp, temp+2);
// 		return (temp[0]==a);
// 	}
// }

int main(){
	int n;
	icin(n);
	char s[n][101];
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	int k,l;
	for(int i=0;i<n-1;i++){
	    for(int j=0; j<n-i-1; j++){
	    	if(strlen(s[j]) != strlen(s[j+1])){
	    		if(strlen(s[j])>strlen(s[j+1])){
	        	    swap(s[j],s[j+1]);
	        	}
	    	}
	    	else{
		        l = min(strlen(s[j]),strlen(s[j+1]));
		        for(k=0;k<l;++k)
		            if(s[j+1][k]<s[j][k]){ 
		            	swap(s[j],s[j+1]); 
		            	break; 
		            }
		            else if(s[j+1][k]>s[j][k]) 
		            	break;
	        }
	    }
	}
	bool flag;
	for(int i=1;i<n;i++){
		for(int j=0;j<strlen(s[i]);j++){
			if(s[i][j] == s[i-1][0]){
				flag = true;
				for(int idx=0;idx<strlen(s[i-1]);idx++){
					if(s[i][j+idx] != s[i-1][idx]){
						flag = false;
					}
				}
			}
			if(flag == true)
				break;
		}
		if(flag == false){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=0;i<n;i++){
		cout << s[i] << endl;
	}
}