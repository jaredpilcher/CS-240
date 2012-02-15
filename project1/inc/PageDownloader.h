/*
 * PageDownloader.h
 *
 *  Created on: Feb 10, 2012
 *      Author: jared
 */

#ifndef PAGEDOWNLOADER_H_
#define PAGEDOWNLOADER_H_

#include "URLInputStream.h"

//Used to download html from webpages
class PageDownloader{
public:
	//Default Constructor
	PageDownloader(){
	}

	//Default Deconstructor
	~PageDownloader(){
	}

	//Downloads the html from a webpage
	//@par page - the page to be downloaded
	//@ret string - the html of the webpage
	string download(const Page & page);
private:
	//Retrieves the html from a given webpage and
	//stores it into page_text
	//@par url - the url for the html to be downloaded
	//@par page_text - the string to store the html text
	void getText(const string url, string & page_text);
};

#endif /* PAGEDOWNLOADER_H_ */
