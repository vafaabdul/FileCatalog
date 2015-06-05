/**************************************************************************************************
*FileName      : Display.cpp - Implementation File for displaying hte results
*Author        : Abdulvafa Choudhary, SUID : 671290061, CE Fall'14, Syracuse University
*                aachoudh@syr.edu@syr.edu, (315) 289-3444
*Version       : 1.0
*Language      : C++11
*Platform      : Windows 7 ultimate, HP Pavillion G6 -64bit(core2duo), Microsoft Visual Studio Professional 2013.
*Application   : Project # 1 ,Object Oriented Design CSE 687
***************************************************************************************************/

#include "Display.h"
#include <iostream>
#include <string>


void Display::setFilesList(Display::Files list){
	files = list;
}

//display the heading
static void title(const std::string& title, char underscore = '=')
{
	std::string tempStr = "\n  " + title + "\n " + std::string(title.size() + 2, underscore);
	std::cout << tempStr;
	std::cout << "\n";
}

//display the heading of search results
void Display::searchTitle(const std::string& title,char hyphen)
{
	std::string tempStr = "\n  " + title + "\n " + std::string(title.size() + 2, hyphen);
	std::cout << tempStr;
	std::cout << "\n";
}

//display the result of text search
void Display::txtSearchResults(){

	if (files.size()==0){

		std::cout << std::endl;
		std::cout<<"No Files contain the given text !!!!!!!!"<<std::endl;
	}
	else{
		title("The given text is present in the following files :");

		for (auto file : files){

			std::cout << "File : " + file.first << std::endl;
			std::cout << "Path :" + file.second << std::endl;
			std::cout << std::endl;
		}
	}
}

//display the file catalog
void Display::displayResult(Catalogue* cat){

	auto iterator = cat->getDataStore()->begin();
	title("CATALOGUE");
	for (iterator; iterator != cat->getDataStore()->end(); ++iterator){
		std::cout << "File : " + iterator->first<< std::endl;
		std::cout << "Paths:" << std::endl;
		DataStore::ListOfIters listofIter = iterator->second;
		for (auto iter = listofIter.begin(); iter != listofIter.end(); ++iter){

			std::cout << **iter << std::endl;

		}
		std::cout << std::endl;
	}
	std::string print = "Found " + std::to_string(cat->getNoFiles()) + " Files in " + std::to_string(cat->getNoDirectories()) + " Directories";
	title("SUMMARY");
	std::cout << print << std::endl;

}

#ifdef TEST_DISPLAY

void main(){

	Catalogue* cat=new Catalogue();
	Display* d=new Display();
	cat->isRecurse(true);
	cat->addPattern("*.*");
	std::string path="C://Tmp";
	std::string Keyword = "pattern";
	cat->storeFile(path);
	cat->findDuplicates();
	cat->textSearch(keyword);
	d->displayResult(cat);
	d->txtSearchResults();
	delete cat;

}

#endif