#include <iostream>
#include <string>
using namespace std;
 
int main() {
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
	    string str;
	    cin>>str;
	    int current=1, maximum=1;
	    char last=str[0];
	    int m;
	    for(m=0;m<str.length();m++){
	        if(str[m]!='=')
	            break;
	    }
	    if(m==str.length()){
	        cout<<"1"<<endl;
	        continue;
	    }
	    for(int j=1;j<str.length();j++){
	        if(last=='='){
	            last = str[j];
	            continue;
	        }
	        if(str[j]==last){
	            current++;
	        }
	        else if(str[j]=='='){
	            continue;
	        }
	        else{
	            if(maximum<current)
	                maximum=current;
	            current=1;
	            last=str[j];
	        }
	    }
	    if(maximum<current)
	       maximum=current;
	    cout<<maximum+1<<endl;
	}
	return 0;
}