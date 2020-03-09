/*
 * AmazonTruck.h
 *
 *  Created on: Jan 23, 2020
 *      Author: Evelyn
 */

#ifndef AMAZONTRUCK_H_
#define AMAZONTRUCK_H_

#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "Package.h"
#include "Liquid.h"

class AmazonTruck {
public:
	AmazonTruck(short v) {volumn = v; }
	~AmazonTruck()
	{ 
		delete truck;
	}

	bool isFull();
	void makeEmpty();
	float totalVolumnSoFar();

	/*
	 * 1. How will you parse the address from the data file to match address, town, etc...?
	 */
	void fillFromFile(string filename);
	void displayLastItenInTruck();



private:

	/*
	 * No other data members are allowed!!!
	 */
	vector <Package> * truck = new vector <Package>;
	short volumn;
	/*
	 * No other data members are allowed!!!
	 */

};

void AmazonTruck::fillFromFile(string filename)
{

	ifstream ifs;
	ifs.open(filename.c_str());

	if (!ifs.is_open()) // catch for is there is no files
    {
        cout << "Unable to open file: " << filename << endl;
        return;
    }
	while (!ifs.eof()) 
    {
		//checks if the truck is full
		if(isFull())
			break;

		string line;
        getline(ifs, line);
        istringstream ss(line);
		if(line == "")
			break;

		//Reading in values from file

		//Address
		string address1;
		getline(ss, address1, ',');
		//City
		string city;
		getline(ss, city, ',');
		//State
		string state;
		getline(ss, state, ',');
		//Zip
		string temp;
		int zip;
		ss >> zip;
		getline(ss, temp, ',');

		//Creating the Address variable
		Address address(address1, city, state, zip);

		//height
		int height;
		ss >> height;
		getline(ss, temp, ',');
		//width
		int width;
		ss >> width;
		getline(ss, temp, ',');
		//depth
		int depth;
		ss >> depth;
		getline(ss, temp, ',');
		//Checking to see if any of the dimensions is < 0, if it is, skip this package.
		if((width < 0) || (height < 0) || (depth < 0))
			continue;

		//Creating the Dimensions variable
		Dimension dim(height, width, depth);


		//ID
		string ID;
		getline(ss, ID, ',');
		//Weight
		float weight;
		ss >> weight;
		getline(ss, temp, ',');
		//Type
		string type;
		getline(ss, type, ',');
		//Flammable
		bool flammable = false;
		getline(ss, temp, ',');
		if(temp == "1")
			flammable = true;

		//Creating Liquid variable
		Liquid liquid(address, dim, ID, weight, type, flammable);
		
		//if the current package is to large for the truck, it breaks the loop.
		if(volumn < (totalVolumnSoFar() + width*height*depth))
			break;

		truck->push_back(liquid);
		
	}
	
	ifs.close();

}

bool AmazonTruck::isFull()
{
	if((this->volumn - totalVolumnSoFar()) <= 0)
		return true;
	return false;
}

void AmazonTruck::makeEmpty()
{
	delete truck;
}

float AmazonTruck::totalVolumnSoFar()
{
	int vol = 0;
	for(unsigned int i = 0; i < truck->size(); i++)
	{
		int height = truck->at(i).getDimension().getHeight();
		int width = truck->at(i).getDimension().getWidth();
		int depth = truck->at(i).getDimension().getDepth();
		vol += height*width*depth;
	}
	return vol;
}

void AmazonTruck::displayLastItenInTruck()
{
	cout << &truck->at(truck->size()-1);
}

#endif /* AMAZONTRUCK_H_ */