#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

class Compare{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second>n2.second;
    }
};

int main(){
	int t;
	icin(t);
	for(int m=0;m<t;m++){
		int n, d;
		ll total=0;
		icin(n), icin(d);
		vector<vector<pair<ll, ll> > > arrival_day(100001); 
		for(int i=0;i<n;i++){
			int day;
			ll lectures, sadness;
			icin(day);
			lcin(lectures), lcin(sadness);
			total += lectures*sadness;
			arrival_day[day].push_back(make_pair(lectures, sadness));
		}
		priority_queue<pair<ll, ll>, vector<pair<int, int> >, Compare> pq;
		ll schedule[d+1];
		ll count=0;
		for(int i=1; i<=d; i++){
			for(int j=0;j<arrival_day[i].size();j++){
				pair<ll, ll> p = arrival_day[i][j];
				pq.push(p);
			}
			if(pq.empty())
				continue;
			pair<ll, ll> p = pq.top();
			pq.pop();
			schedule[i]=p.second;
			count += schedule[i];
			p.first--;
			if(p.first != 0)
				pq.push(p);
		}
    	printf("%lld\n", total - count);
    }	
}