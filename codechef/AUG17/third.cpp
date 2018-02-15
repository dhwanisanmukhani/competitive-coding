#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)

int main(){
	int t;
	icin(t);
	for(int x=0;x<t;x++){
		int n, m;
		icin(n), icin(m);
		long long min_sal[n+1];
		for(int i=1;i<=n;i++){
			lcin(min_sal[i]);
		}
		long long offer[m+1];
		int max_allowed[m+1];
		for(int i=1;i<=m;i++){
			lcin(offer[i]), icin(max_allowed[i]);
		}
		int qual[n+1][m+1];
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			for(int j=1;j<=m;j++){
				qual[i][j] = s[j-1]-'0';
			}
		}
		vector<int> company_info(m+1, 1);
		int no_of_employed=0,  no_of_comp=0;
		long long total_sal=0;
		for(int i=1;i<=n;i++){
			long long max_offer=0;
			int max_idx=0;
			for(int j=1;j<=m;j++){
				if(qual[i][j]==0)
					continue;
				if(max_allowed[j]==0)
					continue;
				if(min_sal[i] > offer[j])
					continue;
				if(max_offer < offer[j]){
					max_offer = offer[j];
					max_idx = j;
				}
			}
			if(max_offer > 0){
				max_allowed[max_idx]--;
				company_info[max_idx] = 0;
				total_sal += max_offer;
				no_of_employed++;
			}
		}
		for(int i=1;i<=m;i++){
			no_of_comp += company_info[i];
		}
		printf("%d %lld %d\n", no_of_employed, total_sal, no_of_comp);
	}
}