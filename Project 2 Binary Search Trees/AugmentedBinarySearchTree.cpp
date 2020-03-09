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

#ifndef AUGMENTEDBINARYSEARCHTREE_CPP
#define AUGMENTEDBINARYSEARCHTREE_CPP

#include "AugmentedBinarySearchTree.h"
#include "Exceptions.h"
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

//----------------Bootstraps------------------
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::insert(const Comparable & x)
{
	return insert(x, this->root);
}
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::remove(const Comparable & x)
{
	remove(x, root);
	if(root->m_size == 0)
		root = NULL;
	return 0;
}

template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::PrintLevels(int numlevels)
{
	queue<BinaryNode<Comparable> *> q;
	PrintLevels(q, numlevels);
}

template <class Comparable>
BinaryNode<Comparable> * AugmentedBinarySearchTree<Comparable>::findMin(BinaryNode<Comparable> * t) const
{
	if(t->left == NULL)
		return t;
	else
		findMin(t->left);
	return NULL;
}

template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::RemoveResidue()
{
	int deletes = 0;
	RemoveResidue(root, &deletes);
	return deletes;
}

template <class Comparable>
const Comparable & AugmentedBinarySearchTree<Comparable>::NthElement(int n) const
{
	if(n <= 0 || n > root->m_size)
	{
		throw ItemNotFound();
	}
		
	int nodesVisited = 0;
	BinaryNode<Comparable> * temp = NthElement(root, & nodesVisited, n);

	return temp->element;
}

template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::Rank(const Comparable & x)
{
	int nodesVisited = 1;
	Rank(x, root, &nodesVisited);

	if(nodesVisited > root->m_size)
	{
		throw NodeNotFound();
	}
	return nodesVisited;
}
template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::IsPerfect()
{
	//This queue is pointless and i refuse to use it.
	queue<BinaryNode<Comparable> *> q;
	return IsPerfect(q, findHeight());
}

template <class Comparable>
const Comparable & AugmentedBinarySearchTree<Comparable>::Median()
{
	if(root == NULL)
		throw NULLArg();
	int median = (root->m_size)/2;

	return NthElement(median);
}

template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::IsComplete()
{
	return IsComplete(root, 0);
}

template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::makeEmpty()
{
	makeEmpty(root);
}

//----------------Helper bootstrap----------------
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::findHeight()
{
	return findHeight(root);
}

//----------------functions------------------
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::insert(const Comparable & x, BinaryNode<Comparable> * & t) const
{
	int counter = 0;
	if (t == NULL) //Base Case
	{
		t = new BinaryNode<Comparable>(x, NULL, NULL, 1);
		counter = 1;
		return counter;
	}
	if (x < t->element) // Move left
	{
		counter = insert(x, t->left);
	}
	else if (t->element < x) //Move right
	{
		counter = insert(x, t->right);
	}
	else if (x == t->element)// Duplicate; 
	{
		counter = 0;
		return counter;
	}
	t->m_size += counter;
	return counter;

}

template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::remove(const Comparable & x, BinaryNode<Comparable> * & t) const
{

	int counter = 0;
	if (t == NULL)
	{
		throw ItemNotFound();
	}
	else if (x < t->element) //Move left
	{
		counter = remove(x, t->left);
	}
	else if (t->element < x) //Move right
	{
		counter = remove(x, t->right);
	}
	else if((t->element == x) && (t->left != NULL && t->right != NULL)) //removing a node with two children
	{
		t->element = findMin(t->right)->element;
		counter = remove(t->element, t->right);
	}
	else if ((t->element == x) && (t->left != NULL || t->right != NULL))//removing a node with one child
	{
		BinaryNode <Comparable> *oldNode = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete oldNode;
		counter = 1;
	}
	else// if the node has no children
	{
		delete t;
		counter = 1;
	}

	t->m_size -= counter;
	return counter;
}

template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::PrintLevels(queue<BinaryNode<Comparable> *> nodes, int levels)
{
	queue<BinaryNode<Comparable> *> parent;
	if(root == NULL)
		throw NodeNotFound();
	nodes.push(root); // push root onto the queue
	BinaryNode<Comparable> * tempRootPar = new BinaryNode<Comparable>();
	parent.push(tempRootPar); // Pushing null to parent since root has no parent 
	for(int i = 0; i < levels; i++) 
	{
		cout << "Level: " << i << endl;
		for(int j = 0; j < pow(2,i); j++)
		{
			//-----------PRINT STATEMENT----------- 
			//(node data, # of nodes in branches, parent node data)
			cout << "(";
			if(nodes.front()->element == -1) // Node data
				cout << "NULL, ";
			else
				cout << nodes.front()->element << ", ";
			if(nodes.front()->m_size == -1) // 3 of branches
				cout << "NULL, ";
			else
				cout << nodes.front()->m_size << ", ";
			if(parent.front()->element == -1) // parent data
				cout << "NULL";
			else
				cout << parent.front()->element;
			cout << ")";

			//-----------PUSH UPDATE-------------
			//Node queue
			
			if(nodes.front()->left == NULL && i != levels-1) // This will add a node to the left if the left node is null and we are not on the last level of print.
			{
				BinaryNode<Comparable> * temp = new BinaryNode<Comparable>();
				nodes.front()->left = temp;
			}
			if(nodes.front()->right == NULL && i != levels-1) // This will add a node to the left if the left node is null and we are not on the last level of print.
			{
				BinaryNode<Comparable> * temp = new BinaryNode<Comparable>();
				nodes.front()->right = temp;
			}

			//---------PUSH AND POP UPDATES--------
			parent.push(nodes.front());
			nodes.push(nodes.front()->left);
			nodes.push(nodes.front()->right);

			
			if(i == 0)//this is a test case if the it is the root node
			{
				parent.pop();
			}
			if(j%2 == 1)//pops parent node every other node
			{
				parent.pop();
			}

			nodes.pop(); //pops node every time

		}
		cout << endl << endl;
	}
}

template <class Comparable>
BinaryNode<Comparable> * AugmentedBinarySearchTree<Comparable>::NthElement(BinaryNode<Comparable> *t, int *nodesVisited, int n) const
{
	if(t == NULL || n == 0) 
		throw ItemNotFound();

	if(*nodesVisited == n)
		return t;

	if(*nodesVisited <= n)
	{
		if(t->left != NULL)
		{
			BinaryNode<Comparable> * left = NthElement(t->left, nodesVisited, n);
			if(left != NULL)
				return left;
		}

		(*nodesVisited) = (*nodesVisited) + 1;

		if(*nodesVisited == n)
			return t;

		if(t->right != NULL)
		{
			BinaryNode<Comparable> * right = NthElement(t->right, nodesVisited, n);
			if(right != NULL)
				return right;
		}
			
	}
	return 0;
}

template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::Rank(const Comparable & x, BinaryNode<Comparable> *t, int *nodesVisited) const
{
	if(root == NULL)
	{
		throw NodeNotFound();
	}

	if(NthElement(*nodesVisited) == x)
		return;

	if(t->left != NULL)
	{
		Rank(x, t->left, nodesVisited);
	}

	(*nodesVisited) = (*nodesVisited) + 1;

	if(NthElement(*nodesVisited-1) != x)
	{
		if(t->right != NULL)
		{
			Rank(x, t->right, nodesVisited);
		}
	}
	else
	{
		(*nodesVisited) = (*nodesVisited) - 1;
	}
}

template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::IsPerfect(queue <BinaryNode<Comparable> *> q, int height) // bassically checks to see if 2^h-1 == tree size. Since a complete bts has 2^h-1 nodes where h is height.
{
	if(root == NULL)
		throw NodeNotFound();
	bool holder = ((pow(2,height)-1) == (root->m_size));
	return holder;
}

template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::makeEmpty(BinaryNode<Comparable> * & t) const
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::RemoveResidue(BinaryNode<Comparable> * & t, int *deletions) const
{
	if(t == NULL)
		return;

	RemoveResidue(t->left, deletions);
	RemoveResidue(t->right, deletions);
	if(t->element == -1)
	{
		delete t;
		t = NULL;
		(*deletions)++;
	}
}


//-----------------Extra Credit-------------
// template <class Comparable> 
// bool AugmentedBinarySearchTree<Comparable>::IsComplete(BinaryNode<Comparable> * t, int n)
// {
// 	if(root == NULL) // returns tree because empty tree is complete tree
// 		return 1;

// 	if(n >= root->m_size)
// 		return 0;
	
// 	return (IsComplete(root->left, 2*n + 1) && IsComplete(root->right, 2*n + 2)); 
// }

//-----------------------Helper---------------------
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::findHeight(BinaryNode<Comparable> * & t)
{
	int maxLeft;
	int maxRight;
	if(t == NULL) // base case
		return 0;
	else
	{
		maxLeft = findHeight(t->left); //max of left branch
		maxRight = findHeight(t->right); //max of right branch

		//finding the max of te two
		if(maxLeft > maxRight)
			return maxLeft + 1;
		else
			return maxRight + 1;
	}
}


#endif