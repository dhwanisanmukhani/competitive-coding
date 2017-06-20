#include <iostream>
#include <unordered_map>
#include <cstdio>
#include <string>
using namespace std;


int main(){
	unordered_map<string, int> usernames;	
	int n;
	scanf("%d", &n);
	char str[32];
	for(int i=0;i<n;i++){
		scanf("%s",str);
		if(usernames[str]){
			printf("%s%d\n", str, usernames[str]);
		}
		else{
			printf("OK\n");
		}
		usernames[str]++;
	}
}