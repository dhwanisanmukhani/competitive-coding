#include <iostream>
#include <cstdio>
#include <map>
using namespace std;


int main(){
	int t;
	cin >> t;
	int arr[49] = {4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346, 355, 378, 382, 391, 438, 454, 483, 517, 526, 535, 562, 576, 588, 627, 634, 636, 645, 648, 654, 663, 666, 690, 706, 728, 729, 762, 778, 825, 852, 861, 895, 913, 915, 922, 958, 985};
	map<int, int> m;
	for(int i=0;i<49;i++){
		m[arr[i]]=1;
	}
	while(t--){
		int n;
		cin >> n;
		string s;
		for(int i=0;i<n;i++){
			cin >>s;
		}		
		int x;
		cin >>x;
		int flag=0, temp;	
		for(int i=0;i<x;i++){
			cin >> temp;
			if(m[temp]==1)
				flag=1;
		}
		if(flag ==1)
			printf("Voila\n");
		else
			printf("Sorry\n");
	}
}
