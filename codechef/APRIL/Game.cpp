#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

void prime(int n, vector<int> &v){
	if(n==6){
		v[2]=1;
		v[3]=1;
	}
	else if(n==4){
		v[2]=1;
	}
	else if(n >=2){
		v[n]=1;
	}
}

int count(vector<int> &v){
	return v[2]+v[3]+v[5]+v[7];
}

int main(){
	int t;
	icin(t);
	while(t--){
		int a, b, c;
		icin(a), icin(b), icin(c);
		vector<int> US(10, 0), R(10, 0);
		prime(a, US);
		prime(b, US);
		prime(b, R);
		prime(c, R);
		int x=count(US);
		int y=count(R);
		if(x>y)
			printf("s0\n");
		else if(x==y)
			printf("draw\n");
		else
			printf("s1\n");
	}
}