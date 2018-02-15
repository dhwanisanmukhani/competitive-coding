#include <iostream>
#include <cstdio>
using namespace std;
#define icin(x) scanf("%d", &x);
#define lcin(x) scanf("%lld", &x);
typedef long long ll;

int main(){
	int n, m;
	icin(n);
	icin(m);
	if(n >= 27){
		printf("%d\n", m);
		return 0;
	}	
	else{
		int num=1;
		for(int i=1;i<=n;i++){
			num = num*2;
		}
		printf("%d\n",m%num);
	}
}