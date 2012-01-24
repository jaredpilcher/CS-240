#include "LinkedList.h"
using namespace std;

/////////////////////////////////////////////////////////////////
////////////////Linked List Node Functions///////////////////////
/////////////////////////////////////////////////////////////////

// LLNode Constructor
LLNode::LLNode(const std::string & v, LLNode * p, LLNode * n) :
  value(v), prev(p), next(n)
{
}

//! Copy Constructor 
LLNode::LLNode(const LLNode & other) : 
   value(other.value),prev(other.prev),next(other.next)
{
}

//!  Read-only public methods for use by clients of the LinkedList class
const std::string & LLNode::GetValue() const
{
  return value;
}

LLNode * LLNode::GetPrevious() const
{
  return prev;
}

LLNode * LLNode::GetNext() const
{
  return next;
}

//! Assignment operator 
LLNode & LLNode::operator=(const LLNode & other)
{
	if(this!=&other)
	{
		value=other.value;
		prev=other.prev;
		next=other.next;
	}
	return *this;
}

/////////////////////////////////////////////////////////////////
////////////////Linked List Functions////////////////////////////
/////////////////////////////////////////////////////////////////

//!  No-arg constructor.  Initializes an empty linked list
LinkedList::LinkedList(){
	top = NULL;
	bottom = NULL;
}


//!  Copy constructor.  Makes a complete copy of its argument
LinkedList::LinkedList(const LinkedList & other){
	top = NULL;
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
}


//!  Destructor
~LinkedList();


//! Assignment operator.  Makes a complete copy of its argument
//! @return A reference to oneself
LinkedList& operator =(const LinkedList & other);


//!  @return true if the list is empty, or false if the list is not empty
bool IsEmpty() const;


//!  Removes all values from the list
void Clear();


//!  @return the number of values in the list
int GetSize() const;



//!  @return a pointer to the first node in the list, or NULL if the list is empty
LLNode * GetFirst()const;



//!  @returns a pointer to the last node in the list, or NULL if the list is empty
LLNode * GetLast()const;


//!  Inserts value v into the list after node n
//!  
//!  @param v The new value being inserted
//!  @param n A node that is already in the list after which the new node should 
//!      be inserted.
//!      If n is NULL, the new node should be inserted at the beginning of the list.
//!
//!  @return a pointer to the newly inserted node
LLNode * Insert(const std::string & v, LLNode * n);


//! Searches for the first occurrence of value v that appears in the list 
//!   after node n
//!   
//!  @param v The value being searched for
//!  @param n The node in the list after which the search should begin.
//!      If n is NULL, the list should be searched from the beginning.
//!
//!  @return a pointer to the node containing v, or NULL if v is not found
LLNode * Find(const std::string & v, LLNode * n) const;


//!  Removes node n from the list
//!  
//!  @param n The node being removed from the list
void Remove(LLNode * n);

int main(){


}


