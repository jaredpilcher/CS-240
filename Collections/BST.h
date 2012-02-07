	#ifndef CS240_BST_H
#define CS240_BST_H

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

//!  BST implements a binary search tree
class BST 
{
	
	public:
	
		//!  No-arg constructor.  Initializes an empty BST
		BST();
	
	
		//!  Copy constructor.  Makes a complete copy of its argument
		BST(const BST & other);
	
	
		//!  Destructor
		~BST();
	
	
		//!  Assignment operator.  Makes a complete copy of its argument
		//!  @return Reference to oneself
		BST& operator =(const BST & other);
	
	
		//!  @return a pointer to the root node of the tree, or NULL if the tree is empty.
		//!  @note This is useful for BST clients that need to traverse the tree.)
		BSTNode * GetRoot()const;
	
	
		//!  @return true if the BST is empty, or false if the BST is not empty
		bool IsEmpty() const;
	
	
		//!  Removes all values from the BST
		void Clear();
	
	
		//!  @return the number of values in the BST
		int GetSize() const;
	
	
		//!  Inserts value v into the BST
		//!  
		//!  @param v The new value being inserted
		//!
		//!  @return a pointer to the newly inserted node, or NULL if v was already
		//!          in the tree (i.e., NULL is used to indicate a duplicate insertion)
		BSTNode * Insert(const std::string & v);
	
	
		//!  Searches the tree for value v
		//!  
		//!  @param v The new value being searched for
		//!
		//!  @return a pointer to the node containing v, or NULL if v is not in the tree
		BSTNode * Find(const std::string & v) const;
	
		void print() const;
	
		//! @NOTE: YOU ARE NOT REQUIRED TO IMPLEMENT THE Remove METHOD BELOW
		//!        (BUT YOU CAN IF YOU WANT TO)
		//!
		//!  Removes value v from the tree
		//!  
		//!  @param v The value being removed from the tree
		//!
		//!  @return true if v was removed from the tree, or false if v was not in the tree
		//bool Remove(const std::string & v);
	
	private:
		BSTNode * top;
		int size;
		void insertNode(BSTNode* &prevNode, BSTNode * inNode);
		void printTree(BSTNode* Node) const;
		BSTNode * findNode(BSTNode * top, const std::string & v)const;
		void removeNodes(BSTNode * Node);
		BSTNode* copyTree(BSTNode* otherNode);
};


#endif
