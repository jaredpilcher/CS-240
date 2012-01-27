#include <string>

//! LLNode implements a doubly-linked list node
class LLNode 
{		
		friend class LinkedList;  //!< LinkedList can access private members of LLNode
	public:
	
		//!  Constructor
		LLNode(const std::string & v, LLNode * p, LLNode * n);
		
		//! Copy Constructor 
		LLNode(const LLNode & other);
	
		//!  Read-only public methods for use by clients of the LinkedList class
		const std::string & GetValue() const;
	
		LLNode * GetPrevious() const;
	
		LLNode * GetNext() const;
		
		//! Assignment operator 
		LLNode & operator=(const LLNode & other);
	
	private:
		std::string value;        //!< value stored in the node
		LLNode * prev;            //!< pointer to previous node in the list
		LLNode * next;            //!< pointer to next node in the list
};
