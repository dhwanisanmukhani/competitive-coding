#include <bits/stdc++.h>
using namespace std;
#define icin(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair

vector<int> v;

// 1-based segment tree
class SegmentTree{
public:
	class Node{
	public:
		int l, r;
		int data;
		void init(int _l, int _r, int _data){
			l = _l;
			r = _r;
			data = _data;
		}
		void print(){
			printf("[%d, %d] -> %d\n", l, r, data);
		}
	};
	Node merge(Node& l, Node& r){
		Node ret;
		ret.l = l.l;
		ret.r = r.r;
		ret.data = min(l.data, r.data);
		return ret;
	}
	vector<Node> nodes;
	int left(int idx){
		return (idx<<1);
	}
	int right(int idx){
		return (idx<<1)|1;
	}
	void build(int l, int r, int idx){
		if(l==r){
			nodes[idx].init(l, r, v[l]);
			return;
		}
		int mid = (l+r)>>1;
		build(l, mid, left(idx));
		build(mid+1, r, right(idx));
		nodes[idx] = merge(nodes[left(idx)], nodes[right(idx)]);
	}
	void print(int l, int r, int idx){
		if(l==r){
			nodes[idx].print();
			return;
		}
		int mid = (l+r)>>1;
		print(l, mid, left(idx));
		print(mid+1, r, right(idx));
		nodes[idx].print();
	}
	int point_query(int a, int _l, int _r, int x)
	{
	    int count = x;
		int mid = (_l + _r)/2;
		if(_l==_r)
		{
			return count;
		}
		if(a <= mid)
		{
			count = 2*count;
			return point_query(a, _l, mid, count);
		} 
		else if(a > mid)
		{
			count = (2*count) + 1;
			return point_query(a, mid+1, _r, count);
		}
	}
	Node query(int a, int b, int l, int r, int idx)
	{
	    if(a==l && b==r)
	    {
	        return nodes[idx];
	    }
	    int mid = (l+r)>>1;
	    if(a>mid){
	        return query(a, b, mid+1, r, right(idx));
	    }
	    else if(b<=mid){
	        return query(a, b, l, mid, left(idx));
	    }
	    else{
	        Node ll = query(a, mid, l , mid, left(idx));
	        Node rr = query(mid+1, b, mid+1, r, right(idx));
	        return merge(ll, rr);
	    }
	}
};
SegmentTree tree;
int main(){
	int n;	
	icin(n);
	v.resize(n+1);
	for(int i=1;i<=n;i++){
		icin(v[i]);
	}
	tree.nodes.resize(4*n);
	tree.build(1, n, 1);
//	tree.print(1, n, 1);
	tree.query(4, 5,1, n, 1).print();
	
}