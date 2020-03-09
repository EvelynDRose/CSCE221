/*****************************************
** File:    AugmentedBinarySearchTree.h
** Project: CSCE 221 Project 2
** Author:  Evelyn Rose
** Date:    3/6/2020
** Section: 518
** E-mail:  kimshi12345@tamu.edu
**
**  C++ file:
**	Breif Description of the file
**
**	
**
*******************************************/



#ifndef AUGMENTED_BINARY_SEARCH_TREE_H
#define AUGMENTED_BINARY_SEARCH_TREE_H


/*---------------Imported Libraries---------------*/
#include <fstream>
#include <sstream>
#include <iostream>       // For NULL
#include <queue>

using namespace std;
/*----------------Includes---------------------*/

#include "Exceptions.h"
//#include "BinarySearchTree.h"
//#include "Proj3Aux.h"

// Binary node and forward declaration because g++ does
// not understand nested classes.
template <class Comparable>
class AugmentedBinarySearchTree;
template <class Comparable>
class BinarySearchTree;

#ifndef BINARY_NODE
#define BINARY_NODE
template <class Comparable>
class BinaryNode
{
	Comparable element;
	BinaryNode *left;
	BinaryNode *right;
	int m_size;

	BinaryNode(const Comparable & theElement = -1, BinaryNode *lt = NULL, BinaryNode *rt = NULL, int size = -1)
		: element(theElement), left(lt), right(rt), m_size(size)  { }
	friend class AugmentedBinarySearchTree<Comparable>;
	friend class BinarySearchTree<Comparable>;

};
#endif // BINARY_NODE

template <class Comparable>
class AugmentedBinarySearchTree
{
public:
	/*------------Constructors/Destructors-------------*/

	AugmentedBinarySearchTree()
	{
		root = NULL;
	}
	AugmentedBinarySearchTree<Comparable>(const AugmentedBinarySearchTree<Comparable> & rhs)
	{
		*this = rhs;
	}
	~AugmentedBinarySearchTree<Comparable>()//DO THIS
	{
		makeEmpty();
	}

	/*--------------Facilitators------------------------*/

	int remove(const Comparable & x);
	bool IsPerfect();
	bool IsComplete();
	void PrintLevels(int numlevels);
	void makeEmpty();

	/*---------------Getters---------------------------*/
	
	int RemoveResidue(); /* Assume RemoveResidue will always be called after Print */
	const Comparable & NthElement(int n) const;
	int Rank(const Comparable & x);
	const Comparable & Median();
	BinaryNode<Comparable> * findMin(BinaryNode<Comparable> *t) const;

	//--------------helper function----------------
	int findHeight();

	
	/*---------------Setters---------------------------*/

	int insert(const Comparable & x);

private:

	int insert(const Comparable & x, BinaryNode<Comparable> * & t) const; // done
	int remove(const Comparable & x, BinaryNode<Comparable> * & t) const; // done
	void PrintLevels(queue <BinaryNode<Comparable> *> q, int levels); // done
	void RemoveResidue(BinaryNode<Comparable> * & t, int *deletions) const;//not started
	BinaryNode<Comparable> * NthElement(BinaryNode<Comparable> *t, int  *nodesVisited, int n) const;//done
	void Rank(const Comparable & x, BinaryNode<Comparable> *t, int *nodesVisited) const; //still working
	bool IsPerfect(queue <BinaryNode<Comparable> *> q, int height);  // done
	void makeEmpty(BinaryNode<Comparable> * & t) const; // done
	bool IsComplete(BinaryNode<Comparable> *t, int index); // still working

	//-------------helper function-------------
	int findHeight(BinaryNode<Comparable> * & t);

	/*------------------Members-----------------------------*/
	//BinarySearchTree<Comparable> m_tree;
	BinaryNode<Comparable> * root;
};

#include "AugmentedBinarySearchTree.cpp"
#endif // AUGMENTED_BINARY_SEARCH_TREE_H 