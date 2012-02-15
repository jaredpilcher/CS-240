/*
 * OccurrenceSet.h
 *
 *  Created on: Feb 10, 2012
 *      Author: jared
 */

#ifndef OCCURRENCESET_H_
#define OCCURRENCESET_H_

//A set of occurrences on pages
class OccurrenceSet{
public:
	
	//Default Constructor
	OccurrenceSet(){
	}
	
	//Default Deconstructor
	~OccurrenceSet(){
	}

	//Places an occurrence, or increments the
	//count of an occurrence on the class BST
	//@par page - the page that the word was found
	//@par word - the word that was found
	void push(Page page, string word);

	//Return a unique Occurrence
	//WARNING: only returns the occurrence once
	void pop();

private:
	//The BST that holds the set of occurrences
	BST<Occurrence> occurrences;
};

#endif /* OCCURRENCESET_H_ */
