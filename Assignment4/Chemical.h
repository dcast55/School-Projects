// Name: Dan Castellucci
// Course: CSC 260 Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment: Assignment 4
// Description: Inputs, stores, and manipulates chemical data from a text file
// Filename: Chemical.h
// Last Modified On: 3/23/13

#include <string>
using namespace std;

class Chemical
{
    
private:
    string name;
    string number;
    string cleanair;
    string classification;
    string metal;
    string metalcategory;
    string carcinogen;
    string formtype;
    string unitmeasure;
    string riskfactor;
    
public:
    Chemical();
    Chemical (string, string, string, string, string, string, string, string, string, string);
    string getName();
    string getNum();
    string getCleanair();
    string getClassification();
    string getMetal();
    string getMetalcategory();
    string getCarcinogen();
    string getFormtype();
    string getUnitmeasure();
    string getRiskfactor();
    string toString();
};



