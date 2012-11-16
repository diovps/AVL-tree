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
	Node<T>* blankNode = new Node<T>(0);
	Node<T>** critNode = &blankNode;
	
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
	
	Node<T>** R;
	int d1 = 0;
	int d2 = 0;
	//int d3 = 0;

	if(*critNode != 0){
		Node<T>* C;
		Node<T>* B;

		if(v == (*critNode)->getValue()){
			d1 = 0;
			C = *critNode;
		}else if(v < (*critNode)->getValue()){
			d1 = -1;
			C = (*critNode)->getLeftChild();
		}else{
			d1 = 1;
			C = (*critNode)->getRightChild();
		}
		
		if((*critNode)->getBalance()!=d1){
			(*critNode)->setBalance(0);
			R = curr;
		}else{
			if(v==C->getValue()){
				d2 = 0;
				B = C;	
			}else if(v < C->getValue()){
				d2 = -1;
				B = C->getLeftChild();
			}else{
				d2 = 1;
				B = C->getRightChild();
			}
			
			if(d2 == d1){
				(*critNode)->setBalance(0);
				R = &B;
				if(d1<0){
					rotateRight(critNode);
				}else{
					rotateLeft(critNode);
				}
			}else{
				
			}
		}
		
	}
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
	rotateRight(curr);	
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
