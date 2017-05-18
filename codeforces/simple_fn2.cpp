#include <bits/stdc++.h>
using namespace std;
int simple_function(vector<int>& flag1,vector<int>& flag2)
{
  int answer=0; 
  for(int i=1;i<=9;i++)
  {
    if(flag1[i]==1 && flag2[i]==1)
    {
      answer=answer*10+i;
    }
  }
  return answer;
}
 
int main()
{
  int t;
  cin>>t;
  while(t--){
    int n1,n2;
		cin>>n1>>n2;
    vector<vector<int> > flag1, flag2;
    flag1.assign(n1, vector<int>(10, 0));
    flag2.assign(n2, vector<int>(10, 0));
    string s1,s2;
    for(int i=0;i<n1;i++){
			cin>>s1;
      for(int j=0;j<s1.size();j++)
        flag1[i][s1[j]-'0']=1;
    }
    for(int i=0;i<n2;i++){
			cin>>s2;
      for(int j=0;j<s2.size();j++)
        flag2[i][s2[j]-'0']=1;
    }
	  int poss=0;
		for(int i=0;i<n1;i++)			// O(10^3 * 10^3 * 10^3)
  	{
    	for(int j=0;j<n2;j++)
    	{
      	if(simple_function(flag1[i],flag2[j])%2==0)
      	{
        	poss++;
      	}
    	}
  	}
  	float probability = float(poss)/(n1*n2);
		printf("%.3f\n", probability);
  }
  return 0;
} 