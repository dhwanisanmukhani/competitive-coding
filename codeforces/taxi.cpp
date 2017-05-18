#include <iostream>
using namespace std;
int main()
{
	int n,i,taxi=0,x=0,y=0,z=0,w=0;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			x++;
		else if(a[i]==2)
			y++;
		else if(a[i]==3)
			z++;
		else
			w++;
	}
	if(z<x)
	{	
		taxi=w+z+(y/2);
		if(y%2==0)
		{
			if((x-z)%4==0)
			{
				taxi=taxi+((x-z)/4);
			}
			else
			{
				taxi=taxi+((x-z)/4)+1;
			}
		}
		else
		{
			if((x-z)<=2)
				taxi=taxi+1;
			else
			{		
				taxi=taxi+1;
				if((x-z-2)%4==0)
				{
					taxi=taxi+((x-z-2)/4);
				}
				else
				{
					taxi=taxi+((x-z-2)/4)+1;
				}				
			}
		}
	}
	else
	{
		taxi=w+z;
		if(y%2==0)
			taxi=taxi+(y/2);
		else
			taxi=taxi+(y/2)+1;
	}
	cout<<taxi<<endl;
	return 0;		
}
