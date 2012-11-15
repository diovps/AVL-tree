#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
 private:
  T value;
  Node<T>* leftChild;
  Node<T>* rightChild;
  int balance;

 public:
  Node<T>(T v);
  T getValue();

  void setBalance(int n);
  int getBalance();

  Node<T>*& getLeftChild();
  void setLeftChild(Node<T>& n);

  Node<T>*& getRightChild();
  void setRightChild(Node<T>& n);
};
#endif
