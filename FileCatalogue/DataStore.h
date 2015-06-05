#ifndef DATASTORE_H
#define DATASTORE_H
/**************************************************************************************************
*FileName      : DataStore.h - Header File for storing file and paths
*Author        : Abdulvafa Choudhary, SUID : 671290061, CE Fall'14, Syracuse University
*                aachoudh@syr.edu@syr.edu, (315) 289-3444
*Version       : 1.0
*Language      : C++11
*Platform      : Windows 7 ultimate, HP Pavillion G6 -64bit(core2duo), Microsoft Visual Studio Professional 2013.
*Application   : Project # 1 ,Object Oriented Design CSE 687
*Reference     : Dr.Jim Fawcett's Code help on DataStore
***************************************************************************************************/
/*
* Module Operations:
* ------------------
* This Class provides a data strucutre for saving all the files and
* their corresponding paths.
*
*
* Maintenance History:
* --------------------
* ver 1.0 : 10 Feb 2015
* - first release
*
*/

#include <set>
#include <list>
#include <map>
#include <string>
#include <vector>

class DataStore{

	public:
		DataStore(){};
		~DataStore(){};
		using Path = std::string;
		using Paths = std::set < Path >;
		using PathIter = Paths::iterator;
		using ListOfIters = std::list < PathIter >;
		using File = std::string;
		using Store = std::map < File, ListOfIters >;
		using iterator = Store::iterator;

		void save(const std::string& fileName, const std::string& path);
		iterator begin(){ return store.begin(); }
		iterator end(){ return store.end(); }
		int  getStoreSize();
		int getPathSize();

	private:
		Store store;
		Paths paths;

	};

#endif