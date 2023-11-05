#pragma once
#pragma warning (disable: 4996)
#include "filesclass.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

/// <summary>
/// Class to create folder objects containing the name,size and date
/// </summary>
class folder {
private:
	string name;
	int size;
	//current time based on system
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

	~folder(){
		cout << "Folder deleted" << endl;
	}

	/// <summary>
	/// gets the folderArray and save it to a given array. 
	/// </summary>
	void getFolderArray(folder* arrayToUpdate[5]) {
		for (int i = 0; i < 5; i++)
		{
			arrayToUpdate[i] = folderArray[i];
		}
	}

	/// <summary>
	/// gets the filesArray and save it to a given array. 
	/// </summary>
	void getFilesArray(files* arrayToUpdate[5]) {
		for (int i = 0; i < 10; i++)
		{
			arrayToUpdate[i] = filesArray[i];
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
	int getFolderSize() {
		return size;
	}
	
	/// <summary>
	/// Get the date of which the of the folder was made
	/// </summary>
	/// <returns></returns>
	string getFolderDate() {
		return dOfCreation;
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
	bool addFolder(folder* newFolder) {
		for (int i = 0; i < 5; i++) {
			if (folderArray[i] == nullptr)
			{
				folderArray[i] = newFolder;
				return true;
				
			}
		}
		return false;
		
	}
	
	/// <summary>
	/// Adds new file to an open space in the objects file array
	/// </summary>
	/// <param name="newFile"></param>
	void addFile(files* newFile) {
		for (int i = 0; i < 10; i++)
		{
			if (filesArray[i] == nullptr) {
				filesArray[i] = newFile;
				cout << endl << "File added to " + getFolderName() << endl;
				break;
			}
			else {
				cout << endl << "Folder is full" << endl;
				break;
			}
		}
	}

	/// <summary>
	/// Change the file in the array
	/// </summary>
	void changeFileArray(string oldFile, files* newFile) {
		for (int i = 0; i < 9; i++)
		{
			if (filesArray[i]->getFilesName() == oldFile) {
				filesArray[i] = newFile;
			}
		}
	}

	/// <summary>
	/// Print content of folder
	/// </summary>
	void printFolderInfo() {
		cout << name << endl
			<< size << endl
			<< dOfCreation << endl;

		cout << "Folders: " << endl;
		for (int i = 0; i < 5; i++)
		{
			if (folderArray[i] == nullptr) {
				cout << "Empty, ";
			}
			else {
				cout << folderArray[i] <<", ";

			}
		}

		cout << "Files: " << endl;
		for (int i = 0; i < 10; i++)
		{
			if (filesArray[i] == nullptr) {
				cout << "Empty, ";
			}
			else {
				
				cout << filesArray[i] << ", ";

			}
		}
	}
};