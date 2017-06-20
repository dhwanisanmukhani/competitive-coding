// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include <algorithm>
// using namespace std;
// #define icin(x) scanf("%d", &x)
// #define lcin(x) scanf("%lld", &x)

// int main(){
// 	int t;
// 	icin(t);
// 	for(int s=0;s<t;s++){
// 		int n, q;
// 		icin(n), icin(q);
// 		vector<int> arr(n+1);
// 		vector<vector<int> >index(n+1);
// 		for(int i=1;i<=n;i++){
// 			icin(arr[i]);
// 			index[arr[i]].push_back(i);
// 		}
// 		for(int k=0;k<q;k++){
// 			vector<int> v1 = arr;
// 			vector<int> v2 = arr;
// 			int a, b, c, d;
// 			icin(a), icin(b), icin(c), icin(d);
// 			int miss=0;
// 			for(int i=c;i<=d;i++){
// 				// for(int j=0;j<index[arr[i]].size();j++){
// 				// 	if(index[arr[i]][0] >= a && index[arr[i]][0]<=b){
// 				// 		break;
// 				// 	}
// 				// 	if(index[arr[i]][j] > b){
// 				// 		miss++;
// 				// 		break;
// 				// 	}
// 				// }
// 				// if(miss>1)
// 				// 	break;
				
// 			}
// 			if(miss > 1)
// 				printf("NO\n");
// 			else
// 				printf("YES\n");
// 		}
// 	}
// }
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
 
int main(){
	int t;
	icin(t);
	for(int s=0;s<t;s++){
		int n, q;
		icin(n), icin(q);
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			icin(arr[i]);
		}
		for(int k=0;k<q;k++){
			vector<int> v1 = arr;
			vector<int> v2 = arr;
			int a, b, c, d;
			icin(a), icin(b), icin(c), icin(d);
			sort(v1.begin()+a-1, v1.begin()+b);
			sort(v2.begin()+c-1, v2.begin()+d);
			int miss = 0;
			while(miss<=1){
				if(v1[a-1] != v2[c-1]){
					miss++;
				}
				a++, c++;
				if(a == b+1)
					break;
			}
			if(miss <= 1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
} 