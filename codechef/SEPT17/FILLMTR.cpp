#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
typedef long long ll;

vector<int> arr, size, color;
vector<vector<int> > adjlist;
vector<int> visited;

void initialize(int N){
    for(int i = 0;i<=N;i++){
        arr[i] = i ;
        size[i] = 1;
    }
}

int root (int i){
    while(arr[i] != i){
        arr[i] = arr[arr[i]] ; 
        i = arr[i]; 
    }
    return i;
}


void wunion(int A,int B){
    int root_A = root(A);
    int root_B = root(B);
    if(size[root_A] < size[root_B ]){
        arr[root_A] = arr[root_B];
        size[root_B] += size[root_A];
    }
    else{
        arr[root_B] = arr[root_A];
        size[root_A] += size[root_B];
    }

}

bool find(int A,int B){
    if(root(A)==root(B))       
        return true;
    else
        return false;
}

int main(){
    int t;
    icin(t);
    while(t--){
        int n, q, flag=0;
        icin(n), icin(q);
        arr.resize(n+1);
        size.resize(n+1);
        initialize(n);
        int a, b, val;
        vector<pair<int, pair<int, int> > > v;
        adjlist.resize(n+1);
        visited.assign(n+1, 0);
        for(int i=0;i<q;i++){
            icin(a), icin(b), icin(val);
            v.push_back(make_pair(val, make_pair(a, b))); 
            if(val==0)
                wunion(a, b);  
        }
        for(int i=0;i<q;i++){
            if(v[i].first == 1){
                if(find(v[i].second.second, v[i].second.first)){
                    printf("no\n");
                    flag=1;
                    break;
                }
                int root_A = root(v[i].second.first);
                int root_B = root(v[i].second.second);
                adjlist[root_A].push_back(root_B);
                adjlist[root_B].push_back(root_A);
            }
        }
        if(flag==0){
            queue<int> q;
            color.assign(n+1,-1);
            for(int i=0;i<=n;i++){
                if(color[i]==-1){
                    q.push(i);
                    color[i]=0;
                    bool isBiparite=true;
                    while(!q.empty() && isBiparite){
                        int u = q.front();
                        q.pop();
                        for(int j=0;j<adjlist[u].size();j++){
                            int v = adjlist[u][j];
                            if(color[v]==-1){
                                color[v]=1-color[u];
                                q.push(v);
                            }
                            else if(color[v]==color[u]){
                                isBiparite=false;
                                break;
                            }
                        }
                    }
                    if(!isBiparite){
                        flag=1;
                        printf("no\n");
                        break;
                    }
                }
            }
        }
        if(flag==0)
            printf("yes\n");
    }
}