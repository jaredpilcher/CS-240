#include "BSTNode.h"
using namespace std;
//!  Constructor
BSTNode::BSTNode(const std::string & v) :
  value(v), left(NULL), right(NULL)
{
}

//! Copy Constructor
BSTNode::BSTNode(const BSTNode & other) : 
  value(other.value),left(other.left),right(other.right)
{
}


//!  Read-only public methods for use by clients of the BST class
const std::string & BSTNode::GetValue() const
{
  return value;
}



BSTNode * BSTNode::GetLeft()const
{
  return left;
}


BSTNode * BSTNode::GetRight()const
{
  return right;
}

//! Assignment operator 
BSTNode & BSTNode::operator=(const BSTNode & other)
{
	if(this!=&other)
	{
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
