#ifndef DISPLAY_H
#define DISPLAY_H
/**************************************************************************************************
*FileName      : Display.h - Header File for displaying hte results
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
* This package displays the required results on the console
*
* Maintenance History:
* --------------------
* ver 1.0 : 10 Feb 2015
* - first release
*
*/

#include <list>
#include "Catalogue.h"
class Display{

public:
	using fileName = std::string;
	using Files = std::map < fileName, std::string>;
	Display(){};
	~Display(){};
	void txtSearchResults();
	void setFilesList(Files list);
	void displayResult(Catalogue* cat);
	void searchTitle(const std::string& title, char underscore = '-');

private:
	Files files;
};

#endif