#include <iostream>
using namespace std;
#define icin(x) scanf("%d", &x) 

int main(){
	int t;
	icin(t);
	while(t--){
		int n;
		icin(n);
		int nzero=0, nm_one=0, n_one=0, nn=0;
		for(int x=0;x<n;x++){
			int a;
			icin(a);
			if(a==-1)
				nm_one++;
			else if(a==1)
				n_one++;
			else if(a==0)
				nzero++;
			else
				nn++;
		}
		if(n==1){
			printf("yes\n");
			continue;
		}
		if(nn>1)
			printf("no\n");
		else if(nn==1){
			if(nm_one > 0)
				printf("no\n");
			else
				printf("yes\n");
		}
		else{
			if(nm_one>1 && n_one==0)
				printf("no\n");
			else
				printf("yes\n");
		}
	}	
}