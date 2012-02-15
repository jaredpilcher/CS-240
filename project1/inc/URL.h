/*
 * URL.h
 *
 *  Created on: Feb 10, 2012
 *      Author: jared
 */

#ifndef URL_H_
#define URL_H_

//Tools to handle url specific functions
class URL{
public:
	//Default Constructor
	URL(){
	}

	//Default Deconstructor
	~URL(){
	}

	//Joins two urls
	//@par url1 - first url to be joined
	//@par url2 - second url to be joined
	//@ret string - url that is joined together
	string join(string url1, string url2);

	//Removes the file name at the end of the url
	//@par url - url to manipulate
	//@ret string - returns the manipulated string
	string removeFileName(string & url);

private:
};

#endif /* URL_H_ */
