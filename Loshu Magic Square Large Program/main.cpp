/****************************************
* Braden Hobby
* Due November 14th
* Large Program 4
* File Name: main.cpp
* Description: This file executes the program using functions
****************************************/

#include "header.h"

//creates a 3 by 3 square from input and checks if it is a magic square
int main() {
	int square[WIDTH][WIDTH]; //creates square and reads input into square
	readSquare(square);
	
	
	if (isMagicSquare(square)) { //checks if the square is wizardry and outputs accordingly
		cout << "The array is a magic square." << endl;
	}
	else {
		cout << "The array is not a magic square." << endl;
	}
	
	printSquare(square); //prints square
	
	


	return 0;
}