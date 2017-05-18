#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int lt, rt;
	int mmax;
	int mmin;
	int sum;
	int l;
	node(){
		// lt=rt=0;
		// mmax=0;
		// mmin=int(1e9);
		// sum=0;
		// l=0;
	}
	// void print(){
	// 	cout<<"----"<<endl;
	// 	cout<<lt<<" "<<rt<<endl;
	// 	cout<<mmin<<" "<<mmax<<" "<<sum<<endl;;
	// 	cout<<l<<endl;
	// 	cout<<endl;
	// }
};

class segment_tree
{
private:
	vector<int> A;
	vector<node> v;
public:
	segment_tree(vector<int> &array)
	{
		A = array;
		v.resize(4*(A.size()));
		build(1, A.size(), 1);
	}
	void build(int l, int r, int i)
	{
		if (l == r)
		{
			make_node(A[l-1], i, l);
		}
		else
		{
			build(l, (l+r)/2, 2*i);
			build((l+r)/2 + 1, r, (2*i) + 1);
			v[i] = merge(v[2*i], v[(2*i) + 1]);
		}
	}
	void make_node(int data, int i, int l)
	{
		v[i].lt = v[i].rt = l;
		v[i].mmax = data;
		v[i].mmin = data;
		v[i].sum = data;
		v[i].l = 0;
	}
	node merge(node n1, node n2)
	{
		node n;
		n.lt = n1.lt;
		n.rt = n2.rt;
		n.mmax = max(n1.mmax + n1.l, n2.mmax + n2.l);
		n.mmin = min(n1.mmin + n1.l, n2.mmin + n2.l);
		n.sum = n1.sum + n2.sum;
		n.sum += (n1.l)*(n1.rt - n1.lt + 1);
		n.sum += (n2.l)*(n2.rt - n2.lt + 1);
		n.l = 0;
		return n;
	}
	node query(int l, int r, int i, int a, int b, int lazy)
	{
		if(a == l && b == r)
		{
			//v[i].print();
			return v[i];
		}
		percolate(i);
		if(b <= (l+r)/2)
		{
			return query(l, (l+r)/2, 2*i, a, b, lazy);
		}
		else if( a > (l+r)/2)
		{
			return query((l+r)/2+1, r, (2*i) + 1, a, b, lazy);
		}
		else
		{
			node n1, n2;
			n1 = query(l, (l+r)/2, 2*i, a, (l+r)/2, lazy);
			n2 = query((l+r)/2 + 1, r, 2*i + 1, (l+r)/2 + 1, b, lazy);
			return merge(n1, n2);
		}
	}
	void percolate(int i)
	{
		v[(2*i)].l += v[i].l;
		v[(2*i) + 1].l += v[i].l;
		v[i].l = 0;
	}
	void updatep(int l, int r, int i, int a, int b, int lazy)
	{
		if (a == l && b == r)
		{
			v[i].l += lazy;
			return;
		}
		int mid = (l+r)/2;
		percolate(i);
		if(b <= mid)
		{
			updatep(l, mid, 2*i, a, b, lazy);
		}
		else if(a > mid)
		{
			updatep(mid + 1, r, (2*i) + 1, a, b, lazy);
		}
		else
		{
			updatep(l, mid, 2*i, a, mid, lazy);
			updatep(mid + 1, r, (2*i) + 1, mid+1, b, lazy);
		}
	}
};

int main()
{
	vector<int> v = {1, 10, 8, 2, 0, 57, 64, 9, 23, 11};
	segment_tree st(v);
	node n = st.query(1, 10, 1, 2, 8, 0);
	cout << n.mmax << endl;
	st.updatep(1, 10, 1, 2, 2, 89);
	node n1 = st.query(1, 10, 1, 2, 8, 0);
	cout << n1.mmax << endl;
}