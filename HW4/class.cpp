#include <iostream>
using namespace std;

template <class T>
class Node{
	T data;
	int key;
	Node<T> *right;
	Node<T> *left;
	int current_depth;
public:
	Node(T data, int key, int current_depth){
		this->data = data;
		this->key = key;
		right = NULL;
		left = NULL;
		this->current_depth = current_depth;
	}
	int getCurrent_depth(){
		return current_depth;
	}
	void decreaseCurrent_depth(){
		current_depth--;
	}
	void setRight(Node<T> *a){
		this->right = a;
	}
	void setLeft(Node<T> *a){
		this->left = a;
	}
	void setData(T data){
		this->data = data;
	}
	T getData(){
		return data;
	}
	Node<T> * getRight(){
		return right;
	}
	Node<T> * getLeft(){
		return left;
	}
	int getKey(){
		return key;
	}
	~Node(){
		if(right != NULL) delete right;
		if(left != NULL) delete left;
	}
};
template <class T>
class Tree{
	Node<T> *root;
	int depth;
	int nu; //shomare ye har node
	Node<T> * NodeKSearch(int key, Node<T> * curr){
		if(curr == NULL){
			return curr;
		}else{
			if(curr->getKey() == key){
				return curr;
			}else{
				Node<T> * S = NodeKSearch(key, curr->getRight());
				if(S != NULL){
					return S;
				}else{
					S = NodeKSearch(key, curr->getLeft());	
				}
				return S;
			}				
		}
		
	}
	Node<T> * NodeCSearch(int key, Node<T> * curr){
		if(curr->getRight() == NULL && curr->getLeft() == NULL){
			return NULL;
		}
		if((curr->getRight() != NULL && curr->getRight()->getKey() == key) || (curr->getLeft() != NULL &&curr->getLeft()->getKey() == key)){
			return curr;
		}else{
			Node<T> * S = NodeCSearch(key, curr->getRight());
			if(S != NULL) return S;
			S = NodeCSearch(key, curr->getLeft());
			if(S != NULL) return S;
		}
		return NULL;
	}
	void copy(Node<T> * des,Node<T> *curr){
		if(curr->getRight() == NULL && curr->getLeft() == NULL){
			return;
		}else{
			if(curr->getRight() != NULL){
				Node<T> *a = new Node<T>(curr->getRight()->getData(),curr->getRight()->getKey(), curr->getRight()->getCurrent_depth());
				des->setRight(a);
			}
			if(curr->getLeft() != NULL){
				Node<T> *a = new Node<T>(curr->getLeft()->getData(),curr->getLeft()->getKey(), curr->getLeft()->getCurrent_depth());
				des->setLeft(a);
			}
			if(curr->getRight() != NULL) copy(des->getRight(), curr->getRight());
			if(curr->getLeft() != NULL) copy(des->getLeft(), curr->getLeft());	
		}
		
	}
	void decreseDepth(Node<T> *curr){
		if(curr == NULL){
			return;
		}
		curr->decreaseCurrent_depth();
		if(curr->getRight() != NULL) decreseDepth(curr->getRight());
		if(curr->getLeft() != NULL) decreseDepth(curr->getLeft());
	}
public:
	Tree(int depth, T data){
		nu = 1;
		root = new Node<T>(data,nu,0);
		this->depth = depth;
	}
	Tree(Tree<T> & a){
		nu = 1;
		root = new Node<T>(a.getRoot()->getData(),a.getRoot()->getKey(),a.getRoot()->getCurrent_depth());
		this->depth = a.getDepth();
		copy(root,a.getRoot());
	}
	Node<T> * NodeTSearch(T data, Node<T> * curr){
		if(curr == NULL){
			return NULL;
		}else{
			if(curr->getData() == data){
				return curr;
			}else{
				Node<T> * S = NodeTSearch(data, curr->getRight());
				if(S != NULL){
					return S;
				}else{
					S = NodeTSearch(data, curr->getLeft());	
				}				
				return S;
			}
		}
	}
	Node<T> * getRoot(){
		return root;
	}
	int getDepth(){
		return depth;
	}
	void deleteNode(int key){
		Node<T> *curr = NodeKSearch(key, this->root);
		if(curr == NULL){
			cout << "In node vojud nadare" << endl;
			return;
		}
		if(curr->getKey() == this->root->getKey()){
			cout << "shoma nemitunid rishe ye derakht ro pak konid" << endl;
		}else{
			if(curr->getRight() == NULL && curr->getLeft() == NULL){
				Node<T> *parent = NodeCSearch(key, this->root);
				if(parent->getRight() != NULL && parent->getRight()->getKey() == key){
					delete parent->getRight();
					parent->setRight(NULL);
				}
				if(parent->getLeft() != NULL && parent->getLeft()->getKey() == key){
					delete parent->getLeft();
					parent->setLeft(NULL);
				}
			}else{
				Node<T> *parent = NodeCSearch(curr->getKey(), this->root);
				if(parent->getRight()->getKey() == key){
					Node<T> *a = parent->getRight()->getLeft();
					parent->getRight()->setLeft(NULL);
					delete parent->getRight();
					parent->setRight(a);
					decreseDepth(parent->getRight());
				}
				if(parent->getLeft()->getKey() == key){
					Node<T> *a = parent->getLeft()->getLeft();
					parent->getLeft()->setLeft(NULL);
					delete parent->getLeft();
					parent->setLeft(a);
					decreseDepth(parent->getLeft());
				}

			}
		}
	}
	void NodeAdd(int no,T data,bool d){ //d is a bool == 0 for right and 1 for left
		Node<T> * curr = NodeKSearch(no,this->root);
		if(curr == NULL){
			cout << "Hich gere i ba in key peida nashod" << endl;
			return;
		}else{
			if(d == 0 && curr->getRight() != NULL){
				cout << "tooye ghesmate rast in gere, ye gere ye Dge ham hast" << endl;
				return;
			}else if(d == 1 && curr->getLeft() != NULL){
				cout << "tooye ghesmate chap in gere, ye gere ye Dge ham hast" << endl;
				return;
			}else{
				if(curr->getCurrent_depth() == this->depth){
					cout << "Be hade aksar omghe mojaz residi. nemishe bishtar raft tu" << endl;
					return;
				}else{
					if(d == 0){
						nu++;
						Node<T> *a = new Node<T>(data,nu,curr->getCurrent_depth() + 1);
						curr->setRight(a);
						//cout << "x::" << curr->getKey();
					}else if(d == 1){
						nu++;
						Node<T> *a = new Node<T>(data,nu,curr->getCurrent_depth() + 1);
						curr->setLeft(a);
						//cout << "y::" << curr->getKey();
					}	
				}				
			}
		}
	}
	void change(int nu, T data){
		Node<T> * curr = NodeKSearch(nu,this->root);
		if(curr == NULL){
			cout << "Hich gere i ba in key peida nashod" << endl;
			return;
		}else{
			curr->setData(data);
		}
	}
	void print(Node<T> *curr, int i = 0){
		if(i == 0){
			cout << "DATA :: " << curr->getData() << endl;
			cout << "key :: " << curr->getKey() << endl;
			cout << "------" << endl;
			if(curr->getRight() != NULL){
				cout << "DATA :: " << curr->getRight()->getData() << endl;
				cout << "key :: " << curr->getRight()->getKey() << endl;
				cout << "Parent :: " << curr->getKey() << endl;
				cout << "------" << endl;
				print(curr->getRight(), 1);
			}
			if(curr->getLeft() != NULL){
				cout << "DATA :: " << curr->getLeft()->getData() << endl;
				cout << "key :: " << curr->getLeft()->getKey() << endl;
				cout << "Parent :: " << curr->getKey() << endl;
				cout << "------" << endl;
				print(curr->getLeft(), 1);
			}
		}
		if(curr == NULL){
			return;
		}
		if(i == 1){
			if(curr->getRight() != NULL){ 
				cout << "DATA :: " << curr->getRight()->getData() << endl;
				cout << "key :: " << curr->getRight()->getKey() << endl;
				cout << "Parent :: " << curr->getKey() << endl;
				cout << "------" << endl;
				print(curr->getRight(), 1);
			}
			if(curr->getLeft() != NULL){
				cout << "DATA :: " << curr->getLeft()->getData() << endl;
				cout << "key :: " << curr->getLeft()->getKey() << endl;
				cout << "Parent :: " << curr->getKey() << endl;
				cout << "------" << endl;
				print(curr->getLeft(), 1);
			}	
		}		
	}
	~Tree(){
		delete root;
	}
};