/*
 * XMLGenerator.h
 *
 *  Created on: Feb 10, 2012
 *      Author: jared
 */

using namespace std;

void XMLGenerator::writeFile() const{
	createTag("website");
	createTag("start-url");
	addText(start_url);
	createTag("/start-url");
	createTag("pages");
	createPageTags();
	createTag("/pages"
	createTag("index");
	createWords();
	createTag("/index");
	createTag("/website");
	
	ofstream xml_file("output.xml");
	xml_file << xml;
}

void XMLGenerator::createTag(string value){
	EncodeToXml(value);
	xml.append("<" + value + ">");
}

void XMLGenerator::addText(const string text){
	EncodeToXml(text);
	xml.append(text);
}
