#pragma once
#pragma warning(disable : 4996) // fix this shit
#include "filesclass.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <string>
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
	// current time based on system
	char* dOfCreation;
	files* filesArray[10];
	folder* folderArray[5];

public:
	folder(string newName) {
		srand((unsigned)time(0)); // sets the seed for rand() using time.
		name = newName;
		size = rand() % 100 + 1;//generates rand number between 1-100		
		time_t timeNow = time(0);
		dOfCreation = ctime(&timeNow);
		for (int i = 0; i < 5; i++)
		{
			folderArray[i] = nullptr;
			filesArray[i] = nullptr;
		}
	}



	/// <summary>
	/// Get the name of the folder
	/// </summary>
	string getFolderName() {
		return name;
	}

	/// <summary>
	/// Get the size of the folder
	/// </summary>
	string getFolderSize() {
		return size + "mb";
	}
	
	/// <summary>
	/// Get the date of which the of the folder was made
	/// </summary>
	/// <returns></returns>
	string getFolderDate() {
		return dOfCreation;
	}

	
	
	void getFoldersFromArray() {
		for (int i = 0; i < 5; i++)
		{
		cout << folderArray[i] << ", ";
		}
	}


	/// <summary>
	/// Change name of the folder
	/// </summary>
	/// <param name="newName"></param>
	void changeFolderName(string newName) {
		name = newName;
	}
	/// <summary>
	/// Adds folder to the array of folders
	/// </summary>
	void addFolder(folder* newFolder) {
		for (int i = 0; i < 5; i++) {
			if (folderArray[i] == nullptr)
			{
				folderArray[i] = newFolder;
				break;
			}
		}
		cout << "done did-it";
	}

	
	void changeFolderArray(string oldFolder, folder* newFolder) {
		for (int i = 0; i < 5; i++)
		{
			if (folderArray[i]->name == oldFolder) {
				folderArray[i] = newFolder;
			}
		}
	}
	
	
	int addFile(files* newFile) {
		for (int i = 0; i < 10; i++)
		{
			if (filesArray[i] == nullptr) {
				filesArray[i] = newFile;
				cout << "File added to " + getFolderName();
				return 0;
				break;
			}
			else {
				cout << "Folder is full";
				return 1;
				break;
			}
		}
	}
	/// <summary>
	/// Change the file in the array
	/// </summary>
	void changeFileArray(string oldFile, files* newFile) {
		for (int i = 0; i < 10; i++)
		{
			if (filesArray[i]->getFileName() == oldFile) {
				filesArray[i] = newFile;
			}
		}
	}

	/// <summary>
	/// prints info on the folder
	/// </summary>
	void printFolderInfo() { 
		cout << name << endl;
		cout << size << endl;
		cout << dOfCreation << endl;
		for (int i = 0; i < 5; i++)
		{
			if(folderArray[i] != nullptr)
			{
				cout << folderArray[i]->getFolderName() << ", ";
			}
			else {
				cout << "Empty,";
			}
		}
	}

	void deletus() {
		//todo: delete the thang
	}

	
};