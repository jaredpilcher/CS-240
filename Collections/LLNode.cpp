#include "LLNode.h"
using namespace std;

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
