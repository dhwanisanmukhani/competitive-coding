#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long LL;

int C[31][31];
void precompute(){
	C[0][0]=1;
	C[1][0]=C[1][1]=1;
	for(int i=2;i<31;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j] = C[i-1][j-1] + C[i-1][j];
	}
}
int n;
LL k;

bool check(LL a, LL b){
	return a <= (k/b);
}

vector<LL> v;
map<LL, int> m;

struct Node{
	vector<LL> data;
	vector<LL> cnt;
	void init(LL val, int c){
		data= {1};
		cnt = {1};

		LL pdt = 1;
		for(int i=1;i<=c;i++){
			if(!check(pdt, val))
				break;
			pdt = pdt * val;
			data.push_back(pdt);
			cnt.push_back(C[c][i]);
		}
	}
	void print(){
		cout<<"Printing node..."<<endl;
		for(auto d:data){
			cout<<d<<" ";
		}
		cout<<endl;
		for(auto c:cnt){
			cout<<c<<" ";
		}
		cout<<endl;
	}
};
vector<Node> nodes;


LL recursive(int idx, LL pdt){
	LL ret=0;
	Node* node = &nodes[idx];

	if(idx==nodes.size()-1){
		for(int i=0;i<node->data.size();i++){
			if(check(pdt, node->data[i]))
				ret += node->cnt[i];
			else
				break;
		}
		return ret;
	}
	for(int i=0;i<node->data.size();i++){
		if(check(pdt, node->data[i]))
			ret += node->cnt[i]*recursive(idx+1, pdt*node->data[i]);
		else
			break;
	}
	return ret;
}
int main(){
	precompute();
	icin(n);
	lcin(k);
	v.resize(n);
	for(int i=0;i<n;i++){
		lcin(v[i]);
		m[v[i]]=0;
	}
	for(auto _v:v){
		m[_v]++;
	}
	Node node;
	for(auto p:m){
		node.init(p.first, p.second);
		nodes.push_back(node);
	}
	printf("%lld\n", recursive(0, 1)-1);
}