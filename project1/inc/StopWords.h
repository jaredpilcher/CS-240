/*
 * StopWords.h
 *
 *  Created on: Feb 10, 2012
 *      Author: jared
 */

#ifndef STOPWORDS_H_
#define STOPWORDS_H_

#define MAX 32000

//Contains the array of stop words
//Contains tools for the array of stop words
class StopWords{
	string stop_words[MAX];
public:
	//Default Constructor
	StopWords(){
	}

	//Default Deconstructor
	~StopWords(){
	}

	//Retrieves all of the words from the stop_words file
	//Places words into the stop_words array
	//@par stop_file - file url of the stop words file
	void getWords(string stop_file);

	//Determines if the given word is a stop word
	//@par word - word to be found
	void isStopWord(string word);
private:
};

#endif /* STOPWORDS_H_ */
