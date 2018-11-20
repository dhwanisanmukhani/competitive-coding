#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

const int INF = 5e3+1;

int main(){
	int t;
	icin(t);
	for(int x=1;x<=t;x++){
		int n;
		icin(n);
		vector<int> arr(INF, 0);
		int a, b;
		for(int i=0;i<n;i++){
			icin(a), icin(b);
			arr[a]++;
			arr[b+1]--;
		}
		int p;
		icin(p);
		for(int i=1;i<INF;i++){
			arr[i] += arr[i-1];
		}
		printf("Case #%d:", x);
		int temp;
		for(int i=0;i<p;i++){
			icin(temp);
			printf(" %d", arr[temp]);
		}
		puts("");
	}
}