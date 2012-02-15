/*
 * PageHistory.h
 *
 *  Created on: Feb 10, 2012
 *      Author: jared
 */

#ifndef PAGEHISTORY_H_
#define PAGEHISTORY_H_
#include "BST.h"

//Contains the history of pages that have been indexed
class PageHistory{
public:
	//Default Constructor
	PageHistory(){
	}

	//Default Deconstructor
	~PageHistory(){
	}
	
	//Push the page onto the history BST
	//@par page - page to be inserted
	void push(Page page);
	
	//Remove the page that matches the argument
	//from the BST
	//@par page - page to be removed
	void pop(Page page);

private:
	//The BST to hold the history of pages
	BST<Page> history;
};

#endif /* PAGEHISTORY_H_ */
