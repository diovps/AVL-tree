#include "BST.h"

int main() {
  BST<int>* bst = new BST<int>();

  bst->insert(4);
  bst->insert(6);
  bst->insert(3);
 
  bst->print(); 
  bst->levelPrint();
}
