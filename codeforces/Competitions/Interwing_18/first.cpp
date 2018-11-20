#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define icin(x) scanf("%d", &x)
typedef long long ll;
using namespace std;

class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;        //Size of set
    int number_of_sets;
    DSU(int _n){
        number_of_sets=_n;
        parent.resize(_n);
        rank.resize(_n);
        size.resize(_n);
        for(int i=0;i<_n;i++){
            parent[i]=i;rank[i]=1;size[i]=1;
        }
    }
    ~DSU(){
        number_of_sets=0;
        parent.clear();rank.clear();size.clear();
    }
    int root(int i){
        return (parent[i]==i) ? i : (parent[i] = root(parent[i]));
    }
    int sizeSet(int i){
        return (parent[i]==i) ? size[i] : size[i] = size[root(i)];
    }
    void unionSet(int i,int j){
        i=root(i);j=root(j);
        if(i==j)return;
        number_of_sets--;
        if(rank[i]<rank[j])swap(i,j);
        if(rank[i]==rank[j])rank[i]++;
        parent[j]=i;
        size[i] += size[j]; 
    }
    bool isSameSet(int i,int j){
        return root(i)==root(j);
    }
};

int main(){
    int n, m;
    icin(n), icin(m);
    DSU friends(n);
    for(int i=0;i<m;i++){
    	int a, b;
    	icin(a), icin(b);
    	if(!friends.isSameSet(a, b)){
    		friends.unionSet(a, b);
    	}
    }
    int t = friends.sizeSet(1);
    int mmin = 1e9, mmax = -1e9;
    int attacks[n];
    int time = 0;
    for(int i=0;i<n;i++){
    	icin(attacks[i]);
    }
    if(n == t){
    	printf("0\n");
    	return 0;
    }
    
    printf("%d\n", time);
}

