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

int main()
{
    infile.open("ChocolatesV2.txt"); //to open the read file
    outfile.open("output.txt"); //to open the write file

    //ensure read file is open and will read data
    if(!infile.is_open())
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

    while(!infile.eof())
    {
        cout << setw(4);
        infile >> chocData[idNum][chocPieces]; //read in data from file
        cout << chocData[idNum][chocPieces] << " "; //verify data has been read in properly

        if((bump + 1) % 2 == 0) //to print 2 pieces of data per line
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
    for(rows = 0; rows < ROWS; rows++)
        for(cols = 0; cols < COLS; cols++)
        {
            ary[rows][cols] = 0;
        }

}
