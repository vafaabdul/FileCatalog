#ifndef CATALOGUE_H
#define CATALOGUE_H
/**************************************************************************************************
*FileName      : Catalogue.h - Header File for creation and operations on Catalog
*Author        : Abdulvafa Choudhary, SUID : 671290061, CE Fall'14, Syracuse University
*                aachoudh@syr.edu@syr.edu, (315) 289-3444
*Version       : 1.0
*Language      : C++11
*Platform      : Windows 7 ultimate, HP Pavillion G6 -64bit(core2duo), Microsoft Visual Studio Professional 2013.
*Application   : Project # 1 ,Object Oriented Design CSE 687
***************************************************************************************************/
/*
* Module Operations:
* ------------------
* This package builds the file catalog and provides functions to do 
* operations on the same 
*
* Maintenance History:
* --------------------
* ver 1.0 : 10 Feb 2015
* - first release
*
*/

#include "DataStore.h"
#include <vector>

class Catalogue
{
public:
	using fileName = std::string;
	using Files = std::map < fileName,std::string > ;
	Catalogue();
	~Catalogue();
	void storeFile(std::string path);
	void isRecurse(bool val);
	void addPattern(std::string pattern);
	DataStore* getDataStore();
	void findDuplicates();
	Files textSearch(std::string keyword);
	int getNoFiles();
	int getNoDirectories();
	Files textPatternSearch(std::string keyowrd,std::vector<std::string> patterns);
	std::vector<std::string> patterns;


private:
	DataStore *dataStore;
	Files files;
	bool recurse;


};


#endif