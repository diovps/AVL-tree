#include "BST.h"

int main() {
  BST<int>* bst = new BST<int>();
  
  bst->insert(5);
  bst->insert(7);
  bst->insert(8);
  bst->insert(9);
  bst->remove(5);
  bst->print();
  bst->levelPrint();
}
