/**************************************************************************************************
*FileName      : Catalogue.cpp - Implementation File for creation and operations on Catalog
*Author        : Abdulvafa Choudhary, SUID : 671290061, CE Fall'14, Syracuse University
*                  aachoudh@syr.edu@syr.edu, (315) 289-3444
*Version       : 1.0
*Language      : C++11
*Platform      : Windows 7 ultimate, HP Pavillion G6 -64bit(core2duo), Microsoft Visual Studio Professional 2013.
*Application   : Project # 1 ,Object Oriented Design CSE 687
***************************************************************************************************/

#include "Catalogue.h"
#include "../FileSystemDemo/FileSystem.h"
#include "DataStore.h"
#include <iostream>
#include <regex>



Catalogue::Catalogue(){

	dataStore = new DataStore();
	recurse = false;
}

Catalogue::~Catalogue(){

	delete dataStore;
}

//builds catalog
void Catalogue::storeFile(std::string path){


	if (patterns.size() == 0){
		addPattern("*.*");
	}

	FileSystem::Directory::setCurrentDirectory(path);

	for each (std::string pattern in patterns)
	{

		std::vector<std::string> files = FileSystem::Directory::getFiles(path, pattern);
		for each (std::string file in files)
		{
			dataStore->save(file, path);
		}

	}
	
	if (recurse){

		std::string curr=FileSystem::Directory::getCurrentDirectory();
		std::vector<std::string> dirs = FileSystem::Directory::getDirectories(path);

		for (int i = 2; i < dirs.size(); i++){
			storeFile(curr+"\\"+dirs[i]);
		}
	}
}

//sets flag for recursive search
void Catalogue::isRecurse(bool val){
	recurse = val;
}


//adds file pattern
void Catalogue::addPattern(std::string pattern){

	patterns.push_back(pattern);
}

//returns the the file catalog
DataStore* Catalogue::getDataStore()
{
	return dataStore;
}

// finds duplicate files in the catalog
void Catalogue::findDuplicates(){
	
	int count = 0;
	for (DataStore::iterator it = dataStore->begin(); it != dataStore->end(); ++it){

		if (it->second.size() > 1){

			if (count == 0){
				std::string title = "Duplicate files";
				std::string tempStr = "\n  " + title + "\n " + std::string(title.size() + 2, '=');
				std::cout << tempStr;
				std::cout << "\n";
			}
			std::cout << "FileName: ";
			std::cout << it->first << std::endl;
			std::cout << "Paths:" << std::endl;
			DataStore::ListOfIters listofIter = it->second;
			for (auto iter = listofIter.begin(); iter != listofIter.end();++iter){

				std::cout << **iter << std::endl;
				
			}
			std::cout << std::endl;
			count++;
		}
	}

	if (count == 0){
		std::cout << "No Duplicates Files Found !!!!!!!!" << std::endl;
	}
}

//searches for given text in the catalog
Catalogue::Files  Catalogue::textSearch(std::string keyword){


	for (DataStore::iterator it = dataStore->begin(); it != dataStore->end(); ++it)
	{
		std::string fileName = it->first;
		std::string filePath = **it->second.begin();
		FileSystem::File* myFile = new FileSystem::File(filePath + "//" + fileName);
		myFile->open(FileSystem::File::in);
		std::string contents = myFile->readAll();
		std::size_t found=contents.find(keyword);
		if (found != std::string::npos){
			files[fileName]=filePath;
		}
		myFile->close();
	}
	return files;
}

//narrows down the search based on patterns
Catalogue::Files Catalogue::textPatternSearch(std::string keyword,std::vector<std::string> patterns){

	files.clear();
	bool filesearch = false;
	bool allPatterns = false;
	if (patterns.size() == 0){
		allPatterns = true;
	}
	for (DataStore::iterator it = dataStore->begin(); it != dataStore->end(); ++it)
	{
		std::string fileName = it->first;
		std::string filePath = **it->second.begin();

		/*for (auto patt : patterns){
			std::regex exp("("+patt+")");
			if (std::regex_match(fileName, exp)){
				filesearch = true;
			}
		}*/

		for (auto patt : patterns){

			if (patt.compare("*.*")==0){
				allPatterns = true;
			}
			else{
				std::string ext = FileSystem::Path::getExt(fileName);
				ext = "*." + ext;
				if (ext.compare(patt) == 0)
					filesearch = true;

			}
		}

		if (filesearch || allPatterns){
			FileSystem::File* myFile = new FileSystem::File(filePath + "//" + fileName);
			myFile->open(FileSystem::File::in);
			std::string contents = myFile->readAll();
			std::size_t found = contents.find(keyword);
			if (found != std::string::npos){
				files[fileName] = filePath;
			}
			myFile->close();
			filesearch = false;
		}

	}
	return files;

}

//get the no of files in the catalog
int Catalogue::getNoFiles(){

	return dataStore->getStoreSize();
}

//get the number of directories
int Catalogue::getNoDirectories(){

	return dataStore->getPathSize();
}

#ifdef TEST_CATALOGUE

void main(){

	Catalogue* cat=new Catalogue();
	cat->isRecurse(true);
	cat->addPattern("*.*");
	std::string path="C://Tmp";
	std::string Keyword="pattern";
	cat->storeFile(path);
	cat->findDuplicates();
	cat->textSearch(keyword);
	delete cat;
}
#endif