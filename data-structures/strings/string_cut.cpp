#include <iostream>
#include <sstream>
#include <iterator>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    string str;
    int n;
    scanf("%d ",&n);
    for(int a=0;a<n;a++){
    	getline(cin, str);
     	istringstream iss(str);
     	vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
     	int sz = tokens.size();
        for(int i=0;i<sz;i++){
            for(int j=0;j<tokens[i].size();j++){
                if(j==0){
                    if(tokens[i][j]>='a' && tokens[i][j]<='z'){
                        tokens[i][j] = tokens[i][j]-32;
                    }
                }
                else{
                    if(tokens[i][j]>='A' && tokens[i][j]<='Z'){
                        tokens[i][j] = tokens[i][j]+32;
                    }
                }
            }
        }
        if(sz==1)
            cout<<tokens[0]<<endl;
        else{
            for(int i=0;i<sz-1;i++){
                cout<<tokens[i][0]<<". ";
            }
            cout<<tokens[sz-1]<<endl;
        }
    }
	return 0;
}