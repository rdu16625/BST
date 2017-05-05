#include "BSTree.h"

#include <iostream>
#include <string>


using namespace std;

// insert value into correct node
void BSTree::insert(const string &inserted)
{
    insert(inserted, root);
}

void BSTree::insert(const string &inserted, Node* curr)
{
    if (root == 0)
    {
        root = new Node();
        root->data = inserted;
    }
    else if (curr->isLeaf())
    {
        if (inserted < curr->data)
        {
            curr->left = new Node();        // new node is initialized as leaf.
            curr->left->data = inserted;
        }
        else if (inserted > curr->data)
        {
            curr->right = new Node();       // new node is initialized as leaf.
            curr->right->data = inserted;
        }
    }
    else
    {
        if (inserted < curr->data)
        {
            if (curr->left == 0)
            {
                curr->left = new Node();
                curr->left->data = inserted;
            }
            else
            {
                insert(inserted, curr->left);
            }
        }
        else if (inserted > curr->data)
        {
            if (curr->right == 0)
            {
                curr->right = new Node();
                curr->right->data = inserted;
            }
            else
            {
                insert(inserted, curr->right);
            }
        }
    }
}

// search for the string in the tree. return true if found.
bool BSTree::search(const string &duplicate) const
{
    return search(duplicate, root);
}

bool BSTree::search(const string &duplicate, Node* curr) const
{
    if (curr->isLeaf() && duplicate != curr->data)
    {
        return false;       // couldnt find value
    }
    if (duplicate < curr->data)
    {
        return search(duplicate, curr->left);
    }
    else if (duplicate > curr->data)
    {
        return search(duplicate, curr->right);
    }
    else
    {
        return true;        // found same value
    }
}

// prints tree inOrder
void BSTree::inOrder() const
{
    inOrder(root);
}

void BSTree::inOrder(Node* curr) const
{
    if (curr != 0)
    {
        inOrder(curr->left);
        cout << curr->data << " ";
        inOrder(curr->right);
    }
}

// prints tree postOrder
void BSTree::postOrder() const
{
    postOrder(root);
}

void BSTree::postOrder(Node* curr) const
{
    if (curr != 0)
    {
        postOrder(curr->left);
        postOrder(curr->right);
        cout << curr->data << " ";
    }
}

// prints tree preOrder
void BSTree::preOrder() const
{
    preOrder(root);
}

void BSTree::preOrder(Node* curr) const
{
    if (curr != 0)
    {
        cout << curr->data <<" ";
        preOrder(curr->left);
        preOrder(curr->right);
    }
}

// returns the smallest value in tree
string BSTree::smallest() const
{
    return smallest(root);
}

string BSTree::smallest(Node* curr) const
{
    if (!curr->isLeaf() && curr->left != 0)
    {
        return smallest(curr->left);
    }
    else
    {
        return curr->data;
    }
    return " ";
}

// returns the largest value in tree
string BSTree::largest() const
{
    return largest(root);
}

string BSTree::largest(Node* curr) const
{
    if (!curr->isLeaf() && curr->right != 0)
    {
        return largest(curr->right);
    }
    else
    {
        return curr->data;
    }
    return " ";
}

// returns height of tree from starting node.
// use search.

int BSTree::height(const string &start) const
{
    if (search(start))
    {
        return height(start, root);
    }
    else
    {
        return -1;
    }
}

int BSTree::height(const string &start, Node* curr) const
{
    if (root == 0)
    {
        return 0;
    }
    if (start < curr->data)                 // first search for word
    {
        return height(start, curr->left);
    }
    else if (start > curr->data)
    {
        return height(start, curr->right);
    }
    else                                    // value found, begin count
    {
        return heightCounter(curr);
    }
}

int BSTree::heightCounter(Node* curr) const
{
    if (curr->isLeaf())
    {
        return 0;
    }
    else
    {
        if (curr->left == 0)                    // if left is empty
        {
            return heightCounter(curr->right) + 1;
        }
        else if (curr->right == 0)
        {
            return heightCounter(curr->left) + 1;
        }
        else
        {
            return heightCounter(curr->left) + 1;
            return heightCounter(curr->right) + 1;
        }
    }
}

// removes node with the value
void BSTree::remove(const string &str)
{
    remove(str, root);
}

void BSTree::remove(const string &str, Node* curr)
{
    if (curr->isLeaf() && curr->data == str) // found and is leaf.
    {
            delete curr;
    }
    else if (!curr->isLeaf())               // not leaf.
    {
        if (str < curr->data)               // look for data
        {
            remove(str, curr->left);
        }
        else if (str > curr->data)
        {
            remove(str, curr->right);
        }
        else
        {
            string large = " ";
            string small = " ";
            if (curr->left != 0)            // find smallest or largest value.
            {
                large = largest(curr->left);
            }
            else
            {
                small = smallest(curr->right);
            }
            if (large != " ")
            {
                curr->data = large;         // replace data
                remove(large, curr->left);
            }
            else if (small != " ")
            {
                curr->data = small;         // replace data
                remove(small, curr->right);
            }
        }
    }  
}
