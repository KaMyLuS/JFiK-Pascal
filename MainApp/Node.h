#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define abs(a) ((a)<0 ? -(a) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

class Node
{
	private:
		int char_count; // czestosc danego znaku
		bool leaf; // czy lisc
		char ch; // znak w lisciu
		Node *left, *right; // lewy i prawy syn

	public:

		Node(bool _leaf, int ch_count, char _ch, Node *lt = NULL, Node *rt = NULL);
		bool isLeaf() const;
		int getCount() const;
		char getChar() const;
		Node* getLeft() const;
		Node* getRight() const;

		void setLeft(Node *x);
		void setRight(Node *x);
		void setLeaf(bool x);
		void setChar(char c);
};

class NodePointCompare
{
	public:
		bool operator() (const Node* lhs, const Node* rhs) const
		{
			return lhs->getCount() > rhs->getCount();
		}

};

#endif

