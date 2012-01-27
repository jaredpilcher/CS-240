#include "LinkedList.h"
using namespace std;

//!  No-arg constructor.  Initializes an empty linked list
LinkedList::LinkedList(): top(NULL), bottom(NULL), size(0){
}


//!  Copy constructor.  Makes a complete copy of its argument
LinkedList::LinkedList(const LinkedList & other):top(NULL), bottom(NULL), size(0) {
	copyList(other);
}

void LinkedList::copyList(const LinkedList & other){
	LLNode * hisCurNode=other.top;
	LLNode * myCurNode = NULL;
	LLNode * myPrevNode = NULL;
	while(hisCurNode != NULL){
		myCurNode = new LLNode(hisCurNode->value, myPrevNode, NULL);
		
		if(myPrevNode!=NULL){
			myPrevNode->next = myCurNode;
		}
		myPrevNode = myCurNode;
		if(top==NULL){
			top = myCurNode;
		}
		if(hisCurNode->next == NULL){
			break;
		}
		hisCurNode = hisCurNode->next;
	}
	bottom = hisCurNode;
	size = other.size;
}

//!  Destructor
LinkedList::~LinkedList(){
	removeNodes(top);
	top=NULL;
	bottom=NULL;
}


//! Assignment operator.  Makes a complete copy of its argument
//! @return A reference to oneself
LinkedList& LinkedList::operator =(const LinkedList & other){
	removeNodes(top);
	top=NULL;
	bottom=NULL;
	copyList(other);
}


//!  @return true if the list is empty, or false if the list is not empty
bool LinkedList::IsEmpty() const{
	if(top==NULL){
		return true;
	}
	return false;
}


//!  Removes all values from the list
void LinkedList::Clear(){
	removeNodes(top);
	top=NULL;
	bottom=NULL;
	return;
}

//Delete all nodes, starting with Node
void LinkedList::removeNodes(LLNode * Node){
	if(Node==NULL) return;
	LLNode * next = Node->next;
	delete Node;
	if(next!=NULL){
		removeNodes(next);
	}
	return;
}

//!  @return the number of values in the list
int LinkedList::GetSize() const{
	return size;
}



//!  @return a pointer to the first node in the list, or NULL if the list is empty
LLNode * LinkedList::GetFirst()const{
	return top;
}



//!  @returns a pointer to the last node in the list, or NULL if the list is empty
LLNode * LinkedList::GetLast()const{
	return bottom;
}



//!  Inserts value v into the list after node n
//!  
//!  @param v The new value being inserted
//!  @param n A node that is already in the list after which the new node should 
//!      be inserted.
//!      If n is NULL, the new node should be inserted at the beginning of the list.
//!
//!  @return a pointer to the newly inserted node
LLNode * LinkedList::Insert(const std::string & v, LLNode * n){
	LLNode * newNode;
	if(n==NULL){
		newNode = new LLNode(v, NULL, top);
		if(top!=NULL) top->prev = newNode;
		top = newNode;
	}
	else{
		newNode = new LLNode(v, n, n->next);
		
		if(n->next!=NULL){
			newNode->next->prev=newNode;
		}
		else{
			bottom = newNode;
		}
		n->next = newNode;
	}
	size++;
	return newNode;
}


//! Searches for the first occurrence of value v that appears in the list 
//!   after node n
//!   
//!  @param v The value being searched for
//!  @param n The node in the list after which the search should begin.
//!      If n is NULL, the list should be searched from the beginning.
//!
//!  @return a pointer to the node containing v, or NULL if v is not found
LLNode * LinkedList::Find(const std::string & v, LLNode * n) const{
	LLNode * returnNode = n;
	if(returnNode==NULL){
		returnNode = top;
	}
	while(returnNode!=NULL){
		if(returnNode->value == v){
			break;
		}
		returnNode=returnNode->next;
	}
	return returnNode;
}


//!  Removes node n from the list
//!  
//!  @param n The node being removed from the list
void LinkedList::Remove(LLNode * n){
	if(n->prev!=NULL){
		n->prev->next = n->next;
	}
	else{
		top=n->next;
	}
	if(n->next!=NULL){
		n->next->prev = n->prev;
	}
	else{
		bottom=n->prev;
	}
	size--;
	delete n;
}

void LinkedList::printList(const LinkedList & List){
	int i=0;
	LLNode * Node;
	Node = List.top;
	cout << List.top << endl;
	while(Node!=NULL){
		cout << "Node " << i << " has:" << endl;
		cout << ">>>>value: " << Node->value << endl;
		cout << ">>>>next: " << Node->next << endl;
		cout << ">>>>prev: " << Node->prev << endl;
		cout << ">>>>addr: " << Node << endl;
		Node=Node->next;
		i++;
	}
	if(i==0) cout << "Nothing in List" << endl;
	return;
}


