#include "Node.h"

Node::Node(bool _leaf, int ch_count, char _ch, Node *lt, Node *rt)
{
	leaf = _leaf;
	char_count = ch_count;
	ch = _ch;
	left = lt;
	right = rt;
}

bool Node::isLeaf() const
{
	return leaf;
}

int Node::getCount() const
{
	return char_count;
}

char Node::getChar() const
{
	return ch;
}

Node* Node::getLeft() const
{
	return left;
}

Node* Node::getRight() const
{
	return right;
}

//-------

void Node::setLeft(Node *x)
{
	left = x;
}

void Node::setRight(Node *x)
{
	right = x;
}

void Node::setLeaf(bool x)
{
	leaf = x;
}

void Node::setChar(char c)
{
	ch = c;
}
