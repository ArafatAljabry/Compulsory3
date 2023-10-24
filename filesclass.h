#pragma once
#include <iostream>
using namespace std;

class files{
private:
	string name;
	int size;
	string dOfCreation;

public:
	files(string newName) {
		srand(time(0)); // sets the seed for rand() using time.

		name = newName;
		size = rand() % 100 + 1;//generates rand number between 1-100
		dOfCreation = time(0); // current time based on system

	}

	/// <summary>
	/// Get the name of the file
	/// </summary>
	/// <returns></returns>
	string getFileName();

	/// <summary>
	/// Get the size of the file
	/// </summary>
	/// <returns></returns>
	string getFilesSize();


	string getFilesDate();

	/// <summary>
	/// changes name of a given folder
	/// </summary>
	/// <param name="newName"></param>
	void changeFileName(string newName);

	/// <summary>
	/// prints file information
	/// </summary>
	void printFileInfo();

};
