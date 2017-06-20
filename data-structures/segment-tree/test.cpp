#include <iostream>
#include <cstdio>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long LL;

class SegmentTree{
private:
	struct Node{
		int l,r;
		int data;
		int lazy;
		Node(int _l=0, int _r=0,int _data = 0, int _lazy=0){
			init(_l, _r, _data, _lazy);
		}
		void init(int _l, int _r, int _data, int _lazy){
			l = _l;
			r = _r;
			data = _data;
			lazy = _lazy;
		}
		friend Node merge(const Node& left, const Node& right){
			int data = max(left.data+left.lazy, right.data + right.lazy);
			return Node(left.l, right.r, data, 0);
		}
	}
	vector<Node> nodes;
	vector<int> data;
	int n;
public:
	void init(const vector<int>& _data){
		data = _data;
		n = data.size()-1;
		nodes.resize(4*n);
		build(1, n, 1);
	}
	void build(int l, int r, int idx){
		if(l==r){
			nodes[idx].init(l, r, data[l], 0);
			return;
		}
		int mid = (l+r)>>1;
		build(l, mid, idx<<1);
		build(mid+1, r, idx<<1|1);
		nodes[idx] = merge(nodes[idx<<1], nodes[idx<<1|1]);
	}
	void percolate(int idx){
		nodes[idx<<1].lazy += nodes[idx].lazy;
		nodes[idx<<1|1].lazy += nodes[idx].lazy;
		nodes[idx].lazy=0;
	}
	Node query(int l, int r, int idx, int a, int b){
		if(l==a && r==b){
			return nodes[idx];
		}
		int mid = (l+r)>>1;
		if(b<=mid){
			return query(l, mid, idx<<1, a, b);
		}
		if(a>mid){
			return query(mid+1, r, idx<<1|1, a, b);			
		}
		return merge(query(l, mid, idx<<1, a, mid), query(mid+1, r, idx<<1|1, ,mid+1, b));
	}
	void update(int l, int r, int idx, int a, int b){
		if(l==a && r==b){
			nodes[idx].lazy++;
			return;
		}
		percolate(idx);
		int mid = (l+r)>>1;
		if(b<=mid){
			update(l, mid, idx<<1, a, b);
		}
		else if(a>mid){
			update(mid+1, r, idx<<1|1, a, b);			
		}
		else{
			update(l, mid, idx<<1, a, mid);
			update(mid+1, r, idx<<1|1, mid+1, b);
		}
		nodes[idx] = merge(nodes[idx<<1], nodes[idx<<1|1]);		
	}
	void update_1(int l, int r, int idx, int a,int new_data){
		if(l==r){
			data[a] = new_data;
			nodes[idx].init(l, r, data[a], 0);
			return;
		}
		percolate(idx);
		int mid = (l+r)>>1;
		if(a<=mid){
			update_1(l, mid, idx<<1, a, new_data);
		}
		else{
			update_1(mid+1, r, idx<<1|1, a, new_data);			
		}
		nodes[idx] = merge(nodes[idx<<1], nodes[idx<<1|1]);	
	}
};

int main(){
	return 0;
}