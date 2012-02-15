/*
 * PageQueue.h
 *
 *  Created on: Feb 10, 2012
 *      Author: jared
 */

#ifndef PAGEQUEUE_H_
#define PAGEQUEUE_H_

//Holds the list of pages that need to be indexed
class PageQueue{
public:
	//Default Constructor
	PageQueue(){
	}

	//Default Deconstructor
	~PageQueue(){
	}

	//Pushes a page on the the queue
	//@par page - the page to be inserted onto the queue
	void push(Page page);

	//Removes and returns a copy of 
	//the next page on the queue
	Page pop();

private:
	//The linked list that holds the list
	//of pages that need to be indexed
	LinkedList<Page> queue;
};

#endif /* PAGEQUEUE_H_ */
