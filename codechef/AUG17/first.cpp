#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define icin(x) scanf("%d", &x);

int main(){
	int t;
	icin(t);
	for(int x=0;x<t;x++){
		int n;
		icin(n);
		int arr[n];
		for(int i=0;i<n;i++){
			icin(arr[i]);
		}
		vector<int> v(8, 0);
		int t=1, flag=0, mid;
		for(int i=0;i<n;i++){
			if(t>7){
				flag=1;
				break;
			}
			if(arr[i]<t){
				mid=i;
				break;
			}
			if(arr[i] == t)
				v[t]++;
			else if(arr[i] == t+1){
				t++;
				v[t]++;
			}
			else{
				flag=1;
			}
		}
		if(flag==1){
			cout<<"no"<<endl;
			continue;
		}
		for(int i=1;i<=7;i++){
			if(v[i]==0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			cout<<"no"<<endl;
			continue;
		}
		for(int i=mid;i<n;i++){
			v[arr[i]]--;
		}
		for(int i=1;i<7;i++){
			if(v[i]!=0){
				cout<<"no"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<"yes"<<endl;
	}	
}
