#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

int main(){
	int t;
	icin(t);
	while(t--){
		int n;
		icin(n);
		if(n%2 == 0){
			for(inat i=1;i<=n;i++){
				if(i%2 == 0)
					printf("%d ", i-1);
				else
					printf("%d ", i+1);
			}
		}
		else{
			for(int i=1;i<=n-3;i++){
				if(i%2 == 0)
					printf("%d ", i-1);
				else
					printf("%d ", i+1);
			}
			cout << n-1 << " " << n << " " << n-2;
		}
		cout<<endl;
	}
}