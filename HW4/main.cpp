#include <iostream>
using namespace std;
#include "class.cpp"
int main(){
	Tree<int> a(3,1); //Tree with root data 1 and depth 3 (without counting root)
	a.NodeAdd(1,3,0); //adding node
	a.NodeAdd(1,2,1);
	a.NodeAdd(3,4,0);
	a.NodeAdd(3,5,1);
	a.NodeAdd(2,6,0);
	a.NodeAdd(2,7,1);
	a.NodeAdd(2,6,0);
	a.NodeAdd(4,6,0);
	a.NodeAdd(7,16,0);
	a.NodeAdd(9,6,0);
	a.print(a.getRoot()); //print node
	cout << a.NodeTSearch(16, a.getRoot())->getKey() << endl; //Searching
	{ //Testing destructor
		Tree<int> a(3,1);
		a.NodeAdd(1,3,0);
		a.NodeAdd(1,2,1);
		a.NodeAdd(3,4,0);
		a.NodeAdd(3,5,1);
		a.NodeAdd(2,6,0);
		a.NodeAdd(2,7,1);
		a.NodeAdd(2,6,0);
		a.NodeAdd(4,6,0);
		a.NodeAdd(7,6,0);
		a.NodeAdd(9,6,0);
	}
	cout << "***********" << endl; //deleting
	a.deleteNode(2);
	a.print(a.getRoot());
	cout << "***********" << endl;
	a.deleteNode(9);
	a.print(a.getRoot());
	cout << "***********" << endl;
	a.deleteNode(1); //delete root
	a.deleteNode(20); //delete ye ki ke tooye derakht nis
	cout << "##############" << endl;
	Tree<int> b = a; //copy constructor
	b.print(b.getRoot());
	b.change(5, 15); //change Data
	cout << "##################" << endl;
	a.print(a.getRoot()); //show that b and a be ham va baste nistan
	return 0;
}
