#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

bool Node::isLeaf()
{
    if (left == 0 && right == 0)
    {
        return true;
    }
    return false;
}