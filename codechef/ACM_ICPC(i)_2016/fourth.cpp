#include <iostream>
using namespace std;
#define icin(x) scanf("%d", &x) 

int main(){
	int t;
	icin(t);
	while(t--){
		int n, m, d, D;
		icin(n), icin(m), icin(d), icin(D);
		if(m < (n*d) || m > (n*D)){
			printf("-1\n");
			continue;
		}
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<d;j++){
				int x = (i+j)%n;
				printf("%d %d\n",i, x+1);
			}
		}
		int count = m-(n*d);
		if(count==0)
			continue;
		int flag=0;
		int lim = D-d;
		if(D > n)
			lim = n-d;
		for(int i=1;i<=n;i++){
			for(int j=0;j<lim;j++){
				int x=(i+d+j)%n;
				printf("%d %d\n",i ,x+1);
				count--;
				if(count==0){
					flag=1;
					break;
				}
			}
			if(flag==1){
				break;
			}
		}
	}
}