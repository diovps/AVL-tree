#include "BST.h"
#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>

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
	Node<T>** critNode;
	bool CritNodeFound = false;

	while(*curr!=0){
		if((*curr)->getBalance()!=0){
			critNode = curr;
			CritNodeFound = true;
		}

		if(v < (*curr)->getValue()){
			curr = &((*curr)->getLeftChild());
		}else if(v > (*curr)->getValue()){
			curr = &((*curr)->getRightChild());
		}
	}
	*curr = new Node<T>(v);
	
	Node<T>** R;
	int d1 = 0;
	int d2 = 0;
	int d3 = 0;
	
	if(!CritNodeFound){
		R = &root;
	}else{
		Node<T>** C = 0;
		Node<T>* B = 0;

		if(v < (*critNode)->getValue()){
			d1 = -1;
			C = &((*critNode)->getLeftChild());
		}else{
			d1 = 1;
			C = &((*critNode)->getRightChild());
		}
		
		if((*critNode)->getBalance()!=d1){
			(*critNode)->setBalance(0);
			R = curr;
			std::cout << "No rotation" << std::endl;
		}else{
			if(v < (*C)->getValue()){
				d2 = -1;
				B = (*C)->getLeftChild();
			}else{
				d2 = 1;
				B = (*C)->getRightChild();
			}
			
			if(d2 == d1){
				(*critNode)->setBalance(0);
				R = &B;
				
				std::cout << "Single Rotation" << std::endl;
				rotate(critNode,-d1);
			}else{
					
				if(v < B->getValue()){
					d3 = -1;
					R = &(B->getLeftChild());
				}else if(v>B->getValue()){
					d3 = 1;
					R = &(B->getRightChild());
				}else{
					R = &B;
				}
			
				if(d3==d2){
					(*critNode)->setBalance(0);
					(*C)->setBalance(d1);
				}else if(d3 == -d2){
					(*critNode)->setBalance(d2);
				}else{
					(*critNode)->setBalance(0);
				}
				std::cout << "Double rotation" << std::endl;	
				rotate(C,-d2);
				rotate(critNode,-d1);
			}
		}		

	}
	
	Node<T>** temp = R;
	std::cout << "R is:" << (*R)->getValue() << std::endl;
	while(*temp!=0 && (*temp)->getValue()!=v){
		
		if((*temp)->getValue()<v){
			(*temp)->setBalance((*temp)->getBalance()+1);
			temp = &((*temp)->getRightChild());
		}else if((*temp)->getValue()>v){
			(*temp)->setBalance((*temp)->getBalance()-1);
			temp = &((*temp)->getLeftChild());
		}

	}		
}


template <typename T>
void BST<T>::rotate(Node<T>** Q, int d){
	if(d==-1){
		rotateLeft(Q);
	}else{
		rotateRight(Q);
	}	
}
	
template <typename T>
void BST<T>::rotateRight(Node<T>** critNode){
	
	std::cout << "Right" << std::endl;
	Node<T>* currNode = *critNode;	
	*critNode = (*critNode)->getLeftChild();
	currNode->setLeftChild(*((*critNode)->getRightChild()));
	(*critNode)->setRightChild(*currNode);
	
}

template <typename T>
void BST<T>::rotateLeft(Node<T>** critNode){	
	
	std::cout << "Left" << std::endl;
	Node<T>* currNode = *critNode;	
	*critNode = (*critNode)->getRightChild();
	currNode->setRightChild(*((*critNode)->getLeftChild()));
	(*critNode)->setLeftChild(*currNode);
}

template <typename T>
void BST<T>::remove(T v) {
  Node<T>** temp = &root;
  
  std::list<Node<T>*> path;
  path.push_back(root);  

  while(*temp!=0 && (*temp)->getValue()!=v){
	if((*temp)->getValue()<v)
	    temp = &((*temp)->getRightChild());
	else{
	    temp = &((*temp)->getLeftChild());
	}
	path.push_back(*temp);
  }
  if(*temp==0) return;
  Node<T>** ios = temp;

  if((*temp)->getRightChild()==0){
	Node<T>* something = (*temp);
	(*temp) = (*temp)->getLeftChild();
	path.push_back(*temp);	
	delete something;
  }else{
	ios = &((*ios)->getRightChild());
	
	path.push_back((*ios)->getRightChild());
	
	bool hIos = (*ios)->getLeftChild()==0;
	
	while((*ios)->getLeftChild()!=0){
		ios = &((*ios)->getLeftChild());
		path.push_back((*ios)->getLeftChild());
	}
  	
	Node<T>* leftTree = (*temp)->getLeftChild();
	Node<T>* rightTree = (*temp)->getRightChild();
	Node<T>* iosRight = (*ios)->getRightChild();

	(*ios)->setLeftChild(*leftTree);
	(*temp) = (*ios);
	
	if(!hIos){
		rightTree->setLeftChild(*iosRight);
		(*temp)->setRightChild(*rightTree);	
   	}
   }
  
  if(!path.empty()){
	path.pop_back();
  }

  while(!path.empty()){
	//Node<T>* P = path.back();	
	path.pop_back();
  }

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
