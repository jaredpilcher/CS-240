#include "BST.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;
int checkConstructor(void);
int checkInsert(void);

int main(){
	cout << "CS 240 Collections Pass Off\n\n" << endl;
	cout << "LinkedList:" << endl;
	cout << "\t 1 Default Constructor" << (checkConstructor() ? "...Passed!" : "...failed :(") <<  endl;
	cout << "\t 2 Basic Insert Tests" << (checkInsert() ? "...Passed!" : "...failed :(") << endl;
}

int checkConstructor(){
	LinkedList List;
	return (List.getTop()==NULL) || (List.getBottom()==NULL) || (List.getSize()==0);
}

int checkInsert(){
	LinkedList List;
	LLNode * Node1, *Node2, *Node3;
	LLNode * top = List.getTop();
	LLNode * bottom = List.getBottom();
	int size = List.getSize();

	//Test 0
	if((top != NULL) || (bottom != NULL) || (size!=0)) return 0;

	//Test 1
	Node1 = List.Insert("Test 1", NULL);
	top = List.getTop();
	bottom = List.getBottom();
	size = List.getSize();
	//check to see if the Node was set up properly
	if((top->getPrev() != NULL) || (top->getNext() != NULL) || (size!=1) || (top->getValue()!="Test 1") || (bottom != NULL)) return 0;
	//Ensure that top and Node point to the same object
	if(top != Node) return 0;

	//Test 2
	Node2 = List.Insert("Test 2", Node);
	top = List.getTop();
	bottom = List.getBottom();
	size = List.getSize();
	//check to see if the Node was set up properly
	if( (top->getPrev() != NULL) || (top->getNext() != Node)  || (size!=2)  || (Node->getValue()!="Test 2")  || (bottom != Node)) return 0;

	//Test 3
	Node3 = List.Insert("Test 3", 
	
}
