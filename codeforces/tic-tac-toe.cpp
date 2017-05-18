#include <iostream>
#include <vector>
using namespace std;

bool game(vector<vector<char> >& v)
{
	int count=0;
	for(int j=0;j<4;j++)
	{
		for(int i=1;i<=2;i++)
		{
			if(v[j][i-1]=='x' && v[j][i]=='x' && v[j][i+1]=='x')
				return true;
		}
	}
	for(int j=0;j<4;j++)
	{
		for(int i=1;i<=2;i++)
		{
			if(v[i-1][j]=='x' && v[i][j]=='x' && v[i+1][j]=='x')
				return true;
		}
	}
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			if(v[i-1][j-1]=='x' && v[i][j]=='x' && v[i+1][j+1]=='x')
				return true;
			if(v[i+1][j-1]=='x' && v[i][j]=='x' && v[i-1][j+1]=='x')
				return true;
		}
	}
	return false;
}

int main()
{
	vector<vector<char> > v(4,vector<char>(4));
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>v[i][j];
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(v[i][j]=='.')
			{
				v[i][j]='x';
				if(game(v))
				{
					cout<<"YES"<<endl;
					return 0;
				}
				else
				{
					v[i][j]='.';
				}
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}

/* 
	00 01 02 03
    10 11 12 13
    20 21 22 23
    30 31 32 33
*/