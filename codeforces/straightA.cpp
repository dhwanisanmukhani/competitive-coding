#include <iostream>
using namespace std;

int main()
{
	int n;
	float k;
	cin >> n >> k;
	int sum = 0;
	int marks;
	for (int i = 0; i < n; ++i)
	{
		cin >> marks;
		sum += marks;
	}
	int x = 2*(n*(k-0.5) - sum);
	if(x > 0)
		printf("%d\n", x);
	else
		printf("0\n");
	return 0;
}