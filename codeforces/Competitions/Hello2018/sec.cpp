#include <iostream>
#include <cstdio>
using namespace std;
#define icin(x) scanf("%d", &x);
#define lcin(x) scanf("%lld", &x);
typedef long long ll;

struct node{
	int parent;
	int no_of_leaf;
	int flag;
	node(){
		no_of_leaf=0;
		flag=0;
	}	
	int if_leaf(){
		return flag;
	}
	void upgrade_leaf(){
		flag=1;
	}
};

int main(){
	int n;
	icin(n);
	node nodes[n+1];
	nodes[1].upgrade_leaf();
	for(int i=1;i<n;i++){
		int par;
		icin(par);
		nodes[i+1].parent = par;
		nodes[par].no_of_leaf++;
		if(par == 1)
			continue;
		if(nodes[par].if_leaf() == 0){
			nodes[par].upgrade_leaf();
			nodes[nodes[par].parent].no_of_leaf--;
		}
	}
	for(int i=1;i<=n;i++){
		if(nodes[i].no_of_leaf < 3 && nodes[i].if_leaf() != 0){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}