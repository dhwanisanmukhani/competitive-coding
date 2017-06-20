#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;

#define icin(x) scanf("%d", &x)
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;

const int N = int(1e6)+1;
vector<int> primes, arr;
vector<vector<pair<int, int> > > factors;

void factorization_sieve(int n){
	primes.assign(n, 1);
	factors.assign(n, vector<pair<int, int> >());
	primes[0] = primes[1] = 0;
	for(int i=2;i<=n;i++){
		if(primes[i]==0)
			continue;
		factors[i].pb(mp(i, 1));
		for(int j=i<<1;j<=n;j+=i){
			primes[j]=0;
			int tmp = j/i;
			if(tmp%i){
				factors[j].pb(mp(i, 1));
			}
			else{
				factors[j].pb(mp(i, factors[tmp].back().second + 1));
			}
		}
	}
}

class SegmentTree{
private:
	struct Node{
		int l,r;
		int data;
		Node(int _l=0, int _r=0, int _data = 0){
			init(_l, _r, _data);
		}
		void init(int _l, int _r, int _data){
			l = _l;
			r = _r;
			data = _data;
		}
		friend Node merge(const Node& left, const Node& right){
			return Node(left.l, right.r, left.data + right.data);
		}
	};
	vector<Node> nodes;
	int n;
	void point_update(int l, int r, int idx, int a, int new_data){
		if(l==r){
			nodes[idx].data += new_data;
			return;
		}
		int mid=(l+r)>>1;
		if(a<=mid){
			point_update(l, mid, idx<<1, a, new_data);
		}
		else{
			point_update(mid+1, r, idx<<1|1, a, new_data);
		}
		nodes[idx] = merge(nodes[idx<<1], nodes[idx<<1|1]);
	}
	int query(int l, int r, int idx, int a, int b){
		if(l==a && r==b){
			return nodes[idx].data;
		}
		int mid = (l+r)>>1;
		if(b<=mid){
			return query(l, mid, idx<<1, a, b);
		}
		if(a>mid){
			return query(mid+1, r, idx<<1|1, a, b);
		}
		return query(l, mid, idx<<1, a, mid) + query(mid+1, r, idx<<1|1, mid+1, b);
	}
public:
	void init(int _n){
		n = _n;
		nodes.resize(4*n);
		build(1, n, 1);
	}
	void build(int l, int r, int idx){
		if(l==r){
			nodes[idx].init(l, r, 0);
			return;
		}
		int mid = (l+r)>>1;
		build(l, mid, idx<<1);
		build(mid+1, r, idx<<1|1);
		nodes[idx] = merge(nodes[idx<<1], nodes[idx<<1|1]);
	}


	void update(int a, int data){
		point_update(1, n, 1, a, data);
	}
	int query(int a, int b){
		if(a>b)
			return 0;
		return query(1, n, 1, a, b);
	}
};

struct Query{
	int l, r, x, y;
	void init(int _l, int _r, int _x, int _y){
		l=_l;
		r=_r;
		x=_x;
		y=_y;
	}
};
vector<Query> queries;
map<pair<int, int> , int> m;
SegmentTree tree;

void insert(int data){
	auto& factor = factors[data];
	for(auto p:factor){
		tree.update(p.first, p.second);
	}
}
int main(){
	factorization_sieve(N);
	int n;
	icin(n);
	arr.resize(n+1);
	for(int i=1;i<=n;i++){
		icin(arr[i]);
	}
	int t;
	cin >> t;
	queries.resize(t);
	for(int s=0;s<t;s++){
		int l, r, x, y;
		icin(l), icin(r), icin(x), icin(y);
		queries[s].init(l, r, x, y);
		m[pii(l-1, x-1)]=0;
		m[pii(l-1, y)]=0;
		m[pii(r, x-1)]=0;
		m[pii(r, y)]=0;
	}
	tree.init(N-1);
	int idx=0;
	for(auto it=m.begin(); it!=m.end();it++){
		int r, y;
		r = it->first.first;
		y = it->first.second;
		while(idx<r){
			idx++;
			insert(arr[idx]);
		}
		m[pii(r, y)] = tree.query(1, y);
	}
	for(int s=0;s<t;s++){
		int l = queries[s].l, r=queries[s].r, x=queries[s].x, y=queries[s].y;
		int ans = m[pii(r, y)] - m[pii(r, x-1)] - m[pii(l-1, y)] + m[pii(l-1, x-1)];
		printf("%d\n", ans);
	}
	return 0;
}