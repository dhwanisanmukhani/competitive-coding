#include <iostream>
using namespace std;

int main(){
	for(int x=100;x<1e3;x++){
		int i=x;
		printf("3\n");
		while(i){
			printf("%d ",i%10);
			i = i/10;
		}
		printf("\n");
	}
	for(int x=1e3; x<1e4;x++){
		int i=x;
		printf("4\n");
		while(i){
			printf("%d ",i%10);
			i = i/10;
		}
		printf("\n");
	}
	for(int x=1e4;x<1e5;x++){
		int i=x;
		printf("5\n");
		while(i){
			printf("%d ",i%10);
			i = i/10;
		}
		printf("\n");
	}
	// for(int x=1e5; x<1e6;x++){
	// 	int i=x;
	// 	printf("6\n");
	// 	while(i){
	// 		printf("%d ",i%10);
	// 		i = i/10;
	// 	}
	// 	printf("\n");
	// }
}