#ifndef EXECUTIVE_H
#define EXECUTIVE_H

/**************************************************************************************************
*FileName      : Executive.h - Header File for start of execution
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
* This is the pacakge where the execution of the application starts
*
* Maintenance History:
* --------------------
* ver 1.0 : 10 Feb 2015
* - first release
*
*/

#include "Catalogue.h"
#include "Display.h"
#include <iostream>
#include <sstream>

class Executive{

private:
	Catalogue *cat;
	Display *display;
	bool findDuplicates;
	bool textsearch ;
	std::string keyword;

public:
	Executive();
	~Executive();
	void setCatalogue(Catalogue* value);
	void setDisplay(Display * value);
	void isFindDuplicates(bool val);
	void istextSearch(bool val);
	void setKeyword(std::string val);
	Catalogue* getCatalogue();
	Display* getDisplay();
	bool  getFindDuplicates();
	bool getTextSearch();
	std::string getKeyword();
	void startProcessing(int argc, char** argv);
	void newTextSearch();
	void doTextSearch();
};
#endif