#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> flag;

void prime_no(int n)
{
	for(int i=4; i <=n; i++)
	{
		for(int j=2; j*j<=i; j++)
		{
			if(i%j == 0)
			    flag[i]=1;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	if(n>2)
	{
	    flag.assign(n+2, 0);
	    flag[1] = 1;
	    prime_no(n+1);
    	cout<<"2"<<endl;
    	for(int i=2; i<=n+1; i++)
    	{
    	    if(flag[i] == 1)
    	    {
    	        cout<<"2 ";
    	    }
    	    else
    	    {
    	        cout<<"1 ";
    	    }
    	}
	}
	else
	{
	    cout<<"1"<<endl;
	    for(int i=0;i<n;i++)
	    {
	        cout<<"1 ";
	    }
	}
	cout<<endl;
	return 0;
}