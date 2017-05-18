#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
#define pr(x) printf("%s\n", x.c_str());
#define SZ (26)
typedef long long LL;
vector<string> filters;

class Trie{
private:
	class Node{
	public:
		char data;
		int n_words, n_childs;
		Node* parent;
		vector<Node*> childs;
		string a;
		Node(char _data=0){
			data = _data;
			n_words = 0;
			n_childs = 0;
			childs.assign(SZ, NULL);
		}
		~Node(){
			for(auto node:childs){
				if(node)
					delete node;
				node = NULL;
			}
		}
		Node(const Node& s){
			*this = s;	
		}
		Node& operator=(const Node& s){
			data = s.data; n_words = s.n_words, n_childs = s.n_childs;
			for (int i = 0; i < SZ; ++i)
			{
				if(s.childs[i] != NULL)
				{
					childs[i] = new Node();
					*childs[i] = *s.childs[i];
				}
			}
			return *this;	
		}
		const void print()
		{
			if(n_words > 0 && n_childs == 0)
			{
				filters.push_back(a);
			}
			for (int i = 0; i < SZ; ++i)
			{
				if(childs[i] != NULL)
					childs[i]->print();
			}
		}
		bool is_empty(char c)
		{
			return childs[c-'a'] == NULL;
		}
		void set(char c)
		{
			childs[c-'a'] = new Node();
			childs[c-'a'] -> data = c;
			childs[c-'a'] -> n_words = 0;
			n_childs++;
		}
		Node* get(char c){
			return childs[c-'a'];
		}
		void par(char c)
		{
			childs[c-'a']->parent = this;
		}
		void mark()
		{
			n_words++;
		}
		void erase_mark()
		{
			n_words--;
		}
		void erase_child()
		{
			n_childs--;
		}
		Node* get_par()
		{
			return parent;
		}
		int get_child()
		{
			return n_childs;
		}
		int get_words()
		{
			return n_words;
		}
		char get_data()
		{
			return data;
		}
		void set_child(char c)
		{
			childs[c-'a']=NULL;
		}
		void set_str(string s)
		{
			a = s;
		}
	};
	Node root;
public:
	void insert(string s){
		Node* node = &root;
		for(char c:s){
			if(node->is_empty(c))
				node->set(c);
			node->par(c);
			node = node->get(c);
		}
		node->mark();
		node->set_str(s);
	}
	int search(string s){
		Node* node = &root;
		for(char c:s){
			if(node->is_empty(c))
				return -1;
			node = node->get(c);
		}
		if(node->get_words())
			return 1;
		else
			return 0;
	}
	void del(string s){
		Node* node = &root;
		for(char c:s){
			node = node->get(c);
		}
		delc(node);
	}
	void delc(Node* node)
	{
		Node* temp;
		if(node->get_child())
		{
			node->erase_mark();
			return;
		}
		temp = node->get_par();
		temp->erase_child();
		temp->set_child(node->get_data());
		delete node;
		node = NULL;
		delc(temp);
	}
	void print()
	{
		Node* node = &root;
		Node* temp;
		for (int i = 0; i < SZ; ++i)
		{
			temp = node->get(i+'a');
			if(temp)
			{
				temp->print();
			}
		}
	}
	string prefix(string s)
	{
		string ret;
		Node* node = &root;
		for(char c:s){
			if(node->is_empty(c))
			{
				ret.push_back(c);
				return ret;
			}
			ret.push_back(c);
			node = node->get(c);
		}
		return "NO";
	}
};

int main()
{
	Trie tree1;
	int n;
	vector<string> v;
	cin >> n;
	char c;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> c;
		cin >> s;
		if(c == '+')
			tree1.insert(s);
		else
		{
			v.push_back(s);
		}
	}
	Trie tree2;
	for (int i = 0; i < v.size(); ++i)
	{
		if(tree1.prefix(v[i]) != "NO")
			tree2.insert(tree1.prefix(v[i]));
		else
		{
			cout << "-1"<<endl;
			return 0;
		}
	}
	tree2.print();
	printf("%lu\n", filters.size());
	for (int i = 0; i < filters.size(); ++i)
	{
		pr(filters[i]);
	}
	return 0;
}


