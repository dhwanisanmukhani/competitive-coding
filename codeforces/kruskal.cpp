#include <iostream>
#include <vector>
using namespace std;

class disjoint_set
{
public:
	class node
	{
	public:
		int data;
		int rank;
		node* p;
	};
public:
	node* make_set(int x)
	{
		node* temp;
		temp=new(struct node);
		temp->data=x;
		temp->p=temp;
		temp->rank=0;
		return temp;
	}
	void link_set(node* x,node* y)
	{
		if(x->rank > y->rank)
		{
			y->p=x;
		}
		else
		{
			x->p=y;
			if(x->rank==y->rank)
			{
				y->rank=y->rank+1;
			}
		}
	}
	node* find_set(node* x)
	{
		if(x != x->p)
			x->p=find_set(x->p);
		return x->p;
	}
	void union_set(node* x,node* y)
	{
		link_set(find_set(x),find_set(y));
	}
};

int main()
{
	disjoint_set dsu;
	int n_vertices,n_edges;
	int temp;
	cin >> n_vertices >> n_edges;
	int num;
	disjoint_set::node* vertices[n_vertices];
	for(int i=0;i<n_vertices;i++)
	{
		cin>>num;
		vertices[i]=dsu.make_set(num);
	}
	vector<pair<int,int> > edges;
	vector<int> weight(n_edges);
	int a,b;
	for(int i=0;i<n_edges;i++)
	{
		cin>>a>>b;
		edges.push_back(make_pair(a,b));
		cin>>weight[i];
	}
	for(int i=0;i<n_edges;i++)
	{
		for(int j=0;j<=n_edges-i-1;j++)
		{
			if(weight[i]>weight[j])
			{
				temp=weight[i];
				weight[i]=weight[j];
				weight[j]=temp;
				
				temp=edges[i].first;
				edges[i].first=edges[j].first;
				edges[i].first=temp;

				temp=edges[i].second;
				edges[i].second=edges[j].second;
				edges[i].second=temp;
			}
		}
	}
	for(int i=0;i<n_edges;i++)
	{
		if( dsu.find_set(vertices[edges[i].first-1]) == dsu.find_set(vertices[edges[i].second-1]) )
		{
			continue;
		}
		else
		{
			dsu.union_set(vertices[edges[i].first-1],vertices[edges[i].second-1]);
		}
	}
	return 0;
}