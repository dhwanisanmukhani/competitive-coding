#include <iostream>
using namespace std;

int part(int* arr, int left, int right, int pivot)
{
	int i = left;
	int j = right - 1;
	while(i <= j)
	{
		while(arr[i] < pivot)
			i++;
		while(arr[j] > pivot && j > 0)
			j--;
		if(i >= j)
			break;
		else
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i];
	arr[i] = arr[right];
	arr[right] = temp;
	return i;
}


void quicksort(int* arr, int left, int right)
{
	int pivot,partition;
	if(right - left <=0)
		return;
	else
	{
		pivot = arr[right];
		partition = part(arr, left, right, pivot);
		quicksort(arr, left, partition - 1);
		quicksort(arr, partition, right);
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	quicksort(arr, 0, n-1);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}