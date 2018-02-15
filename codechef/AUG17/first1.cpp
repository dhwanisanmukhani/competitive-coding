#include <iostream>
using namespace std;

int main(){
	int s, v1, v2, t1, t2;
	scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2);
	int first, second;
	first = (2*t1) + (s*v1);
	second  = (2*t2) + (s*v2);
	if(first > second)
		cout<<"First"<<endl;
	else if(first < second)
		cout<<"Second"<<endl;
	else
		cout<<"Friendship"<<endl;
	return 0;
}