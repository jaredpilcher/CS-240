#ifndef CS240_BSTNODE_H
#define CS240_BSTNODE_H

#include <string>
#include <iostream>


//!  BSTNode implements a binary search tree node
class BSTNode 
{
		friend class BST;   //!< BST can access private members of BSTNode
	
	public:
	
		//!  Constructor
		BSTNode(const std::string & v);
		
		//! Copy Constructor
		BSTNode(const BSTNode & other);
		
	
		//!  Read-only public methods for use by clients of the BST class
		const std::string & GetValue() const;
	
		
	
		BSTNode * GetLeft()const;
	
	
		BSTNode * GetRight()const;
		
		//! Assignment operator 
		BSTNode & operator=(const BSTNode & other);
		
		void print();
	
	private:
		std::string value;  //!< value stored in the node
		BSTNode * left;     //!< pointer to the node's left child
		BSTNode * right;    //!< pointer to the node's right child
};

#endif
