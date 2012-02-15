/*
 * XMLGenerator.h
 *
 *  Created on: Feb 10, 2012
 *      Author: jared
 */

#ifndef XMLGENERATOR_H_
#define XMLGENERATOR_H_

#include "PageHistory.h"
#include "WordIndex.h"
#include <fstream>

//Creates XML output summary of index, history and start_url
class XMLGenerator{
	//Contains history of pages indexed
	PageHistory history;
	//Contains the queue of pages
	WordIndex index;
	//contains the start_url of the web crawler
	string start_url;
	//contins the finalized xml of the output
	string xml;
public:
	//Default constructor
	XMLGenerator(const PageHistory arg_history, const WordIndex arg_index, const string arg_start_url): 
			history(arg_history), index(arg_index), start_url(arg_start_url) {
	}

	//Default Deconstructor
	~XMLGenerator(){
	}

	//Creates the finalized output and writes it to the file named "output.xml"
	void writeFile() const;
private:
	//Creates a tag and places it in the variable xml
	//@par value - the string to place inside of the tag
	void createTag(string value);

	//Adds text to the xml output
	//@par text - text to be added to the xml output
	void addText(const string text);

};

#endif /* XMLGENERATOR_H_ */
