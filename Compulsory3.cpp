#include <iostream>
#include "folderclass.h"
#include "filesclass.h"

//Notes:
//  Goal:
//  classes: folder and file
// Both: name, size and date of creation, creation of new folder and file; rand size up to 100,name, size and date(function)
//       change name(function) print all info(with folder include files within)
// Folder: array of maximum 10 files and array of maximum 5 folders
// Main:
//      create Files and folder, look through file in folder(print the info)


int main()
{
    std::cout << "Hello World!\n";
}


//Defining functions for folders class
string folder::getFolderName() {
    return name;
}

string folder::getFolderSize() {
	return size + "mb";
}

string folder::getFolderDate() {
	return dOfCreation;
}
void folder::changeFolderName(string newName) {
	name = newName;
}
void folder::addFolder(folder* newFolder) {
	for (int i = 0; i < 5; i++) {
		if (folderArray[i] == 0)
		{
			folderArray[i] = newFolder;
		}
	}
}

void folder::changeFolderArray(string oldFolder, folder* newFolder) {
	for (int i = 0; i < 5; i++)
	{
		if (folderArray[i]->name == oldFolder) {
			folderArray[i] = newFolder;
		}
	}
}

void folder::addFile(folder* newFile) {
	for (int i = 0; i < 10; i++)
	{
		if (filesArray[i] == 0) {
			folderArray[i] = newFile;
		}
	}
}

void folder::changeFileArray(string oldFile, files* newFile) {
	for (int i = 0; i < 10; i++)
	{
		if (filesArray[i]->getFileName() == oldFile) {
			filesArray[i] == newFile;
		}
	}
}

// Defining functions for files class
string files::getFileName() {
	return name;
}

string files::getFilesSize() {
	return size + "mb";
}

string files::getFilesDate() {
	return dOfCreation;
}
void files::changeFileName(string newName) {
	name = newName;
}

void files::printFileInfo() {
	cout << name << endl;
	cout << size << endl;
	cout << dOfCreation << endl;
}
