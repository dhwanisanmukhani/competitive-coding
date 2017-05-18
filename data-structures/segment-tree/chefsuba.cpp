#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int lt, rt;
	int sum;
	int l;
	void print(){
		cout<<lt<<" "<<rt<<" "<<sum<<" "<<l<<endl;
	}
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
		build(1, A.size()-1, 1);
	}
	void build(int l, int r, int i)
	{
		if (l == r)
		{
			make_node(A[l], i, l);
		}
		else
		{
			build(l, (l+r)/2, 2*i);
			build(((l+r)/2) + 1, r, (2*i) + 1);
			v[i] = merge(v[2*i], v[(2*i) + 1]);
		}
	}
	void make_node(int data, int i, int l)
	{
		v[i].lt = v[i].rt = l;
		v[i].sum = data;
		v[i].l = 0;
	}
	node merge(node n1, node n2)
	{
		node n;
		n.lt = n1.lt;
		n.rt = n2.rt;
		n.sum = max(n1.sum + n1.l, n2.sum + n2.l);
		n.l = 0;
		return n;
	}
	node query(int l, int r, int i, int a, int b, int lazy)
	{
		if(a == l && b == r)
		{
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
	void up_range(int l, int r, int i, int a, int b, int lazy)
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
			up_range(l, mid, 2*i, a, b, lazy);
		}
		else if(a > mid)
		{
			up_range(mid + 1, r, (2*i) + 1, a, b, lazy);
		}
		else
		{
			up_range(l, mid, 2*i, a, mid, lazy);
			up_range(mid + 1, r, (2*i) + 1, mid+1, b, lazy);
		}
		v[i] = merge(v[2*i], v[(2*i)+1]);
	}
	void up_point(int l, int r, int i, int ci, int data)
	{
		int mid = (l+r)/2;
		if(l == r)
		{
			make_node(data, i, l);
		}
		else
		{
			percolate(i);
			if(ci <= mid)
				up_point(l, mid, 2*i, ci, data);
			else
				up_point(mid+1, r, (2*i)+1, ci, data);
			v[i] = merge(v[2*i], v[(2*i)+1]);
		}
	}
};

int main()
{
	int n, k, p;
	cin >> n >> k >> p;
	vector<int> a(n+1);
	if(k == 1)
	{
		int flag = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			if(a[i] == 1)
				flag = 1;
		}
		for (int i = 0; i < p; ++i)
		{
			char c;
			cin >> c;
			if(c == '?')
				cout<<flag <<endl;
		}
	}
	else if(k > n)
	{
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			if(a[i] == 1)
				count ++;
		}
		for (int i = 0; i < p; ++i)
		{
			char c;
			cin >> c;
			if(c == '?')
				cout<<count <<endl;
		}
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
		}
		vector<int> dp(n+1,0);
		for (int i = 1; i <= k; ++i)
		{
			dp[i] = dp[i-1] + a[i];
		}
		for(int i = k+1; i <=n; i++)
		{
			dp[i] = dp[i-1] - a[i-k] + a[i];
		}
		segment_tree st(dp);
		int last = n;
		for(int i = 0; i < p; i++)
		{
			char c;
			cin >> c;
			if(c == '!')
			{
				int temp;
				temp = last;
				st.up_point(1, n, 1, last, a[temp]);
				last--;
				if(last < 1)
					last = n;
				if(a[temp] == 1)
				{
					if(temp != n)
					{
						if(temp + k <= n+1)
						{

							st.up_range(1, n, 1, temp + 1, temp + k - 1, 1);
						}
						else
						{
							st.up_range(1, n, 1, temp + 1, n, 1);
							st.up_range(1, n, 1, 1, k-1 - (n-temp), 1);
						}
					}
					else
					{
						st.up_range(1, n, 1, 1, k-1, 1);
					}
				}
			}
			else
			{
				node mai = st.query(1, n, 1, 1, n, 0);
				cout<< mai.sum + mai.l <<endl;
			}
		}
	}
}