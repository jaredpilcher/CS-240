/*
 * WebCrawler.cpp
 *
 *  Created on: Feb 10, 2012
 *      Author: jared
 */
using namespace std;

void WebCrawler::CrawlWeb(){
	PageDownloader downloader;
	WordIndex index;
	HTMLParser parser(start_url);
	StopWords stop_words;
	PageHistory history;
	PageQueue queue;
	XMLGenerator generator(history, queue);
	string word, page_string;

	//create new page and place in queue and history
	Page* page = new Page(start_url);
	queue.push(page);
	history.push(page);

	stop_words.getWords(stop_file);

	while(!queue.empty()){
		//pop page from queue
		page = queue.pop();
		//Download page
		page_string = downloader.download(page);
		//Parse string returned from downloader
		parser.setNewPageString(page_string);
		//Determine if this is a valid page
		if(!parser.isHTML()){
			history.pop(page);
			continue;
		}
		//Grab the description and set to page
		page->setDescription(parser.getDescription());
		//Go through the html document and index words
		while(!parser.empty()){
			word =parser.getWord();
			if(!stop_words.isStopWord(word)){
				index.push(word, page->getURL());
			}
		}

		//Get links from html, create new page and push on queue and history
		while(parser.existNextLink()){
			page=new Page(parser.getLink());
			queue.push(page);
			history.push(page);
		}

	}

	generator.writeFile();

}
