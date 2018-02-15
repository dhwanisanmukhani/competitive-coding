#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;


class disjoint_set{
public:
	class node{
	public:
		int data;
		int rank;
		int diff;
		node* p;
	};
public:
	node* make_set(int x){
		node* temp;
		temp=new(struct node);
		temp->data=x;
		temp->p=temp;
		temp->rank=0;
		diff[x]=x;
		return temp;
	}
	node* find_set(node* x){
		if(x != x->p){
			x->p=find_set(x->p);
			x->diff = x->diff ^ y->diff;
		}
		return x->p;
	}
	void union_set(node* x,node* y,int val){
		node* root_x = find(x)
    	node* root_y = find(y)
		if(root_x->rank > root_y->rank){
			root_y->p=x;
			root_x->diff = val ^ x->diff ^ y->diff;
		}
		else{
			x->p=y;
			if(x->rank==y->rank){
				y->rank=y->rank+1;
			}
			root_y->diff = val ^ x->diff ^ y->diff;
		}
	}
};

int main(){
	disjoint_set dsu;
	disjoint_set::node* vertices[1e5];
	int t;
	icin(t);
	while(t--){
		int n, q;
		icin(n), icin(q);
		for(int i=0;i<n;i++){
			vertices[i]=dsu.make_set(i);
		}
		int a,b;
		for(int i=0;i<edges;i++){
			cin>>a>>b>>val;
			if(val == 0)
				dsu.union_set(vertices[a-1],vertices[b-1]);
			else
		}
	}
	return 0;
}