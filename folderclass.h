#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "filesclass.h"
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
	files* filesArray[10];
	folder* folderArray[5];
public:
	folder(string newName, int newSize) {
		srand(time(0)); // sets the seed for rand() using time.

		name = newName;
		size = rand() % 100 + 1;//generates rand number between 1-100
		dOfCreation = time(0); // current time based on system
	}

	/// <summary>
	/// Returns the name of the folder
	/// </summary>
	/// <returns></returns>
	string getFolderName();

	/// <summary>
	/// returns the size of the folder
	/// </summary>
	/// <returns></returns>
	string getFolderSize();

	/// <summary>
	/// returns the date of creation of a folder
	/// </summary>
	/// <returns></returns>
	string getFolderDate();

	/// <summary>
	/// Changes the name of the folder
	/// </summary>
	/// <param name="newName"></param>
	void changeFolderName(string newName);

	/// <summary>
	/// Print all information stored on the folder
	/// </summary>
	void printAllInfo();

	/// <summary>
	/// Adds a new pointer to a folder to an empty space on the array of folders 
	/// </summary>
	/// <param name="newFolder"></param>
	void addFolder(folder* newFolder);

	/// <summary>
	/// switch out a folder in an array
	/// </summary>
	/// <param name="oldFolder"></param>
	/// <param name="newFolder"></param>
	void changeFolderArray(string oldFolder, folder* newFolder);

	void addFile(folder* newfile);

	void changeFileArray(string oldFile, files* newFile);

	void printFolderInfo() {
		cout << name << endl;
		cout << size << endl;
		cout << dOfCreation << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << filesArray[i] << ", ";
		}
	}
};