#include "folderclass.h"
#include "filesclass.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

void createFolder(folder* rootFolder, string nameOfFolder) {
	folder* newFolder =  new folder(nameOfFolder);
	rootFolder->addFolder(newFolder);
}
void createFile(bool addToFolder, string nameOfFile) {
	files* newFile = new files(nameOfFile);
	if(addToFolder) {
		//todo: add it to the folder if ya want to
	}
}

int main()
{
	int menuChoice;
	//parent folder to hold them all
	folder parentFolder("parent");
	 
	cout << "(1) Move to folder" << endl
		 << "(2) Create file" << endl
		 << "(3) See map information" << endl
		 << "(4) Rename file" << endl
		 << "(4) Rename folder" << endl
		 << "(5) Biggest file in a folder"<< endl;

	//todo: Add protection against wrong input
	cin >> menuChoice;
	cout << "Current Folder: " + parentFolder.getFolderName();
	parentFolder.getFoldersFromArray();
	//todo: eat a potato
	string nameOfFolder;
	
	switch (menuChoice)
	{
	case 1:
		//create folder
		cout << "Name of folder: ";
		cin >> nameOfFolder;
		//create a new folder and add it to parent folder
		createFolder(&parentFolder,nameOfFolder);
		
		cout << parentFolder.getFolderName();
		
		parentFolder.printFolderInfo();

		
		
		// does it make folder? does it add it to the array? why error on printinfo
		break;
	case 2:
		//create file
		break;
	case 3:
		// see obj  information
		break;
	case 4:
		// rename file
		break;
	case 5:
		// biggest file in folder
		break;
	default:
		break;
	}

}
