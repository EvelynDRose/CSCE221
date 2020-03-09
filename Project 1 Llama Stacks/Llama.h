/*
 * Liquid.h
 *
 *  Created on: Feb 13, 2020
 *      Author: Evelyn Rose
 */

#ifndef _LLAMA_H_
#define _LLAMA_H_

/* File: Llama.h

   This file has the class declaration for the LlamaNode class
   for Project 1. See project description for details.

   You may add public and private data members to the Llama class.

   You may add public and private member functions to the Llama class.

*/


#include <stdexcept>
#include <string>
#include "LlamaNode.h"

using namespace std ;


class LlamaUnderflow : public std::out_of_range {

   public:

   LlamaUnderflow(const string& what) : std::out_of_range(what) { }

} ;


template <class T, int LN_SIZE>
class Llama {

   public:

   Llama()
   {
		LlamaNode<T, LN_SIZE> * newLlama = new LlamaNode<T, LN_SIZE>();//Must always have atleast one node
		top = newLlama;
		current = newLlama;
    	numItems = 0;
   }
   Llama(const Llama<T,LN_SIZE>& other) // copy constructor
   {
	   LlamaNode<T, LN_SIZE> * newLlama = new LlamaNode<T, LN_SIZE>();

	   top = newLlama;
	   current = newLlama;
	   numItems = 0;

	   for(int i = other.numItems-1; i >= 0; i--)
	   {
		   T data = other.peek(i);
		   this->push(data);
	   }
   }   
   ~Llama()
   {
	    while(top)
		{
			current = top->m_next;
			delete top;
			top = current;	
		}
		numItems = 0;
   }



   int size() {return numItems;}
   void dump() ;
   void push(const T& data) ;
   T pop() ;


   void dup() ;    //  (top) A B C D -> A A B C D
   void swap() ;   //  (top) A B C D -> B A C D 
   void rot() ;    //  (top) A B C D -> C A B D


   T peek(int offset) const ;


   // overloaded assignment operator
   //
   const Llama<T,LN_SIZE>& operator=(const Llama<T,LN_SIZE>& rhs)
   {
	   //Clears to prevent memory leaks
	   this->~Llama<T,LN_SIZE>();

	   LlamaNode<T, LN_SIZE> * newLlama = new LlamaNode<T, LN_SIZE>();
	   
	   top = newLlama;
	   current = newLlama;

	   for(int i = rhs.numItems-1; i >= 0; i--)
	   {
		   T data = rhs.peek(i);
		   this->push(data);
	   }

	return * this;
   }


   //
   // Add your public member functions & public data mebers here:
   //


   private:

   LlamaNode<T,LN_SIZE> * top;//Very first node
   LlamaNode<T,LN_SIZE> * current;//Where the top of the stack is located
   int numItems;

   //
   // Add your private member functions & private data mebers here:
   //


} ;


#include "Llama.cpp"


#endif