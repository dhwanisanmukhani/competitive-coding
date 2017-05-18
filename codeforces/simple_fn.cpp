#include <bits/stdc++.h>
using namespace std;
int simple_function(int* flag1,int* flag2)
{
 
  int answer=0; 
  for(int i=1;i<=9;i++)
  {
    if(flag1[i]==-1 && flag2[i]==-1)
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
  for(int a=0;a<t;a++)
  {
	int n1,n2;
	cin>>n1>>n2;
	string s1[n1],s2[n2];
	for(int i=0;i<n1;i++)
	{
		cin>>s1[i];
	}
	for(int i=0;i<n2;i++)
	{
		cin>>s2[i];
	}
  int flag1[n1][10], flag2[n2][10];
  for(int j=0;j<n1;j++)
  {
 		 for(int i=0;i<10;i++)
    		flag1[j][i] = 0;
  }
  for(int j=0;j<n2;j++)
  {
 		 for(int i=0;i<10;i++)
    		flag2[j][i] = 0;
  }
 	for(int j=0;j<n1;j++)
  {
  	for(int i=0;i<s1[j].size();i++)
    	flag1[j][s1[j][i]-'0'] = -1;
  }
  for(int j=0;j<n2;j++)
  {  
  	for(int i=0;i<s2[j].size();i++)
    	flag2[j][s2[j][i]-'0'] = -1;
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
//bas test case baaki hai
// ok cool
 
/// DO NOT TYPE BELOW THIS ///
// Existing mistakes in the above code (continue, you can resolve later)
// 1. There are multiple test cases (as mentioned in question). Please take care of that
 
// Suggestions
// 1. Don't repeat code (try making diff functions as much as possible)
  