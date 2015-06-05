/**************************************************************************************************
*FileName      : DataStore.cpp - Implementation File for storing file and paths
*Author        : Abdulvafa Choudhary, SUID : 671290061, CE Fall'14, Syracuse University
*                  aachoudh@syr.edu@syr.edu, (315) 289-3444
*Version       : 1.0
*Language      : C++11
*Platform      : Windows 7 ultimate, HP Pavillion G6 -64bit(core2duo), Microsoft Visual Studio Professional 2013.
*Application   : Project # 1 ,Object Oriented Design CSE 687
*Reference     : Dr.Jim Fawcett's Code help on DataStore
***************************************************************************************************/
#include "DataStore.h"

//saves the file name and its path in data store
void DataStore::save(const std::string& fileName, const std::string& path)
{

	if (store.count(fileName) == 0){

		std::pair<DataStore::PathIter,bool> ret=paths.insert(path);
		ListOfIters newListIter;
		newListIter.push_back(ret.first);
		store[fileName] = newListIter;

	}
	else{

		std::pair<DataStore::PathIter, bool> retIt = paths.insert(path);
		Store::iterator storeIter = store.find(fileName);
		storeIter->second.push_back(retIt.first);
	
	}

};

//returns the number of files
int DataStore::getStoreSize(){

	return store.size();
}

//returns the number of paths
int DataStore::getPathSize(){
	return paths.size();
}


#ifdef TEST_DATASTORE

void main(){
	DataStore* ds=new DataStore();
	std::string filename1 = "Abdul.cpp";
	std::string filename2 = "Abdul.h";
	std::string pathname1_1 = "C:\\Tmp";
	std::string pathname1_2 = "D:\\Tmp";
	std::string pathname1_3 = "C:\\Tmp";
	std::string pathname2_1 = "C:\\Tmp";
	std::string pathname2_2 = "C:\\Tmp";
	std::string pathname2_3 = "D:\\ADS";
	ds->save(filename1, pathname1_1);
	ds->save(filename1, pathname1_2);
	ds->save(filename1, pathname1_3);
	ds->save(filename2, pathname2_1);
	ds->save(filename2, pathname2_2);
	ds->save(filename2, pathname2_3);
	for (DataStore::iterator iter = ds->begin(); iter != ds->end(); ++iter){
		int i = 0;
		cout << endl << "FileName :" + iter->first << endl;
		cout << endl << "Paths";
		for (DataStore::ListOfIters::iterator it = iter->second.begin(); it != iter->second.end(); ++it){
			cout << ++i << "." << **it << '\n';
		}
		cout << '\n';
	}

	delete ds;
}
#endif
