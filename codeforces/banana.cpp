#include <iostream>
using namespace std;
int main()
{
	int k,n,w,coeff,sum,borrow;
	cin>>k>>n>>w;
	coeff=(w*(w+1))/2;
	sum=coeff*k;
	borrow=sum-n;
	if(borrow>0)
		cout<<borrow<<endl;
	else
		cout<<"0"<<endl;
	return 0;
}