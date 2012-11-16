#ifndef __BST_H__
#define __BST_H__

#include "Node.h"
#include <string>

template <typename T>
class BST {
 private:
  Node<T>* root;
  void traversalPrint(Node<T>* root);

 public:
  BST<T>();
  ~BST<T>();
 
  void levelPrint(); 
  
  void rotate(Node<T>**,int d); 
  void rotateRight(Node<T>** n); 
  void rotateLeft(Node<T>** n);

  bool find(T v);
  void remove(T v);
  void insert(T v);
  void print();
};


#endif
