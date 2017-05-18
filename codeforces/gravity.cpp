#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	int col_h[n];
	for(int i=0;i<n;i++)
	{
		cin>>col_h[i];
	}
	sort(col_h,col_h + n);
	for(int i=0;i<n;i++)
	{
		cout<<col_h[i]<<" ";
	}
	return 0;
}