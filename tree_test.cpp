#include "BST.h"

int main() {
  BST<int>* bst = new BST<int>();

  bst->insert(5);
  bst->insert(6);
  bst->insert(3);
  bst->insert(2);
  bst->insert(7);
  bst->insert(8);
  bst->insert(9);
  bst->insert(10);
  bst->insert(1); 
  bst->print();
  bst->levelPrint();
}
