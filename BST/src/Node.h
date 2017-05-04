#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <string>
using namespace std;


class Node
{
  public:
    Node *right;
    Node *left;
    string data;
    Node () : left(0), right(0) {}      // constructor

    bool isLeaf()
    {
        if (left == 0 && right == 0)
        {
            return true;
        }
        return false;
    }
};

#endif
