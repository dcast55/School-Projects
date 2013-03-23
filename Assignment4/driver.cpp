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
    
    
    cout<<"Data from the file has been input."<<endl;
    
    bool repeat = true;
    int choice;
    do
    {
        do
        {
            cout<<"What would you like to do now? Enter a number from the following menu:"<<endl;
            cout<<"     1. Sort the data."<<endl;
            cout<<"     2. Output the data to a file and exit the program."<<endl;
            cout<<"     3. Exit the program without outputting the data to a file."<<endl;
            cin>>choice;
            cout<<endl;
        } while( choice != 1 && choice != 2 && choice != 3);
        
        switch (choice)
        {
            case 1:
                cout<<"What criteria would you like to use to sort the data? Select a choice below. Enter anything that's not a choice to return to the main menu."<<endl;
                cout<<"     1. Chemical name"<<endl;
                cout<<"     2. CAS number"<<endl;
                cout<<"     3. Whether it is covered by the Clean Air Act"<<endl;
                cout<<"     4. Classification"<<endl;
                cout<<"     5. Whether it is a metal"<<endl;
                cout<<"     6. What metal category the chemical falls in"<<endl;
                cout<<"     7. Whether the chemical is a carcinogen"<<endl;
                cout<<"     8. Formtype"<<endl;
                cout<<"     9. Unit of Measure"<<endl;
                cout<<"     10. The chemical's risk factor"<<endl;
                cin>>choice;
                cout<<endl;
                switch (choice)
                {
                    case 1:
                        ChemicalData.sortName(chemArray, size);
                        break;
                    case 2:
                        ChemicalData.sortNum(chemArray, size);
                        break;
                    case 3:
                        ChemicalData.sortCleanAir(chemArray, size);
                        break;
                    case 4:
                        ChemicalData.sortClassification(chemArray, size);
                        break;
                    case 5:
                        ChemicalData.sortMetal(chemArray, size);
                        break;
                    case 6:
                        ChemicalData.sortMetalcategory(chemArray, size);
                        break;
                    case 7:
                        ChemicalData.sortCarcinogen(chemArray, size);
                        break;
                    case 8:
                        ChemicalData.sortFormtype(chemArray, size);
                        break;
                    case 9:
                        ChemicalData.sortUnitmeasure(chemArray, size);
                        break;
                    case 10:
                        ChemicalData.sortRiskfactor(chemArray, size);
                        break;
                        
                    default:
                        break;
                }
                break;
            case 2:
                ChemicalData.outputFile(chemArray, size);
                exit(1);
            case 3:
                cout<<"Exiting Program..."<<endl<<endl;
                exit(1);
                
            default:
                break;
        }
        
    } while (repeat);
    
    return 0;
}

