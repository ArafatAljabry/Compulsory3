#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h> 
using namespace std;

// Both: name, size and date of creation, creation of new folder and file; rand size up to 100,name, size and date(function)
//       change name(function) print all info(with folder include files within)
// Folder: array of maximum 10 files and array of maximum 5 folders


/// <summary>
/// Class to create folder objects containing the name,size and date
/// </summary>
class folder {
private:
	string name;
	int size;
	string dOfCreation;
	string filesArray[10];
	string folderArray[5];
public:
	folder(string newName, int newSize) {
		name = newName;
		size = rand()%101;//generates rand number between 1-100
		dOfCreation = time(0); // current time based on system

		
		
	}
	/// <summary>
	/// Changes the name of the folder
	/// </summary>
	/// <param name="newName"></param>
	void changeFolderName(string newName){
		name = newName;
	}
	/// <summary>
	/// Print all information stored on the folder
	/// </summary>
	void printAllInfo(){}

	/// <summary>
	/// Adds a 
	/// </summary>
	/// <param name="newFolderArray"></param>
	void addFolder(string newFolderArray[5]) {
		for (int i = 0; i < 5; i++) {
			folderArray[i] = newFolderArray[i];
		}
	}
	void addFile(string newFilesArray[10]) {

		for (int i = 0; i < 10; i++) {
			filesArray[i] = newFilesArray[i];
		}

	}

};