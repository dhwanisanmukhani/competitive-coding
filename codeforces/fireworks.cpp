#include <iostream>
using namespace std;
int n;
int a[51];
int visits[310][310];
int arr[310][310][10][50];
int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};

void check(int x,int y,int dir,int level)
{
	if(level>=n)
		return;
	if(arr[x][y][dir][level]==1)
		return;
	arr[x][y][dir][level]=1;
	visits[x][y]=1;
	int x_co=x;
	int y_co=y;
	for(int i=1;i<a[level];i++)
	{
		x_co+=fx[dir];
		y_co+=fy[dir];
		visits[x_co][y_co]=1;
	}
	check(x_co+fx[(dir+1)%8],y_co+fy[(dir+1)%8],(dir+1)%8,level+1);
	check(x_co+fx[(dir+7)%8],y_co+fy[(dir+7)%8],(dir+7)%8,level+1);
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	check(150,150,0,0);
	int count=0;
	for(int i=0;i<310;i++)
	{
		for(int j=0;j<310;j++)
		{
			if(visits[i][j]==1)
				count++;
		}
	}
	cout<<count<<endl;
}