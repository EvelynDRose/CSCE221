/**************************************
** File		:	Driver.cpp
** Project	:	CSCE 221 Project 0, Spring 2020
** Author	:	Evelyn Rose
** Date		:	1/23/2020
** Section 	:	518
** Email	:	kimshi12345@tamu.edu
** 
** This file contains the main driver program for Project 0; 
** This program reads from a file a list of packages and puts the packages, in order, on to the truck until it is full.
***************************************/

#include <iostream>
using namespace std;

#include "AmazonTruck.h"
#include "Liquid.h"
#include "Address.h"
#include "Dimension.h"

int main()
{

	/*   All test code */
	Address testAddress("1600 Penn. Ave.", "DC", "DC", 10125);
	Dimension testDimension(12, 6, 12);
	Liquid testLiquid(testAddress, testDimension, "HJGASDHG12765T", 12.3, "cleaner", true);

	AmazonTruck* fromCollegeStation = new AmazonTruck( (short int) 1664);
	fromCollegeStation->fillFromFile("data.txt");

	cout << "********TEST OUTPUTS********" << endl;

	cout << testAddress << endl;
	cout << testDimension << endl;
	cout << &testLiquid << endl;
	
	/********************/

	cout << "********LAST ITEM IN TRUCK********" << endl;

	//Last item in truck
	fromCollegeStation->displayLastItenInTruck();
	
	//Deletes the truck from memory stopping memory leaks
	delete fromCollegeStation;
	
	return 0;
}