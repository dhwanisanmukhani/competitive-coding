#include <iostream>
using namespace std;

int main() {
	
	int n,m;
	std::cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
	    std::cin >> a[i];
	}
	int total[n+!];
	total[0]=0;
	for(int i=1;i<=n;i++)
	{
	    total[i]=total[i-1]+a[i-1];
	}
	std::cin >> m;
	int fruity[m];
	for(int i=0;i<m;i++)
	{
	    std::cin >> fruity[i];
	}
	int r=n,l=0;
	int mid=(r+l)/2;
	for(int i=0;i<m;i++)
	{
	    while((r-l)!=1)
	    {
	        
	    }
	}
	
}
