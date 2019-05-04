// Chocolate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//  Mike Haney 02092019
//  O So Tasty Chocolate

ifstream infile; //input file to hold read data
ofstream outfile; //output file to hold write data

const int ROWS = 30, //to hold number of rows
COLS = 2; //to hold number columns

//prototype to zero out the array
void zeroTheArray(int[][COLS]);


/*
Goal is to group items using 2d arrays where the first array is an ID and the 2nd array is a sum of numbers.
For example, with the given inputs
0, 3
20, 44
4, 900
2, 100
4, 144

the outputs would be 
[0][3]
[2][100]
[4][944]
[20][44]

To accomplish, create a 2d array. The first will be the range of the max number of entries, lets' say 35 max entires and the 2nd
will be a single element array that contains our sum. This would look ary[35][1]

Read in a line values from disk, use first number to get index for group, add 2nd number to current value
[firstNum][0] += secondNum 

*/

int main()
{
	infile.open("ChocolatesV2.txt"); //to open the read file
	outfile.open("output.txt"); //to open the write file

	//ensure read file is open and will read data
	if (!infile.is_open())
	{
		cout << "FILE ERROR" << endl;

		return 0;
	}

	int perLine = 0; //to hold number of data printed per line
	int bump = 0; //var to print out specific number of data per line
	int chocData[ROWS][COLS]; //2D array to hold chocolate data

	zeroTheArray(chocData); //to zero the array indexes before placing values into them

	int idNum = 0; //to hold chocolate identification number
	int chocPieces = 0; //to hold number of pieces in the identifications

	while (!infile.eof())
	{
		cout << setw(4);
		infile >> chocData[idNum][chocPieces]; //read in data from file
		cout << chocData[idNum][chocPieces] << " "; //verify data has been read in properly

		if ((bump + 1) % 2 == 0) //to print 2 pieces of data per line
			cout << endl;
		bump++; //to increment the bump
	}

	/* *****While attempting to just print the array here, it prints the last
	piece of data with trailing zero's.
	for(int x = 0; x < ROWS; x++)
		for(int y = 0; y < COLS; y++)
		{
			cout << chocData[idNum++][chocPieces++] << " ";
		} */

		//to close files and flush buffers
	infile.close();
	outfile.close();

	return 0;
}
//function to set indexes to zero before reading data into the 2D
void zeroTheArray(int ary[][COLS])
{
	int rows = 0; //to hold rows
	int cols = 0; //to hold cols
	int iterate = 0; //to increment the cols and rows
	iterate = 1;

	//to zero out rows and cols
	for (rows = 0; rows < ROWS; rows++)
		for (cols = 0; cols < COLS; cols++)
		{
			ary[rows][cols] = 0;
		}

}
