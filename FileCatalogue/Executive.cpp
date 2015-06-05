/**************************************************************************************************
*FileName      : Executive.cpp - Implementation File for start of execution
*Author        : Abdulvafa Choudhary, SUID : 671290061, CE Fall'14, Syracuse University
*                aachoudh@syr.edu@syr.edu, (315) 289-3444
*Version       : 1.0
*Language      : C++11
*Platform      : Windows 7 ultimate, HP Pavillion G6 -64bit(core2duo), Microsoft Visual Studio Professional 2013.
*Application   : Project # 1 ,Object Oriented Design CSE 687
***************************************************************************************************/
#include "Executive.h"
#include "../FileSystemDemo/FileSystem.h"

Executive::Executive(){

	cat = new Catalogue();
	display = new Display();
	findDuplicates = false;
	textsearch = false;
	keyword = "";
};

Executive::~Executive(){
	delete cat;
	delete display;
};

void Executive::setCatalogue(Catalogue* value){
	cat = value;
}

void Executive::setDisplay(Display* value){

	display = value;
}
void Executive::isFindDuplicates(bool val){
	findDuplicates = val;
}
void Executive::istextSearch(bool val){
	textsearch = val;
}
void Executive::setKeyword(std::string val){

	keyword = val;
}
Catalogue* Executive::getCatalogue(){

	return cat;
}
Display* Executive::getDisplay(){
	return display;
}
bool  Executive::getFindDuplicates(){
	return findDuplicates;
}
bool Executive::getTextSearch(){
	return textsearch;
}

std::string Executive::getKeyword(){
	return keyword;
}

//start of processing the user commands
void Executive::startProcessing(int argc,char** argv){

	cat->isRecurse(false);
	FileSystem::Directory::setCurrentDirectory(".");
	std::string path = FileSystem::Directory::getCurrentDirectory();

	if (argc < 2){
		cat->addPattern("*.*");
		cat->storeFile(path);
		display->displayResult(cat);
		newTextSearch();
		return ;
	}
	int t = 0;
	for (int j = 1; j < argc; ++j)
	{
		if ((argv[j][0] != '/') && (t == 0))
		{
			path = argv[j];
			FileSystem::Directory::setCurrentDirectory(path);
			path = FileSystem::Directory::getCurrentDirectory();
			t = t + 1;
		}
		if ((argv[j][0] == '/') && (argv[j][1] == 's'))
			cat->isRecurse(true);

		if ((argv[j][0] == '/') && (argv[j][1] == 'd'))
			isFindDuplicates( true);
		
		if ((argv[j][0] == '/') && (argv[j][1] == 'f')){

			istextSearch(true);
			std::string tmp = argv[j+1];
			tmp = tmp.substr(1, tmp.length() - 2);
			setKeyword(tmp);
		}
		else
			cat->addPattern(argv[j]);	
	}

	cat->storeFile(path);
	display->displayResult(cat);

	if (getFindDuplicates())
		cat->findDuplicates();

	if (getTextSearch())
		doTextSearch();
	newTextSearch();
}

void Executive::doTextSearch(){
	display->setFilesList(cat->textSearch(getKeyword()));
	display->txtSearchResults();
}

void Executive::newTextSearch(){

	display->searchTitle("Enter the text to be searched");
	std::string keywrd;
	getline(std::cin, keywrd);
	if (keywrd == ""){

		std::cout << std::endl;
		std::cout << "Exiting Application !!!!!" << std::endl;
		exit(0);
	}
	display->searchTitle("Enter file patterns(for multiple patterns put space between them) ");
	std::string newPat;
	getline(std::cin, newPat);
	std::istringstream buf(newPat);
	std::istream_iterator<std::string> beg(buf), end;
	std::vector<std::string> newPatterns(beg, end);
	display->setFilesList(cat->textPatternSearch(keywrd, newPatterns));
	display->txtSearchResults();
	newTextSearch();
}

int main(int argc, char* argv[])
{
	Executive* exec = new Executive();
	exec->startProcessing(argc, argv);
}

