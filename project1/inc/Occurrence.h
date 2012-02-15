/*
 * Occurrence.h
 *
 *  Created on: Feb 10, 2012
 *      Author: jared
 */

#ifndef OCCURRENCE_H_
#define OCCURRENCE_H_

#include "Page.h"

//An occurrence of a word that is noted on a website
class Occurrence{
public:
	//Default Constructor
	Occurrence(const Page arg_page): page(arg_page), count(1){
	}

	//Default Deconstructor
	~Occurrence(){
	}

	//Increments the number of occurrences on the page
	void addOccurrence();

private:
	//The number of times the occurrence happens
	int count;

	//The page that the occurrence occurs on
	Page page;
};

#endif /* OCCURRENCE_H_ */
