#include "folderclass.h"
#include "filesclass.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
using namespace std;

/// <summary>
/// validate the input for an int
/// </summary>
/// <param name="input"></param>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns>input</returns>
int validateInt(int input,int min, int max) {
	for (;;) {
		if (cin >> input && input> min && input < max) {
			break;
		}
		else {
			cout << "Not valid input" << endl;
			//clears I/O before asking again if wrong input
			//avoids infinite loop since cin saves input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return input;
}


/// <summary>
/// create a folder and add to current folder
/// </summary>
/// <param name="currentFolder"></param>
/// <param name="nameOfFolder"></param>
void createFolder(folder* currentFolder, string nameOfFolder) {
	
	folder* newFolder = new folder(nameOfFolder);
	if (currentFolder->addFolder(newFolder)) {
		cout << "Folder created" << endl;
	}
	//if addFolder() was not successful 
	else { cout << "Folder was not created for lack of space" << endl; }
}

/// <summary>
/// create a file and add to current folder
/// </summary>
/// <param name="addToFolder"></param>
/// <param name="nameOfFile"></param>
void createFile(folder* thisFolder, string nameOfFile) {
	files* newFile = new files(nameOfFile);
	thisFolder->addFile(newFile);
}


int main() 
{	

	int menuChoice = 0;
	string nameOfFolder;
	string nameOfFile;
	int biggestFile = 0;

	//parent folder to hold them all
	folder* parentFolder = new folder("parent");
	//holds on the current folder
	folder* currentFolder = parentFolder;
	folder* previousFolder = parentFolder;
	//vector to hold previousFolder as one gets deeper
	vector<folder*> previousFoldersBackLog;
	
	// An array to use for displaying content in folders
	folder* currentFolderArray[5];
	//Display files
	files* currentFilesArray[10];
	

	do {
		cout << "Any change will be done to the folder you are in (current Folder)" << endl << endl;
		// fill the array with "currentFolder" data
		currentFolder->getFolderArray(currentFolderArray);
		//get the files
		currentFolder->getFilesArray(currentFilesArray);
		//Show where you are and where you can go
		cout << "Previous Folder: " + previousFolder->getFolderName() << endl;
		cout << "Current Folder: " + currentFolder->getFolderName() << endl <<endl;
		//List folders
		cout << "Folders: " << endl;
		for (int i = 0; i < 5; i++)
		{
			//Lets you know if a value in folders folder array is empty
			if (currentFolderArray[i] == nullptr) {
				cout << "Empty, ";
			}
			else {
				cout << currentFolderArray[i]->getFolderName() + ", ";
			}
		}
		//list files
		cout << endl << endl << "Files: " << endl;
		for (int i = 0; i < 10; i++)
		{
			if (i == 5) {
				if (currentFilesArray[i] == nullptr) {
					cout << endl << "Empty, ";
					continue;
				}
			}
			//Lets you know if a value in folders files array is empty
			if (currentFilesArray[i] == nullptr) {
				cout << "Empty, ";
			}
			else {
				cout << currentFilesArray[i]->getFilesName() + ", ";
			}
		}
		
		cout << endl << endl << "(1) Move to folder" << endl
			<< "(2) Previous folder" << endl
			<< "(3) Create folder" << endl
			<< "(4) Create file" << endl
			<< "(5) Rename file" << endl
			<< "(6) Rename folder" << endl
			<< "(7) Delete folder" << endl
			<< "(8) Delete file" << endl
			<< "(9) Biggest file in this folder" << endl
			<< "(10) End program" << endl
			<< endl << "Choose: ";
		
		switch (validateInt(menuChoice,0,11))
		{
		case 1:
			//move to a folder
			cout << "Name: ";
			cin >> nameOfFolder;

			for (int i = 0; i < 5; i++)
			{
				if (currentFolderArray[i] == nullptr || currentFolderArray[i]->getFolderName() != nameOfFolder) { continue; }
				
				previousFoldersBackLog.push_back(currentFolder);
				previousFolder = currentFolder;
				currentFolder = currentFolderArray[i];
				break;
				
			}
			if (currentFolder == previousFolder) {
				cout << endl << nameOfFolder << " does not exist." << endl;
			}
			break;

		case 2:
			//returns to previous folder if there is one
			currentFolder = previousFoldersBackLog.back();
			if (previousFolder == parentFolder) {
				previousFolder = parentFolder;
			}
			else {
				previousFolder = previousFoldersBackLog.at(previousFoldersBackLog.size()-2);
				previousFoldersBackLog.pop_back();
			}

			previousFolder->getFolderArray(currentFolderArray);
			break;

		case 3:
			//create folder
			cout << "Name of folder: ";
			cin >> nameOfFolder;
			//create a new folder and add it to parent folder
			createFolder(currentFolder, nameOfFolder);
			break;

		case 4:
			// create file
			cout << "Name of File: ";
			cin >> nameOfFile;
			//create a new folder and add it to parent folder
			createFile(currentFolder, nameOfFile);
			break;

		case 5:
			// rename file
			cout << "File: ";
			cin >> nameOfFile;
			for (int i = 0; i < 10; i++)
			{
				if (currentFilesArray[i] != nullptr && currentFilesArray[i]->getFilesName() == nameOfFile) {
					string newName;
					cout << "New name: ";
					cin >> newName;
					currentFilesArray[i]->changeFilesName(newName);
					break;
				}
				else { cout << "Couldn't find file"; break; }
			}
			break;

		case 6:
			// rename folder
			cout << "Folder: ";
			cin >> nameOfFolder;
			for (int i = 0; i < 5; i++)
			{
				if (currentFolderArray[i] != nullptr && currentFolderArray[i]->getFolderName() == nameOfFolder) {
					string newName;
					cout << "New name: ";
					cin >> newName;
					currentFolderArray[i]->changeFolderName(newName);
					break;
				}
				else { cout << "Couldn't find folder"; break; }
			}
			break;

		case 7:
			// Delete folder
			cout << "Folder: ";
			cin >> nameOfFolder;
			for (int i = 0; i < 5; i++) {
				if (currentFolderArray[i] == nullptr || currentFolderArray[i]->getFolderName() != nameOfFolder) {
					continue;
				}
				delete currentFolderArray[i];
				currentFolderArray[i] = nullptr;
				break;
			}
			break;

		case 8:
			//delete file
			cout << "Folder: ";
			cin >> nameOfFile;
			for (int i = 0; i < 5; i++) {
				if (currentFilesArray[i] == nullptr || currentFilesArray[i]->getFilesName() != nameOfFile) {
					continue;
				}
				delete currentFilesArray[i];
				currentFilesArray[i] = nullptr;
				break;
			}
			break;

		case 9:
			// biggest file in this folder
			for (int i = 0; i < 10; i++)
			{
				if (currentFilesArray[i] != nullptr) {
					if (currentFilesArray[i]->getFilesSize() > biggestFile) {
						biggestFile = currentFilesArray[i]->getFilesSize();
					}
				}
			}
			for (int i = 0; i < 10; i++)
			{
				if (currentFilesArray[i] != nullptr){
					if (biggestFile == currentFilesArray[i]->getFilesSize()) {
						currentFilesArray[i]->printFilesInfo();
					}
				}
			}
			break;

		case 10:
			return 0;
		default:
			return 0;
		}
	} while (menuChoice != 10);
}
	
