// Name: Dan Castellucci
// Course: CSC 260 Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment: Assignment 4
// Description: Inputs, stores, and manipulates chemical data from a text file
// Filename: Chemical.cpp
// Last Modified On: 3/23/13


#include "Chemical.h"
#include <iostream>
#include <string>

using namespace std;

Chemical::Chemical()
{
    name = " ";
    number = " ";
    cleanair = " ";
    classification = " ";
    metal = " ";
    metalcategory = " ";
    carcinogen = " ";
    formtype = " ";
    unitmeasure = " ";
    riskfactor = " ";
}

Chemical::Chemical (string c_name, string c_number, string c_cleanair, string c_classification, string c_metal, string c_metalcategory, string c_carcinogen, string c_formtype, string c_unitmeasure, string c_riskfactor)
{
    name = c_name;
    number = c_number;
    cleanair= c_cleanair;
    classification = c_classification;
    metal = c_metal;
    metalcategory = c_metalcategory;
    carcinogen = c_carcinogen;
    formtype = c_formtype;
    unitmeasure = c_unitmeasure;
    riskfactor = c_riskfactor;
}

string Chemical::getName()
{
    return name;
}

string Chemical::getNum()
{
    return number;
}

string Chemical::getCleanair()
{
    return cleanair;
}

string Chemical::getClassification()
{
    return classification;
}

string Chemical::getMetal()
{
    return metal;
}

string Chemical::getMetalcategory()
{
    return metalcategory;
}

string Chemical::getCarcinogen()
{
    return carcinogen;
}

string Chemical::getFormtype()
{
    return formtype;
}

string Chemical::getUnitmeasure()
{
    return unitmeasure;
}

string Chemical::getRiskfactor()
{
    return riskfactor;
}

string Chemical::toString()
{
    string s1;
    s1 = name + "," + number + "," + cleanair + "," + classification + "," + metal + "," + metalcategory + "," + carcinogen + "," + formtype + "," + unitmeasure + "," + riskfactor;
    return s1;
}