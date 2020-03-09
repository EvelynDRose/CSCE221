/*
 * Dimension.h
 *
 *  Created on: Jan 10, 2020
 *      Author: Prof. Lupoli
 */

#ifndef DIMENSION_H_
#define DIMENSION_H_

class Dimension {
public:
	Dimension();
	Dimension(unsigned short int height, unsigned short int width, unsigned short int depth);
	
	//setters and getters

	unsigned short int getDepth() const { return depth; }
	void setDepth(unsigned short int depth) { this->depth = depth; }

	unsigned short int getHeight() const { return height; }
	void setHeight(unsigned short int height) { this->height = height; }

	unsigned short int getWidth() const { return width; }
	void setWidth(unsigned short int width) { this->width = width; }



	// overloaded cout
	friend ostream& operator<<(ostream& os, const Dimension&source)
	{
		os << "Height: \t" << source.height << endl;
		os << "Width: \t\t" << source.width << endl;
		os << "Depth: \t\t" << source.depth << endl;

		return os;
	}
	// overloaded equals
	const Dimension &operator = (const Dimension &source);
	


private:
	unsigned short int width;
	unsigned short int height;
	unsigned short int depth;

};

inline Dimension::Dimension() { }

inline Dimension::Dimension(unsigned short int h, unsigned short int w, unsigned short int d)
{
	this->width = w;
	this->height = h;
	this->depth = d;
}

inline const Dimension & Dimension::operator = (const Dimension &source)
{
	if(this == &source) // this is a self assignment checker
	{ return *this; }	// returns the pointer to the current object
	// otherwise copy

	//new-instance now = source instance
	this->width = source.width;
	this->height = source.height;
	this->depth = source.depth;

	return *this; // returns previously empty instance
}

#endif /* DIMENSION_H_ */

