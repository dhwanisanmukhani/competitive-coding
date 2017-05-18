#include <iostream>
using namespace std;

int main() {
	int n,temp=1,t;
	std::cin >> n>>t;
	if(n==1&&t==10)
	{
	    std::cout << "-1" << std::endl;
	}
	else if(n!=1&&t!=10)
	{
    	for(int i=1;i<n;i++)
    	{
    	    temp=temp*10;
    	    temp=temp%t;
    	}
    	temp=temp%t;
    	std::cout << "1";
    	for(int i=1;i<n-1;i++)
    	{
    	    std::cout << "0";
    	}
    	std::cout << t-temp << std::endl;
	}
	else if(t!=10)
	{
	    cout<<t<<endl;
	}
	else
	{
	    std::cout << "1";
    	for(int i=1;i<n;i++)
    	{
    	    std::cout << "0";
    	}
	}
    return 0;
}
