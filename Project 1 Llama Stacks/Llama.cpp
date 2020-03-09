/*
 * Liquid.h
 *
 *  Created on: Feb 13, 2020
 *      Author: Evelyn Rose
 */

#ifndef _LLAMA_CPP_
#define _LLAMA_CPP_

#include "Llama.h"
#include "LlamaNode.h"

//pushes onto the stack
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::push(const T& data)
{
    //If there is a node on top that is empty. If there is the ammount of items/LN_SIZE has a remander greater than half of LN_SIZE and top and current are not the same, then there must be a node on top.
	if(((numItems+1)%LN_SIZE == 1) && (top != current))
	{ 
		current = top;
	}
	//If pushing the data goes over the ammount of avalible spaces in the array
    else if(((numItems+1)%LN_SIZE == 1) && (numItems != 0))//if the num of items/4 has a remainder of 0 and the size is not 0
    {
		//Adding a node if the num of items goes over the LN_SIZE
		LlamaNode<T, LN_SIZE> * newNode = new LlamaNode<T, LN_SIZE>();
		newNode->m_next = top;
		top = newNode;
		current = newNode;
    }
	current->arr[(numItems)%LN_SIZE] = data;
	numItems++;
}

//pops from the top of the stack
template <class T, int LN_SIZE>
T Llama<T, LN_SIZE>::pop()
{
	//If there is nothing in stack
	if(numItems == 0)
		throw LlamaUnderflow("Llama underflow");

	//If the num of items in a node is half, delete the node before unless it is the first node.
	if(((numItems - 1)%LN_SIZE == (LN_SIZE/2)) && (numItems-1 != (LN_SIZE/2)))
	{
		delete top;
		top = current;
	}

	T data = current->arr[(numItems-1)%LN_SIZE];

	//Chages the current node to where the top of the stack is, only if it's not the last item on the stack
	if((numItems - 1)%LN_SIZE == 0 && numItems != 1)
	{
		current = current->m_next;
	}

	numItems--;
	return data;
}

//Prints the entire stack from top to bottom
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::dump()
{
	cout << endl;
	
	cout << "***** Llama Stack Dump ******" << endl;
	cout << "LN_SIZE = " << LN_SIZE << endl;
	cout << "# of items in the stack = " << numItems << endl;
	top->report();

	cout << endl;

	//Check if there is another node
	if(top == current)
	{
		cout << "This stack does not have an extra node." << endl;
	}
	else
	{
		cout << "This stack has an extra node: " << top << endl;
	}

	cout << endl;

	cout << "Stack contents, top to bottom" << endl;
	//---------------------------------
	//Loop through contents of stack
	LlamaNode<T, LN_SIZE> * cursor = current;
	int index = numItems-1;
	while(cursor)
	{
		//loop through stack printing from top to bottom
		cout << "----- " << cursor << " -----" << endl;
		for(int i = 0; i < LN_SIZE; i++)
		{
			cout << cursor->arr[index%LN_SIZE] << endl;
			index--;
			if(index%LN_SIZE == LN_SIZE-1)//if there is extra space in the node
			{
				break;
			}
			if(index < 0)
				break;
				
		}
		cursor = cursor->m_next;
	}
	cout << "----- bottom of stack ---- " << endl;

	cout << endl;

	cout << "*****************************" << endl;

}

// Looks at a specific item in the stack
template <class T, int LN_SIZE>
T Llama<T, LN_SIZE>::peek(int offset) const
{
	LlamaNode<T, LN_SIZE> * cursor = current;
	int index = numItems - 1;
	int target = index - offset;
	while(cursor)
	{
		//loop through stack printing from top to bottom
		for(int i = 0; i < LN_SIZE; i++)
		{
			if(index == target)//If the index is the target
			{
				return cursor->arr[index%LN_SIZE];
			}
			
			index--;
			if(index%LN_SIZE == LN_SIZE-1)//if there is extra space in the node
				break;
		}
		cursor = cursor->m_next;
	}
	if(offset >= numItems)
		throw LlamaUnderflow("Llama Underflow");
	return 0;
}

//Swaps the first and second items on the stack
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::swap()
{
	if(numItems <= 2)
		throw LlamaUnderflow("Llama Underflow");

	T first = this->pop();
	T second = this->pop();

	this->push(first);
	this->push(second);
}

//Places the third item on the top of the stack
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::rot()
{
	if(numItems <= 3)
		throw LlamaUnderflow("Llama Underflow");

	T first = this->pop();
	T second = this->pop();
	T third = this->pop();
	

	this->push(second);
	this->push(first);
	this->push(third);
	
}

#endif