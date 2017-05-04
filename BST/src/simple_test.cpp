
#include <iostream>
#include "BSTree.h"

using namespace std;

void printOrders(BSTree *tree) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout << endl;
  cout << "Inorder = ";
  tree->inOrder( );
  cout << endl;
  cout << "Postorder = ";
  tree->postOrder( );
  cout << endl;
}

int main( ) {

  BSTree tree;

  cout << "Test 1: Testing simple insert" << endl;
  tree.insert("hello");   // 7
  tree.insert("delete");  // 4
  tree.insert("hoppy");   // 8 
  tree.insert("gadget");  // 6 
  tree.insert("edward");  // 5
  tree.insert("annie");   // 2  
  tree.insert("words");   // 10
  tree.insert("cow");     // 3
  tree.insert("wings");   // 9
//  tree.insert("aid");     // 1

  printOrders(&tree);     
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 2: Search testing" << endl;
  if (tree.search("hello")) {
    cout << "Passed" << endl;
  } else {
    cout << "Failed" << endl;
  }
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 3: Smallest value in the tree is..." << endl;
  cout << tree.smallest( ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 4: Largest value in the tree is..." << endl;
  cout << tree.largest( ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 5: Testing subtree heights" << endl;
  cout << "Height of subtree rooted at \"hello\" = " 
       << tree.height("hello") << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 6: Remove testing" << endl;
  cout << "Removing \"hoppy\"" << endl;
  tree.remove("hoppy");
  printOrders(&tree);
  cout << "----------------------------------------------------------------" 
       << endl;

  return 0;
}