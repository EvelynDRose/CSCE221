/*
 * Package.h
 *
 *  Created on: Jan 23, 2020
 *      Author: Evelyn Rose
 */

#ifndef PACKAGE_H_
#define PACKAGE_H_

#include <iostream>
#include <string>
using namespace std;

#include "Address.h"
#include "Dimension.h"

class Package {
public:
	Package();
	Package(Address &a, Dimension &d, string id, float weight);
	
	//setters and getters

	const Address& getAddress() const { return address; }
	void setAddress(const Address& address) { this->address = address; }

	const Dimension& getDimension() const { return dimension; }
	void setDimension(const Dimension& dimension) { this->dimension = dimension; }

	const string& getId() const { return ID; }
	void setId(const string& id) { ID = id; }

	float getWeight() const { return weight; }
	void setWeight(float weight) { this->weight = weight; }

	virtual void print(ostream& os)
	{
		os << address;
		os << dimension;
		os << "ID: \t\t" << ID << endl;
		os << "Weight: \t" << weight << endl;
	}

	// overloaded cout
	friend ostream& operator << (ostream& os, Package * source)
	{
		source->print(os);
		return os;
	}

protected:
	string ID;
	float weight;
	Dimension dimension;
	Address address;

};

inline Package::Package() // constructor
{
	ID = "";
	weight = 0.0;
}

inline Package::Package(Address &a, Dimension &d, string id, float weight)
{
	this->address = a;
	this->dimension = d;
	this->ID = id;
	this->weight = weight;
}

#endif /* PACKAGE_H_ */