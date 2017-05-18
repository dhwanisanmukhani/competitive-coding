#include <iostream>
using namespace std;

int main() {
	int n;
	std::cin >> n;
	int last,slast;
	last=n/10;
	slast=(last/10)*10+(n%10);
    if(last>slast)
    {
        if(last>n)
        {
            std::cout << last << std::endl;
        }
        else
        {
            std::cout << n << std::endl;
        }
    }
    else
    {
        if(slast>n)
        {
            std::cout << slast << std::endl;
        }
        else
        {
            std::cout << n << std::endl;
        }
    }
	return 0;
}
