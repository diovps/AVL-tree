#include "BST.h"

int main() {
  BST<int>* bst = new BST<int>();
  
  bst->insert(5);
  bst->insert(7);
  bst->insert(8);
  bst->insert(6);
  bst->remove(6);
  bst->print();
  bst->levelPrint();
}
