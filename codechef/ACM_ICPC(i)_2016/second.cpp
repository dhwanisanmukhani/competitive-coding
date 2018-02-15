#include <iostream>
using namespace std;
#define icin(x) scanf("%d", &x) 

int main(){
	int t;
	icin(t);
	while(t--){
		int n;
		icin(n);
		printf("%d\n", (n%9)+1);
	}
}