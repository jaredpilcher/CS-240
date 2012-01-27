#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(){
	LinkedList List;
	string test_string("This is a test");
	string test_string2("This is a second test");

	LLNode * newNode = List.Insert(test_string, NULL);
	LLNode * secondNode = List.Insert(test_string2, newNode);
	LLNode * Node;
//	Node = List.GetFirst();
	Node = List.Find(test_string2, newNode);
	if(Node!=NULL){
		cout << Node->GetValue() << endl;
		cout << Node->GetPrevious() << endl;
		cout << Node->GetNext() << endl;
		cout << List.GetSize() << endl;
	}
	List.Remove(secondNode);
	Node = List.Find(test_string2, newNode);
	if(Node!=NULL){
		cout << Node->GetValue() << endl;
		cout << Node->GetPrevious() << endl;
		cout << Node->GetNext() << endl;
	}
	else{
		cout << "cannot find that string" << endl;
		cout << List.GetSize() << endl;
	}
}
