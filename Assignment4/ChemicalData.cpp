// Name: Dan Castellucci
// Course: CSC 260 Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment: Assignment 4
// Description: Inputs, stores, and manipulates chemical data from a text file
// Filename: ChemicalData.cpp
// Last Modified On: 3/23/13

#include "Chemical.h"
#include "ChemicalData.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int ChemicalData::inputdata(Chemical chemArray[])
{
    string  fileNameIn;
	ifstream inFile;
	bool worked = false;
    int size = 0;
	
    //Asks user to input name of file to read from, open the file. If file fails to open, the user is notified, otherwise the program continues
    do
    {
		cout << "Enter name of file to read from:" << endl;
		cin >> fileNameIn;
		
		inFile.open (fileNameIn.c_str());
        
        if (inFile.fail())
        {
            cerr << "There was an error opening the file. Check the file and try again." << endl;
			inFile.clear();
			inFile.ignore(80, '\n');
			worked = false;
		}
		else
			worked = true;
	} while (!worked);
    
    //Scans in the data from the file
    string line;
    getline(inFile, line); //Ignore first line
    while(getline(inFile, line))
    {
         stringstream linestream(line);
         string c_name, c_number, c_cleanair, c_classification, c_metal, c_metalcategory, c_carcinogen, c_formtype, c_unitmeasure, c_riskfactor;
        
       
        getline(linestream, c_name, ',');
        getline(linestream, c_number, ',');
        getline(linestream, c_cleanair, ',');
        getline(linestream, c_classification, ',');
        getline(linestream, c_metal, ',');
        getline(linestream, c_metalcategory, ',');
        getline(linestream, c_carcinogen, ',');
        getline(linestream, c_formtype, ',');
        getline(linestream, c_unitmeasure, ',');
        getline(linestream, c_riskfactor);
         
         //Creates a temporary Chemical object, and then places that object into the array
         Chemical temp_chem (c_name, c_number, c_cleanair, c_classification, c_metal, c_metalcategory, c_carcinogen, c_formtype, c_unitmeasure, c_riskfactor);
         
         chemArray[size] = temp_chem;
         size++;
     }
    
    inFile.close();
    
    return size;
}

void ChemicalData::outputFile(Chemical chemArray[], int size)
{
    ofstream outFile;
    string fileNameOut;
    bool worked = false;
    
    do
    {
		cout << "Enter name of file to output to:" << endl;
		cin >> fileNameOut;
		
		outFile.open (fileNameOut.c_str());
        
        if (outFile.fail())
        {
            cerr << "There was an error opening the file. Check the file and try again." << endl;
			outFile.clear();
			worked = false;
		}
		else
			worked = true;
	} while (!worked);
    
    outFile<<"Chemical,CAS #/Comp ID,Clean Air Act Chemical,Classification,Metal,Metal Category,Carcinogen,Form Type,Unit of Measure,Risk Factor"<<endl;
    for (int i=0; i<size; i++)
        outFile<<chemArray[i].toString()<<endl;
    
    outFile.close();
    cout<<"Output complete. Exiting program..."<<endl<<endl;
}

void ChemicalData::sortName(Chemical chemArray[], int size)
{
    int i, j;
    Chemical tempchem[1];
    for(j = 1; j < size; j++)
    {
        tempchem[0] = chemArray[j];
        for(i = j - 1; (i >= 0) && (chemArray[i].getName() > tempchem[0].getName()); i--)
        {
            chemArray[i+1] = chemArray[i];
        }
        chemArray[i+1] = tempchem[0];
    }
    
    for (int k=0; k<size; k++)
        cout<<chemArray[k].toString()<<endl;
}

void ChemicalData::sortNum(Chemical chemArray[], int size)
{
    int i, j;
    Chemical tempchem[1];
    for(j = 1; j < size; j++)
    {
        tempchem[0] = chemArray[j];
        for(i = j - 1; (i >= 0) && (chemArray[i].getNum() > tempchem[0].getNum()); i--)
        {
            chemArray[i+1] = chemArray[i];
        }
        chemArray[i+1] = tempchem[0];
    }
    
    for (int k=0; k<size; k++)
        cout<<chemArray[k].toString()<<endl;
}

void ChemicalData::sortCleanAir(Chemical chemArray[], int size)
{
    int i, j;
    Chemical tempchem[1];
    for(j = 1; j < size; j++)
    {
        tempchem[0] = chemArray[j];
        for(i = j - 1; (i >= 0) && (chemArray[i].getCleanair() > tempchem[0].getCleanair()); i--)
        {
            chemArray[i+1] = chemArray[i];
        }
        chemArray[i+1] = tempchem[0];
    }
    
    for (int k=0; k<size; k++)
        cout<<chemArray[k].toString()<<endl;
}

void ChemicalData::sortClassification(Chemical chemArray[], int size)
{
    int i, j;
    Chemical tempchem[1];
    for(j = 1; j < size; j++)
    {
        tempchem[0] = chemArray[j];
        for(i = j - 1; (i >= 0) && (chemArray[i].getClassification() > tempchem[0].getClassification()); i--)
        {
            chemArray[i+1] = chemArray[i];
        }
        chemArray[i+1] = tempchem[0];
    }
    
    for (int k=0; k<size; k++)
        cout<<chemArray[k].toString()<<endl;
}

void ChemicalData::sortMetal(Chemical chemArray[], int size)
{
    int i, j;
    Chemical tempchem[1];
    for(j = 1; j < size; j++)
    {
        tempchem[0] = chemArray[j];
        for(i = j - 1; (i >= 0) && (chemArray[i].getMetal() > tempchem[0].getMetal()); i--)
        {
            chemArray[i+1] = chemArray[i];
        }
        chemArray[i+1] = tempchem[0];
    }
    
    for (int k=0; k<size; k++)
        cout<<chemArray[k].toString()<<endl;
}

void ChemicalData::sortMetalcategory(Chemical chemArray[], int size)
{
    int i, j;
    Chemical tempchem[1];
    for(j = 1; j < size; j++)
    {
        tempchem[0] = chemArray[j];
        for(i = j - 1; (i >= 0) && (chemArray[i].getMetalcategory() > tempchem[0].getMetalcategory()); i--)
        {
            chemArray[i+1] = chemArray[i];
        }
        chemArray[i+1] = tempchem[0];
    }
    
    for (int k=0; k<size; k++)
        cout<<chemArray[k].toString()<<endl;
}

void ChemicalData::sortCarcinogen(Chemical chemArray[], int size)
{
    int i, j;
    Chemical tempchem[1];
    for(j = 1; j < size; j++)
    {
        tempchem[0] = chemArray[j];
        for(i = j - 1; (i >= 0) && (chemArray[i].getCarcinogen() > tempchem[0].getCarcinogen()); i--)
        {
            chemArray[i+1] = chemArray[i];
        }
        chemArray[i+1] = tempchem[0];
    }
    
    for (int k=0; k<size; k++)
        cout<<chemArray[k].toString()<<endl;
}

void ChemicalData::sortFormtype(Chemical chemArray[], int size)
{
    int i, j;
    Chemical tempchem[1];
    for(j = 1; j < size; j++)
    {
        tempchem[0] = chemArray[j];
        for(i = j - 1; (i >= 0) && (chemArray[i].getFormtype() > tempchem[0].getFormtype()); i--)
        {
            chemArray[i+1] = chemArray[i];
        }
        chemArray[i+1] = tempchem[0];
    }
    
    for (int k=0; k<size; k++)
        cout<<chemArray[k].toString()<<endl;
}

void ChemicalData::sortUnitmeasure(Chemical chemArray[], int size)
{
    int i, j;
    Chemical tempchem[1];
    for(j = 1; j < size; j++)
    {
        tempchem[0] = chemArray[j];
        for(i = j - 1; (i >= 0) && (chemArray[i].getUnitmeasure() > tempchem[0].getUnitmeasure()); i--)
        {
            chemArray[i+1] = chemArray[i];
        }
        chemArray[i+1] = tempchem[0];
    }
    
    for (int k=0; k<size; k++)
        cout<<chemArray[k].toString()<<endl;
}

void ChemicalData::sortRiskfactor(Chemical chemArray[], int size)
{
    int i, j;
    Chemical tempchem[1];
    for(j = 1; j < size; j++)
    {
        tempchem[0] = chemArray[j];
        for(i = j - 1; (i >= 0) && (chemArray[i].getRiskfactor() > tempchem[0].getRiskfactor()); i--)
        {
            chemArray[i+1] = chemArray[i];
        }
        chemArray[i+1] = tempchem[0];
    }
    
    for (int k=0; k<size; k++)
        cout<<chemArray[k].toString()<<endl;
}

