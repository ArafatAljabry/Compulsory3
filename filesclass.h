#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

class files{
private:
	string name;
	int size;
	string dOfCreation;	

public:
	files(string newName) {
		srand((unsigned)time(0)); // sets the seed for rand() using time.

		name = newName;
		size = rand() % 100 + 1;//generates rand number between 1-100
		time_t timeNow = time(0);
		dOfCreation = ctime(&timeNow); // current time based on system
	}
	~files() { cout << "File deleted"; }

	///<summary>
	///Gets name of file
	///<summary>
	string getFilesName() {
		return name;
	}
	
	/// <summary>
	/// Gets the size of the file
	/// </summary>
	/// <returns>Filesize as a int</returns>
	int getFilesSize() {
		return size;
	}
	
	/// <summary>
	/// get date and time of creation
	/// </summary>
	string getFilesDate() {
		return dOfCreation;
	}

	/// <summary>
	/// change the name of the file
	/// </summary>
	void changeFilesName(string newName) {
		name = newName;
	}

	/// <summary>
	/// print information saved on object
	/// </summary>
	void printFilesInfo() {
		cout << endl << "Name: " << name << endl;
		cout << "Size: " << size << endl;
		cout << "Created: " << dOfCreation << endl;
	} 
};
