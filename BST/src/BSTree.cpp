#include "BSTree.h"

#include <iostream>
#include <string>
#include <stdexcept>


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
        root->count++;
    }
    else if (curr->isLeaf())
    {
        if (inserted < curr->data)
        {
            curr->left = new Node();        // new node is initialized as leaf.
            curr->left->count++;
            curr->left->data = inserted;
        }
        else if (inserted > curr->data)
        {
            curr->right = new Node();       // new node is initialized as leaf.
            curr->right->count++;
            curr->right->data = inserted;
        }
        else
        {
            curr->count++;
        }
    }
    else
    {
        if (inserted < curr->data)
        {
            if (curr->left == 0)
            {
                curr->left = new Node();
                curr->left->count++;
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
                curr->count++;
                curr->right->data = inserted;
            }
            else
            {
                insert(inserted, curr->right);
            }
        }
        else
        {
            curr->count++;
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
    if (curr == 0)
    {
        return false;
    }
    if ((curr->isLeaf() && duplicate != curr->data))
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
        cout << curr->data;
        cout << "(" << curr->count << "), " << endl;
        inOrder(curr->right);
    }
    else
    {
        cout << "";
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
        cout << curr->data;
        cout << "(" << curr->count << "), ";
    }
    else
    {
        cout << "";
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
        cout << curr->data;
        cout << "(" << curr->count << "), ";
        preOrder(curr->left);
        preOrder(curr->right);
    }
    else
    {
        cout << "";
    }
}

// returns the smallest value in tree
string BSTree::smallest() const
{
    return smallest(root);
}

string BSTree::smallest(Node* curr) const
{
    if (curr == 0)
    {
        return "";
    }
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
    if (curr == 0)
    {
        return "";
    }
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
    if (curr == 0)
    {
        return -1;
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
            return heightCounter(curr->right);
        }
        else if (curr->right == 0)
        {
            return heightCounter(curr->left);
        }
        else
        {
            int heightLeft = heightCounter(curr->left) + 1;
            int heightRight = heightCounter(curr->right) + 1;
            if (heightLeft > heightRight)
            {
                return heightLeft;
            }
            else
            {
                return heightRight;
            }
        }
    }
}


// removes node with the value
void BSTree::remove(const string &str)
{
    remove(str, root, root);
}

void BSTree::remove(const string &str, Node* curr, Node* parent)
{
    if(search(str))
    {
        curr = searchNode(str, curr, parent);
        parent = searchParent(str, curr, parent);

        if (curr->count > 1)
        {
            curr->count--;
        }
        else if (curr->isLeaf())
        {
            if(curr == root)
            {
                delete curr;
                delete root;
                root = 0;
                curr = 0;
            }
            else if (parent->left == curr)
            {
                parent->left = 0;
            }
            else if (parent->right == curr)
            {
                parent->right = 0;
            }
            delete curr;
            curr = 0;
        }
        else if (!curr->isLeaf())
        {
            string large = " ";
            string small = " ";
            Node* temp;
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
                temp = searchNode(large, curr->left, curr);
                //get largeNode*

                curr->data = temp->data;
                curr->count = temp->count;
                temp->count = 1;

                if(temp->isLeaf())
                {
                   if (curr->left == temp)
                   {
                       curr->left = 0;
                   }
                   else
                   {
                       curr->right = 0;
                   }
                   delete temp;
                   temp = 0;
                }
                else
                {
                    remove(large, curr->left, curr);
                }


            }
            else if (small != " ")
            {
                temp = searchNode(small, curr->right, curr);

                curr->data = temp->data;
                curr->count = temp->count;
                temp->count = 1;


               if(temp->isLeaf())
               {
                   if (curr->left == temp)
                   {
                       curr->left = 0;
                   }
                   else
                   {
                       curr->right = 0;
                   }
                   delete temp;
                   temp = 0;
               }
               else
               {
                   remove(small, curr->right, curr);
               }
            }
        }
    }
}

Node* BSTree::searchNode(const string &str, Node* curr, Node* parent)
{
    if ((curr->isLeaf() && str != curr->data))
    {
        return 0;       // couldnt find value
    }
    if (str < curr->data)
    {
        return searchNode(str, curr->left,curr);
    }
    else if (str > curr->data)
    {
        return searchNode(str, curr->right,curr);
    }
    else
    {
        return curr;        // found same value
    }
}

Node* BSTree::searchParent(const string &str, Node* curr, Node* parent)
{
    if ((curr->isLeaf() && str != curr->data))
    {
        return 0;       // couldnt find value
    }
    if (str < curr->data)
    {
        return searchParent(str, curr->left,curr);
    }
    else if (str > curr->data)
    {
        return searchParent(str, curr->right,curr);
    }
    else
    {
        return parent;        // found same value
    }
}
