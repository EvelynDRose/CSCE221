/*
 * Liquid.h
 *
 *  Created on: Jan 23, 2020
 *      Author: Evelyn Rose
 */

#ifndef LIQUID_H_
#define LIQUID_H_

#include <iostream>
#include <string>
using namespace std;

#include "Package.h"


class Liquid : public Package {
public:
	Liquid();

	// called a parameterized constructor
	Liquid(Address a, Dimension d, string id, float weight, string type, bool f) : Package(a, d, id, weight)
	{
		this->liquidType = type;
		this->flammable = f;
	}

	//getters and setters
	bool isFlammable() const { return flammable; }
	void setFlammable(bool flammable) { this->flammable = flammable; }

	const string& getLiquidType() const { return liquidType; }
	void setLiquidType(const string& liquidType) { this->liquidType = liquidType; }

	void print(ostream& os)
	{
		os << address;
		os << dimension;
			os << "ID: \t\t" << ID << endl;
		os << "Weight: \t" << weight << endl;
		os << "Type: \t\t" << liquidType << endl;
		if(flammable == 1)
			os << "Flammable:\t Yes" << endl;
		else
			os << "Flammable:\t No" << endl;
	}


	// data members
private:
	string liquidType;
	bool flammable;
};




#endif /* LIQUID_H_ */