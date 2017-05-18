#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define icin(x) scanf("%d", &x)
#define lcin(x) scanf("%lld", &x)
#define SZ (26)
typedef long long LL;

class Trie{
private:
	class Node{
	public:
		char data;
		int n_words, n_childs;
		Node* parent;
		vector<Node*> childs;
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
			cout << data;
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
		node->n_words++;
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
				cout<<endl;
			}
		}

	}
};

int main()
{
	Trie tree;
	tree.insert("dhwani");
	tree.insert("tatti");
	tree.insert("halleluya");
	tree.print();
	tree.del("halleluya");
	tree.print();
	cout<<tree.search("dhwani")<<endl;
}

