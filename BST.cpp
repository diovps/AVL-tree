#include "BST.h"
#include <iostream>
#include <list>

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
bool BST<T>::find(T v) {
  Node<T>* temp = new Node<T>(v);
  root = temp;  
  return true;
}

template <typename T>
void BST<T>::insert(T v) {	
	Node<T>** curr = &root;
	Node<T>** critNode = 0;
	
	while(*curr!=0){
		if((*curr)->getBalance()!=0){
			critNode = curr;
		}

		if(v < (*curr)->getValue()){
			(*curr)->setBalance((*curr)->getBalance()-1);
			curr = &((*curr)->getLeftChild());
		}else if(v > (*curr)->getValue()){
			(*curr)->setBalance((*curr)->getBalance()+1);
			curr = &((*curr)->getRightChild());
		}
	}
	
	*curr = new Node<T>(v);
	
}

template <typename T>
void BST<T>::rotate(T v){

	Node<T>** curr = &root;
		
	while(*curr!=0){
		if(v < (*curr)->getValue()){
			curr = &((*curr)->getLeftChild());
		}else if(v > (*curr)->getValue()){
			curr = &((*curr)->getRightChild());
		}else{
			break;
		}
	}
	rotateLeft(curr);	
}
	
template <typename T>
void BST<T>::rotateRight(Node<T>** critNode){
	
	Node<T>* currNode = *critNode;	
	*critNode = (*critNode)->getLeftChild();
	currNode->setLeftChild(*((*critNode)->getRightChild()));
	(*critNode)->setRightChild(*currNode);
}

template <typename T>
void BST<T>::rotateLeft(Node<T>** critNode){	
	
	Node<T>* currNode = *critNode;	
	*critNode = (*critNode)->getRightChild();
	currNode->setRightChild(*((*critNode)->getLeftChild()));
	(*critNode)->setLeftChild(*currNode);
}

template <typename T>
void BST<T>::remove(T v) {
  Node<T>* temp = new Node<T>(v);
  root = temp;
}

template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    
    std::cout << root->getValue() << " Balance: " << root->getBalance()<< std::endl;
    traversalPrint(root->getRightChild());
  }
}

template <typename T>
void BST<T>::levelPrint(){	
	std::list<Node<T>* > s;
	
	s.push_front(root);
	
	int currentLevel = 1;
	int nextLevel = 0;
	int depth = 1;
	
	while(!s.empty()){
		Node<T>* val = s.front();
		s.pop_front();
		
		currentLevel--;
		std::cout << val->getValue() << " ";
		if(val->getLeftChild()!=0){
			s.push_back(val->getLeftChild());
			nextLevel++;
		}	
		if(val->getRightChild()!=0){
		        s.push_back(val->getRightChild());
			nextLevel++;
		}
		
		if(currentLevel==0){
			std::cout << std::endl;
			depth++;
			currentLevel = nextLevel;
		}
	}
	std::cout << std::endl;
}

template class BST<int>;
//template class BST<double>;
//template class BST<std::string>;
