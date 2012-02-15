/*
 * PageDownloader.cpp
 *
 *  Created on: Feb 10, 2012
 *      Author: jared
 */
using namespace std;
#include "PageDownloader.h"

string PageDownloader::download(const Page & page){
	string page_text;
	getText(page.getURL(), page_text);
	page_text;
}

void getText(const string url, string & page_text){
	URLInputStream input_stream(url);
	while(!input_stream.IsDone()){
		page_text.append(1,input_stream.Read());
	}
}
