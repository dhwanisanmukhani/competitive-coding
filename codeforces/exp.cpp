#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int val[4],a,b,c;
	cin>>a>>b>>c;	
	val[0]=(a+b)*c;
	val[1]=a*(b+c);
	val[2]=a*b*c;
	val[3]=a+b+c;
	sort(val,val+4);
	cout<<val[3]<<endl;
}