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

	string getFileName() {
		return name;
	}
	
	/// <summary>
	/// Gets the size of the file
	/// </summary>
	/// <returns>Filesize as a string</returns>
	string getFilesSize() {
		return size + "mb";
	}

	string getFilesDate() {
		return dOfCreation;
	}

	void changeFileName(string newName) {
		name = newName;
	}

	void printFileInfo() {
		cout << name << endl;
		cout << size << endl;
		cout << dOfCreation << endl;
	}
	 //TODO: fix det her
};
