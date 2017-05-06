#ifndef __BSTREE_H__
#define __BSTREE_H__

#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class BSTree {

private:
	Node* root;

private:
	void insert(const string &, Node*);
	bool search(const string &, Node*) const;
	void preOrder(Node*) const;
	void inOrder(Node*) const;
	void postOrder(Node*) const;
	string smallest(Node*) const;
	string largest(Node*) const;
	int height(const string &, Node*) const;
	int heightCounter(Node*) const;
	void remove(const string &, Node*, Node*);
	void searchNode(const string&, Node*, Node*);

public:
	BSTree() : root(0) {}
	void insert(const string &);
	bool search(const string &) const;
	void inOrder() const;
	void postOrder() const;
	void preOrder() const;
	string smallest() const;
	string largest() const;
	int height(const string &) const;
	void remove(const string &);
};

#endif
