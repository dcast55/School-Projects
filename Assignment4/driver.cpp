// Name: Dan Castellucci
// Course: CSC 260 Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment: Assignment 4
// Description: Inputs, stores, and manipulates chemical data from a text file
// Filename: driver.cpp
// Last Modified On: 3/23/13


#include "Chemical.h"
#include "ChemicalData.h"
#include <iostream>

using namespace std;

int main(void)
{
    Chemical chemArray[ARRAY_SIZE];
    ChemicalData ChemicalData;
    int size = ChemicalData.inputdata(chemArray);   //Inputs data into array and keeps track of the size of the array
    
    
    ChemicalData.sortNum(chemArray, size);
    return 0;
}

