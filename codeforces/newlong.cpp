#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,l,m;
	std::cin >> n >> l;
	int array[n] ;
	for(int i=0;i<n;i++)
    {
        std::cin >> array[i];
    }
    sort (array,array+n);
    m=max(array[0],l-array[n-1])*2;
    for(int i=0;i<n-1;i++)
    {
        m=max(m,array[i+1]-array[i]);
    }
    printf("%lf",m/2.0);
	return 0;
}