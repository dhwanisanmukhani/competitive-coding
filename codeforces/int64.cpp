#include <iostream>
#include <inttypes.h>
using namespace std;
int main()
{
	int64_t n,m;
	cin>>n>>m;
	int64_t count=0;
	int64_t prev=1,next;
	for(int i=0;i<m;i++)
	{
		cin>>next;
		if(next<prev)
		{
			count++;
		}
		prev=next;
	}
	cout<<count<<endl;
	cout<<((count)*n)+next-1<<endl<<endl;
}

	