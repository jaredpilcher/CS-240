/*
 * HTMLParser.cpp
 *
 *  Created on: Feb 10, 2012
 *      Author: jared
 */

#include "HTMLParser.h"

void HTMLParser::setNewPageString(const string page_text){
	words.Clear();
	links.Clear();
	findWords(page_text);
	html_page= determineIfHTML(page_text);
	description = findDescription(page_text);
}

void HTMLParser::findWords(const string page_text){
	HTMLTokenizer tokenizer;
	HTMLToken token, next_ token;
	while(tokenizer.HasNextToken()){
		token = tokenizer.GetNextToken()
		if(token.GetType()==TAG_START){
			if(token.GetValue()=="<TITLE>" ||
			   token.GetValue()=="<HTML>"  ||
			   token.GetValue()=="<A>"     ||
			   token.GetValue()=="<BODY>"  ||
		       token.GetValue()=="<H1>"    ||
			   token.GetValue()=="<H2>"    ||
			   token.GetValue()=="<H3>"    ||){
	
				next_token = tokenizer.GetNextToken();
				if(next_token.GetType()==TEXT){
					insertWords(next_token);
				}
			}
		}
	}
}

void HTMLParser::insertWords(HTMLToken token){
	string value = token.GetValue();
	while(value != ""){
		word = getNextWord(value);
	}
	words.Insert(word);
}

