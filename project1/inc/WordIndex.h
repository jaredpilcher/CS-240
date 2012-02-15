/*
 * WordIndex.h
 *
 *  Created on: Feb 10, 2012
 *      Author: jared
 */

#ifndef WORDINDEX_H_
#define WORDINDEX_H_

#include "OccurrenceSet.h"

//Contains an index of words and pages, and tools to use the index
class WordIndex{
public:

	//Default Constructor
	WordIndex(){
	}

	//Default Deconstructor
	~WordIndex(){
	}

	//Index a word in the given url
	//@par word - the word to be indexed
	//@par url - the url that the word was found on
	void push(const string word, const string url);

	//Get a unique OccurrenceSet. 
	//WARNING: this only gives a different occurrence set once
	//@ret OccurenceSet - A unique occurrence set
	OccurrenceSet pop();
private:
};

#endif /* WORDINDEX_H_ */
