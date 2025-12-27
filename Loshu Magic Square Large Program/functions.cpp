/****************************************
* Braden Hobby
* Due November 14th
* Large Program 4
* File Name: functions.cpp
* Description: This file contains the function definitions.
****************************************/

#include "header.h"


/**
 Inputs values into the square
 @param square[WIDTH][WIDTH] 2D array to fill
 @return nothing (void)
*/
void readSquare(int square[WIDTH][WIDTH]) {
	for (int i = 0; i < WIDTH; i++) { //takes input and puts it into square row by row
		for (int j = 0; j < WIDTH; j++) {
			cin >> square[i][j];
		}
	}
}

/**
* Checks if the square is a magic square
 @param square[WIDTH][WIDTH] 2D array to check
 @return boolean that is true if the square is abracadabra pish posh
*/
bool isMagicSquare(int square[WIDTH][WIDTH]) {
	bool isMagic; //holds boolean return value
	if (!yayRepresentation(square) || !rowColCheck(square) || !diagonalCheck(square)) { //if it passes every test, isMagic is true. Otherwise, it is false
		isMagic = false;
	}
	else {
		isMagic = true;
	}

	return isMagic;
}

/**
 Checks to see if every value of 1-9 is represented
 @param square[WIDTH][WIDTH] 2D array to check
 @return true if the values are represented, false if they are not
*/
bool yayRepresentation(int square[WIDTH][WIDTH]) {
	bool isMagic = true; //holds boolean return value
	int countOne = 0; //counts number of 1s in square
	int countTwo = 0; //counts number of 2s in square
	int countThree = 0; //counts number of 3s in square
	int countFour = 0; //counts number of 4s in square
	int countFive = 0; //counts number of 5s in square
	int countSix = 0; //counts number of 6s in square
	int countSeven = 0; //counts number of 7s in square
	int countEight = 0; //counts number of 8s in square
	int countNine = 0; //counts number of 9s in square
	for (int i = 0; i < WIDTH; i++) { //for loops for indexes of 2D square
		for (int j = 0; j < WIDTH; j++) { //counts up for each number when it appears
			if (square[i][j] == 1) {
				countOne++;
			}
			else if (square[i][j] == 2) {
				countTwo++;
			}
			else if (square[i][j] == 3) {
				countThree++;
			}
			else if (square[i][j] == 4) {
				countFour++;
			}
			else if (square[i][j] == 5) {
				countFive++;
			}
			else if (square[i][j] == 6) {
				countSix++;
			}
			else if (square[i][j] == 7) {
				countSeven++;
			}
			else if (square[i][j] == 8) {
				countEight++;
			}
			else if (square[i][j] == 9) {
				countNine++;
			}
		}
	}
	if (countOne != 1 || countTwo != 1 || countThree != 1 || countFour != 1 || countFive != 1 || countSix != 1 || countSeven != 1 || countEight != 1 || countNine != 1) { //checks to make sure numbers 1-9 are represented exactly once
		isMagic = false;
	}
	return isMagic;
}

/**
 Checks if square has rows and columns that each add up to constant SUM
 @param square[WIDTH][WIDTH] 2D array to check
 @return true if the rows and columns add up to SUM
*/
bool rowColCheck(int square[WIDTH][WIDTH]) {
	bool isMagic = true; //holds boolean return value
	int rowSum = 0; //holds temporary sum of a row
	int columnSum = 0; //holds temporary sum of a column
	for (int i = 0; i < WIDTH; i++) { //for index of 2D square
		for (int j = 0; j < WIDTH; j++) {
			rowSum += square[i][j]; //adds up the row
			columnSum += square[j][i]; //adds up the column
		}
		if (rowSum == SUM && columnSum == SUM) { //if the sum of the row and column equal SUM, move on to the next row and column
			rowSum = 0;
			columnSum = 0;
		}
		else { //if one sum is wong, isMagic is false. Does not matter if future sums are correct, so no reset
			isMagic = false;
		}
	}
	return isMagic;
}

/**
 Checks if the square's diagonals add up to SUM
 @param square[WIDTH][WIDTH] 2D array to check
 @return true if the diagonals add up to SUM, false if not
*/
bool diagonalCheck(int square[WIDTH][WIDTH]) { //a pain
	int diagonalSum = 0; //holds temporary sum of a diagonal
	bool isMagic = true; //holds boolean return value
	for (int i = 0; i < WIDTH; i++) { //finds diagonal sum of top left to bottom right
		diagonalSum += square[i][i];
	}
	if (diagonalSum != SUM) { //checks if the sum is right
		isMagic = false;
	}
	diagonalSum = 0;
	for (int i = WIDTH - 1; i >= 0; i--) { //finds diagonal sum of bottom right to top left
		diagonalSum += square[i][WIDTH - 1 - i];
	}
	if (diagonalSum != SUM) { //if sum is wrong, set isMagic to false
		isMagic = false;
	}
	return isMagic;
}

/**
 Prints square
 @return nothing (void)
*/
void printSquare(int square[WIDTH][WIDTH]) {
	for (int i = 0; i < WIDTH; i++) { //outputs what we have stored in the square in a nice, organized way
		cout << "      ";
		for (int j = 0; j < WIDTH; j++) {
			cout << fixed << setw(5) << square[i][j];
		}
		cout << endl;
	}
}