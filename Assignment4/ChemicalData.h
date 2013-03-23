// Name: Dan Castellucci
// Course: CSC 260 Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment: Assignment 4
// Description: Inputs, stores, and manipulates chemical data from a text file
// Filename: ChemicalData.h
// Last Modified On: 3/23/13



const int ARRAY_SIZE = 2000;

class ChemicalData
{
private:
    Chemical chemArray[ARRAY_SIZE];

public:
    int inputdata(Chemical[]);
    void sortName(Chemical[], int);
    void sortNum(Chemical[], int);
    void sortCleanAir(Chemical[], int);
    void sortClassification(Chemical[], int);
    void sortMetal(Chemical[], int);
    void sortMetalcategory(Chemical[], int);
    void sortCarcinogen(Chemical[], int);
    void sortFormtype(Chemical[], int);
    void sortUnitmeasure(Chemical[], int);
    void sortRiskfactor(Chemical[], int);
    
};


