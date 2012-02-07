#include "BST.h"

using namespace std;

//!  No-arg constructor.  Initializes an empty BST
BST::BST(): top(NULL), size(0){
}


//!  Copy constructor.  Makes a complete copy of its argument
BST::BST(const BST & other){
	top = copyTree(other.top);
	size=other.size;
}


//!  Destructor
BST::~BST(){
	Clear();
}


//!  Assignment operator.  Makes a complete copy of its argument
//!  @return Reference to oneself
BST& BST::operator =(const BST & other){
	if(this!=&other){
		removeNodes(top);
		top = copyTree(other.top);
		size = other.size;
	}
	return *this;
}

BSTNode * BST::copyTree(BSTNode* otherNode){
	if(otherNode==NULL){
		return NULL;
	}
	BSTNode* Node = new BSTNode(otherNode->value);
	Node->left = copyTree(otherNode->left);
	Node->right = copyTree(otherNode->right);
	return Node;	
}
//!  @return a pointer to the root node of the tree, or NULL if the tree is empty.
//!  @note This is useful for BST clients that need to traverse the tree.)
BSTNode * BST::GetRoot()const{
	return top;
}


//!  @return true if the BST is empty, or false if the BST is not empty
bool BST::IsEmpty() const{
	return top == NULL;
}


//!  Removes all values from the BST
void BST::Clear(){
	removeNodes(top);
	size = 0;
	top=NULL;
}

void BST::removeNodes(BSTNode * Node){
	if(Node==NULL) return;
	removeNodes(Node->left);
	removeNodes(Node->right);
	delete Node;
}

//!  @return the number of values in the BST
int BST::GetSize() const{
	return size;
}


//!  Inserts value v into the BST
//!  
//!  @param v The new value being inserted
//!
//!  @return a pointer to the newly inserted node, or NULL if v was already
//!          in the tree (i.e., NULL is used to indicate a duplicate insertion)
BSTNode * BST::Insert(const std::string & v){	
	if(Find(v)) return NULL;
	BSTNode * Node;
	Node = new BSTNode(v);
	insertNode(top,Node);
	size++;
	return Node;
}

void BST::insertNode(BSTNode* &prevNode, BSTNode * inNode){
	if(prevNode==NULL){
		prevNode=inNode;
	}
	else if(prevNode->value > inNode->value){
		insertNode(prevNode->left, inNode);
	}
	else{
		insertNode(prevNode->right, inNode);
	}
}


//!  Searches the tree for value v
//!  
//!  @param v The new value being searched for
//!
//!  @return a pointer to the node containing v, or NULL if v is not in the tree
BSTNode * BST::Find(const std::string & v) const{
	return findNode(top, v);
}

BSTNode * BST::findNode(BSTNode * Node, const std::string & v) const{
	if(Node==NULL){
		return NULL;
	}
	else if(Node->value < v){
		return findNode(Node->right,v);
	}
	else if(Node->value > v){
		return findNode(Node->left,v);
	}
	else{
		return Node;
	}

	
}

void BST::print() const{
	printTree(top);
}

void BST::printTree(BSTNode* Node) const{
	if(Node==NULL){
		cout << "Tree is Empty" << endl;
		return;
	}
	if(Node->left!=NULL){
		printTree(Node->left);
	}
	Node->print();
	if(Node->right!=NULL){
		printTree(Node->right);
	}
}


//! @NOTE: YOU ARE NOT REQUIRED TO IMPLEMENT THE Remove METHOD BELOW
//!        (BUT YOU CAN IF YOU WANT TO)
//!
//!  Removes value v from the tree
//!  
//!  @param v The value being removed from the tree
//!
//!  @return true if v was removed from the tree, or false if v was not in the tree
//bool Remove(const std::string & v);


//!  Constructor
BSTNode::BSTNode(const std::string & v) :
  value(v), left(NULL), right(NULL){
}

//! Copy Constructor
BSTNode::BSTNode(const BSTNode & other) : 
  value(other.value),left(other.left),right(other.right){
}


//!  Read-only public methods for use by clients of the BST class
const std::string & BSTNode::GetValue() const{
  return value;
}



BSTNode * BSTNode::GetLeft()const{
  return left;
}


BSTNode * BSTNode::GetRight()const{
  return right;
}

//! Assignment operator 
BSTNode & BSTNode::operator=(const BSTNode & other){
	if(this!=&other){
		value=other.value;
		left=other.left;
		right=other.right;
	}
	
	return *this;
}

void BSTNode::print(){
	if(this==NULL){
		cout << "Node is empty" << endl;
		return;
	}
	cout << "Node has: " << endl;
	cout << ">>>>value: " << value << endl;
	cout << ">>>>left: " << left << endl;
	cout << ">>>>right: " << right << endl;
	cout << ">>>>addr: " << this << endl;
}


