#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(){
	LinkedList List;
	string test_string="This is a test";
	string test_string2="This is a second test";
	string test_string3="This is a third test";

	LLNode * Node1, *Node2, *Node3;
	Node1 = List.Insert(test_string, NULL);
	
	Node2 = List.Insert(test_string2, Node1);

	Node3 = List.Insert(test_string3, Node2);
	cout << "/////////printing list1////////////////" << endl;
	LinkedList::printList(List);
	LinkedList List2=List;
	cout << "/////////printing list1////////////////" << endl;
	LinkedList::printList(List);
	cout << "/////////printing list2////////////////" << endl;
	LinkedList::printList(List2);
	
}
