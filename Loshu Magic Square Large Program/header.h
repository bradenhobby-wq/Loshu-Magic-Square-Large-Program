/****************************************
* Braden Hobby
* Due November 14th
* Large Program 4
* File Name: header.h
* Description: This file contains the include statements, constants, and function declarations
****************************************/

#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int SUM = 15; //what the rows, columns, and diagonals should add to
const int WIDTH = 3; //width of square

void readSquare(int square[WIDTH][WIDTH]);
bool isMagicSquare(int square[WIDTH][WIDTH]);
bool yayRepresentation(int square[WIDTH][WIDTH]);
bool rowColCheck(int square[WIDTH][WIDTH]);
bool diagonalCheck(int square[WIDTH][WIDTH]);
void printSquare(int square[WIDTH][WIDTH]);