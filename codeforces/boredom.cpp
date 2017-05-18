#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int64_t v[100001]={0};
    int64_t dp[100001]={0};
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v[temp]++;
    }
    dp[0]=0;
    dp[1]=v[1];
    for(int i=2;i<100001;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+(v[i]*i));
    }
    std::cout << dp[100000] << std::endl;
	return 0;
}
