#include <iostream>
using namespace std;
#define icin(x) scanf("%d", &x) 

int main(){
	int t;
	icin(t);
	while(t--){
		int x,y,a,b;
		icin(x), icin(y), icin(a), icin(b);
		if(x!=a && y!=b){
			printf("sad\n");
			continue;
		} 
		if(x==a){
			if(y>b)
				printf("down\n");
			else
				printf("up\n");
		}
		else{
			if(x>a)
				printf("left\n");
			else
				printf("right\n");
		}
	}
}