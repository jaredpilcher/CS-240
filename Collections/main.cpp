#include "BST.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;
int checkConstructor(void);
int checkInsert(void);

int main(){
	cout << "CS 240 Collections Pass Off\n\n" << endl;
	cout << "LinkedList:" << endl;
	cout << "\n\t 1 Default Constructor" << endl;
	checkConstructor();
	cout << "\n\t 2 Basic Insert" << endl;
	checkInsert();
}

int checkConstructor(){
	LinkedList List;
	LinkedList::printList(List);
}

int checkInsert(){
	LinkedList List;
	LLNode * Node1, *Node2, *Node3, *Node4;
	LLNode * top = List.getTop();
	LLNode * bottom = List.getBottom();
	int size = List.getSize();

	//Test 0
	cout << "Before inserting: " << endl;
	LinkedList::printList(List);

	//Test 1
	Node1 = List.Insert("Test 1", NULL);
	cout << "Inserted \"Test 1\" at top of list" << endl;
	LinkedList::printList(List);
	cout << "The returned node was: " << endl;
	LLNode::print(Node1);

	//Test 2
	Node2 = List.Insert("Test 2", Node1);
	cout << "Inserted \"Test 2\" after first node" << endl;
	LinkedList::printList(List);
	cout << "The returned node was: " << endl;
	LLNode::print(Node2);

	//Test 3
	Node3 = List.Insert("Test 3", Node1);
	cout << "Inserted \"Test 3\" after first node" << endl;
	LinkedList::printList(List);
	cout << "The returned node was: " << endl;
	LLNode::print(Node3);

	//Test 4 
	Node4 = List.Insert("Test 4", NULL);
	cout << "Inserted \"Test 4\" at top of list" << endl;
	LinkedList::printList(List);
	cout << "The returned node was: " << endl;
	LLNode::print(Node4);
	
}
