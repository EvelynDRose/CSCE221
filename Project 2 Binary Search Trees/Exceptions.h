/*****************************************
** File:    Exceptions.h
** Project: Project 2
** Author:  Evelyn Rose
** Date:    3/6/2020/
** Section: 518
** E-mail:  kimshi12345@tamu.edu
**
**  Exceptions to be thrown
**
*******************************************/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <exception>
using namespace std;

class ItemNotFound : public exception {
	public:
	virtual const char* what() const throw() {
		return "ITEM NOT FOUND EXCEPTION:";
	}
};

class NodeNotFound : public exception {
	public:
	virtual const char* what() const throw() {
		return "NODE NOT FOUND EXCEPTION:";
	}
};

class CommandNotFound : public exception {
	public:
	virtual const char* what() const throw() {
		return "INVALID COMMAND EXCEPTION:";
	}
};

class NULLArg : public exception {
	public:
	virtual const char* what() const throw() {
		return "NULL ARGUMENT EXCEPTION:";
	}
};

class EmptyTree : public exception {
	public:
	virtual const char* what() const throw() {
		return "EMPTY TREE EXCEPTION:";
	}
};

#endif