#include "BST.h"
#include <iostream>
using namespace std;

int main(){
	BST bst;
	string one="1", two="2", three="3";
	BSTNode * Node;
	bst.Insert(two);
	bst.Insert(one);
	bst.Insert(three);
	BST bst2=bst;
	bst.print();
	bst2.print();
}
