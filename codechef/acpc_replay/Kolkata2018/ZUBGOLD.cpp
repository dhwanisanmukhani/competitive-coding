#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)

int main(){
	int t;
	icin(t);
	while(t--){
		double x[3], y[3], z[3], ux, uy, uz, t[3], c[3], d[3];
		cin >> x[0] >> y[0] >> z[0];
		cin >> x[1] >> y[1] >> z[1];
		cin >> x[2] >> y[2] >> z[2];
		ux = ((y[1]-y[0])*(z[2]-z[0])) - ((z[1]-z[0])*(y[2]-y[0]));
		uy = ((z[1]-z[0])*(x[2]-x[0])) - ((x[1]-x[0])*(z[2]-z[0]));
		uz = ((x[1]-x[0])*(y[2]-y[0])) - ((x[2]-x[0])*(y[1]-y[0]));
		double mag = sqrt((ux*ux)+(uy*uy)+(uz*uz));
		ux /= mag;
		uy /= mag;
		uz /= mag;
		double a[3][3];
		a[0][0] = ux*ux;
		a[0][1] = (ux*uy) - uz;
		a[0][2] = (ux*uz) + uy;
		a[1][0] = (ux*uy) + uz;
		a[1][1] = uy*uy;
		a[1][2] = (uy*uz) - ux;
		a[2][0] = (uz*ux) - uy;
		a[2][1] = (uz*uy) + ux;
		a[2][2] = uz*uz;
		t[0] = x[1] - x[0];
		t[1] = y[1] - y[0];
		t[2] = z[1] - z[0];
		double temp=0;
		for(int i=0;i<3;i++){
			temp=0;
			for(int j=0;j<3;j++){
				temp += a[i][j]*t[j];
			}
			c[i]=temp;
		}
		c[0] += x[1];
		c[1] += y[1];
		c[2] += z[1];
		t[0] = x[0] - x[2];
		t[1] = y[0] - y[2];
		t[2] = z[0] - z[2];
		temp=0;
		for(int i=0;i<3;i++){
			temp=0;
			for(int j=0;j<3;j++){
				temp += a[i][j]*t[j];
			}
			d[i]=temp;
		}
		d[0] += x[2];
		d[1] += y[2];
		d[2] += z[2];
		
		for(int i=0;i<3;i++){
			printf("%.8f ", (c[i]+d[i])/2); 
		}
		printf("\n");
	}
}
