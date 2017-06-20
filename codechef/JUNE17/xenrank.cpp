#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int j=0;j<t;j++){
		int u, v;
		long long level;
		cin >> u >> v;
		level = u+v;
		long long total = (level * (level+1))/2;
		cout << total + u + 1 << endl;
	}
}