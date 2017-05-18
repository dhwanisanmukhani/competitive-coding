#include <iostream>
#include <vector>
using namespace std;
int main(){
	int i,n,k,score,qualified=0;
	vector<int>scores;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>score;
		scores.push_back(score);
	}
	for(i=0;i<n;i++)
	{
		if(scores[i] >= scores[k-1] && scores[i]>0)
		{
			qualified++;
		}
	}
	cout <<qualified<<endl;
	return 0;
}