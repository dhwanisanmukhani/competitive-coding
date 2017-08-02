#include <iostream>
using namespace std;
#define lcin(x) scanf("%lld", &x)
 
int main() {
	int t;
	scanf("%d", &t);
	for(int a=0;a<t;a++){
	    long long n, b;
	    lcin(n), lcin(b);
	    long long left=n/2, right= n-left, min_diff, mul=1;
	    if((right%b) < (b-(right%b))){
	        min_diff=(right%b);
	        mul=-1;
	    }
	    else
	        min_diff= b-(right%b);
	    if(min_diff > (left%b)){
	        min_diff = (left%b);
	        mul=-2;
	    }
	    if(min_diff > (b-(left%b))){
	        min_diff = b-(left%b);
	        mul=2;
	    }
	    if(mul==-2 || mul == 2)
	    {
	        left = (n/2) + ((mul/2)*(min_diff));
	        right = n - left;
	    }
	    else{
	        left = (n/2) + ((mul)*(min_diff));
	        right = n-left;
	    }
	    printf("%lld\n", (left*right)/b);
	}
	return 0;
}