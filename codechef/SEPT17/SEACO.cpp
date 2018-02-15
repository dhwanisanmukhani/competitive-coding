#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;
const ll lint=1000000007;

class SegmentTree{
private:
	struct Node{
		ll l,r;
		ll data;
		ll lazy;
		Node(ll _l=0, ll _r=0,ll _data = 0, ll _lazy=0){
			init(_l, _r, _data, _lazy);
		}
		void init(ll _l, ll _r, ll _data, ll _lazy){
			l = _l;
			r = _r;
			data = _data;
			lazy = _lazy;
		}
		friend Node merge(const Node& left, const Node& right){
			ll data = max(left.data+left.lazy, right.data + right.lazy);
			return Node(left.l, right.r, data, 0);
		}
	};
	vector<Node> nodes;
	ll n;
public:
	void init(ll n){
		nodes.resize(4*n);
		build(1, n, 1);
	}
	void build(ll l, ll r, ll idx){
		if(l==r){
			nodes[idx].init(l, r, 0, 0);
			return;
		}
		ll mid = (l+r)>>1;
		build(l, mid, idx<<1);
		build(mid+1, r, idx<<1|1);
		nodes[idx] = merge(nodes[idx<<1], nodes[idx<<1|1]);
	}
	void percolate(ll idx){
		nodes[idx<<1].lazy = (nodes[idx].lazy + nodes[idx<<1].lazy)%(lint);
		nodes[idx<<1|1].lazy = (nodes[idx].lazy + nodes[idx<<1|1].lazy)%(lint);
		nodes[idx].lazy=0;
	}
	ll query(ll l, ll r, ll idx, ll a){
		if(l==r){
			return nodes[idx].lazy;
		}
		percolate(idx);
		ll mid = (l+r)>>1;
		if(a<=mid){
			return query(l, mid, idx<<1, a);
		}
		else{
			return query(mid+1, r, idx<<1|1, a);			
		}
	}
	void update(ll l, ll r, ll idx, ll a, ll b, ll lz){
		if(l==a && r==b){
			nodes[idx].lazy = (nodes[idx].lazy + lz)%(lint);
			return;
		}
		percolate(idx);
		ll mid = (l+r)>>1;
		if(b<=mid){
			update(l, mid, idx<<1, a, b, lz);
		}
		else if(a>mid){
			update(mid+1, r, idx<<1|1, a, b, lz);			
		}
		else{
			update(l, mid, idx<<1, a, mid, lz);
			update(mid+1, r, idx<<1|1, mid+1, b, lz);
		}
		nodes[idx] = merge(nodes[idx<<1], nodes[idx<<1|1]);		
	}
};

int main(){
	ll t;
	lcin(t);
	while(t--){
		ll n, m;
		lcin(n), lcin(m);
		SegmentTree command_count, arr_count;
		command_count.init(m);
		arr_count.init(n);
		vector<pair<ll, pair<ll, ll> > > v(1);
		ll type, l, r;
		for(ll i=0;i<m;i++){
			lcin(type), lcin(l), lcin(r);
			v.push_back(make_pair(type, make_pair(l, r)));
		}
		for(ll i=m;i>=1;i--){
			if(v[i].first == 2){
				ll num = command_count.query(1, m, 1, i);
				command_count.update(1, m, 1, v[i].second.first, v[i].second.second, 1+num);
			}
		}
		for(ll i=1;i<=m;i++){
			if(v[i].first == 1){
				ll num = command_count.query(1, m, 1, i);
				arr_count.update(1, n, 1, v[i].second.first, v[i].second.second, 1+num);
			}
		}
		for(ll i=1;i<=n;i++){
			cout<<arr_count.query(1, n, 1, i)<<" ";
		}
		cout<<endl;
	}
}