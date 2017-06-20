#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)

int main(){
	int t;
	icin(t);
	for(int n=0;n<t;n++){
		int p, q, r;
		int flag = 0;
		icin(p), icin(q), icin(r);
		long long a[p+1], b[q+1], c[r+1];
		vector<long long>dpa(p+1, 0), dpc(r+1, 0);
		dpa[0] = dpc[0] = 0;
		a[0] = b[0] = c[0] = 0;
		for(int i=1;i<=p;i++){
			lcin(a[i]);
		}
		for(int i=1;i<=q;i++){
			lcin(b[i]);
		}
		for(int i=1;i<=r;i++){
			lcin(c[i]);
		}
		sort(a+1, a+p+1);
		sort(b+1, b+q+1);
		sort(c+1, c+r+1);
		for(int i=1;i<=p;i++){
			dpa[i] = dpa[i-1] + a[i];
		}
		for(int i=1;i<=r;i++){
			dpc[i] = dpc[i-1] + c[i];
		}		
		int breakx = p;
		// while(a[breakx] > b[q]){
		// 	breakx--;
		// 	if(breakx < 1){
		// 		flag = 1;
		// 		break;
		// 	}
		// }
		int breakz = r;
		// while(c[breakz] > b[q]){
		// 	breakz--;
		// 	if(breakz < 1){
		// 		flag = 1;
		// 		break;
		// 	}
		// }
		// if(flag == 1)
		// {
		// 	cout<<"0"<<endl;
		// 	continue;
		// }
		long long sum = 0;
		long long final = 0;
		for(int i=q;i>=0;i--){
			while(a[breakx] > b[i]){
				breakx--;
				if(breakx < 1){
					break;
				}
			}
			if(breakx < 1){
				break;
			}
			while(c[breakz] > b[i]){
				breakz--;
				if(breakz < 1){
					break;
				}
			}
			if(breakz < 1){
				break;
			}
			sum = (dpa[breakx]%1000000007 + ((breakx*b[i])%1000000007))%1000000007;
			sum *= ((dpc[breakz]%1000000007 + ((breakz*b[i])%1000000007))%1000000007);
			sum = sum%1000000007;
			final = final+sum;
			final = final%1000000007;
		}
		printf("%lld\n", final%1000000007);
	}
}