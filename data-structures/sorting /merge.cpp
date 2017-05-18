#include <iostream>
using namespace std;

void merge(int* a, int begin, int center, int end)
{
	int i=begin,j=center+1,t=0;
	int* ptr=new int[end-begin+1];
	while(i<=center && j<=end)
	{
		if(a[i] < a[j])
		{
			ptr[t]=a[i];
			i++;
			t++;
		}
		else
		{
			ptr[t]=a[j];
			j++;
			t++;
		}
	}
	while (j<=end)
	{
		ptr[t]=a[j];
		t++;
		j++;
	}
	while (i<=center)
	{
		ptr[t]=a[i];
		t++;
		i++;
	}
	for(t=0; t<end-begin+1; t++)
	{
		a[begin+t] = ptr[t];
	}
	delete [] ptr;
}

void mergesort(int* a, int begin, int end)
{
	if(begin<end)
	{
		int mid = (begin+end)/2;
		mergesort(a, begin, mid);
		mergesort(a, mid+1, end);
		merge(a, begin, mid, end);
		for (int i = 0; i < end; ++i)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	mergesort(array, 0, n);
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}