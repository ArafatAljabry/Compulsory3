#pragma once
#include <iostream>
using namespace std;

class files{
private:
	string name;
	int size;
	string dOfCreation;

public:
	void files(string newName) {
		name = newName;
		size = rand() % 101;//generates rand number between 1-100
		dOfCreation = time(0); // current time based on system

	}
	///

	void changeName(newName) {
		name = newName;
	}

};
