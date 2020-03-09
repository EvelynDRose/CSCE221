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

#ifndef PROJ2AUX_H
#define PROJ2AUX_H

#include <string>
#include <fstream>
#include <sstream>
#include "AugmentedBinarySearchTree.h"
#include "Exceptions.h"



class Proj2Aux
{

	ifstream inFile;
	AugmentedBinarySearchTree<int> m_tree;

	public:
	Proj2Aux()
	{

	}
	~Proj2Aux()
	{

	}

	void DoPrintCommand(string command, int num)
	{
		try
		{
			cout << command << " " << num << ":" << endl;
			cout << endl;
			m_tree.PrintLevels(num);
		}
		catch(NodeNotFound& e)
		{
			cout << "Empty Tree, cannot print";
			cerr << e.what() << " There does not exist an nth element in the BST." << endl;
		}
	}
	int DoRemoveCommand(string command, int num)
	{
		try
		{
			m_tree.remove(num);
			cout << command << " " << num << ": SUCCESS" << endl << endl;
		}
		catch(ItemNotFound& e)
		{
			cout << command << " " << num << ": FAILED" << endl << endl;
		}
		return 0;
	}
	int GetMedianCommand(string command)
	{
		try
		{
			cout << command << ": " << m_tree.Median() << endl;
			cout << endl;
		}
		catch(NULLArg& e)
		{
			cout << command << ": " << -1 << endl << endl;
			cerr << e.what() <<  " No median value for a tree of zero size." << endl;
		}
		
		return 0;
	}
	int GetNthElementCommand(string command, int num)
	{
		try
		{
			cout << command << " " << num << ": " << m_tree.NthElement(num) << endl;
			cout << endl;
		}
		catch(ItemNotFound& e)
		{
			cout << command << " " << num << ": " << -1 << endl << endl;
			cerr << e.what() <<" There does not exist an nth element in the BST." << endl << endl;
		}
		
		return 0;
	}
	int GetRankCommand(string command, int num)
	{
		try
		{
			cout << command << " " << num << ": " << m_tree.Rank(num) << endl;
			cout << endl;
		}
		catch(NodeNotFound& e)
		{
			cout << command << " " << num << ": " << -1 << endl << endl;
			cerr << e.what() <<"  BST does not contain element 10" << num << endl << endl;
		}
		catch(ItemNotFound& e)
		{
			cout << command << " " << num << ": " << -1 << endl << endl;
			cerr << e.what() << " There does not exist an nth element in the BST." << endl << endl;
		}
		
		return 0;
	}
	int GetResidualsCommand(string command)
	{
		try
		{
			cout << command << ": " << m_tree.RemoveResidue() << endl;
			cout << endl;
		}
		catch(NodeNotFound& e)
		{
			cout << "Empty Tree, cannot print";
			cerr << e.what() << " There does not exist an nth element in the BST." << endl;
		}
		
		return 0;
	}
	bool IsComplete(string command);
	bool IsPerfect(string command)
	{
		try
		{
			cout << command << " : ";
			bool test = m_tree.IsPerfect();
			if(test)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
			cout << endl;
		}
		catch(NodeNotFound& e)
		{
			cout << "Empty Tree, cannot print";
			cerr << e.what() << " There does not exist an nth element in the BST." << endl;
		}
		return 0;
	}
	int ReadFromCommandFile(char*);
	int ReadFromInputFile(char*);

};

//-----------------FUNCTIONS------------------
int Proj2Aux::ReadFromCommandFile(char* filename)
{
	ifstream ifs(filename);
	
	//error handeling initializations
	fstream errors;
	errors.open("errors.txt", ios::out);
	streambuf * strBufferCerr = cerr.rdbuf();
	streambuf * strBufferErrFile = errors.rdbuf();
	cerr.rdbuf(strBufferErrFile);


	if (!ifs.is_open()) //Can't open file
    {
        cerr << "Unable to open file: " << filename << endl;
        return -1;
    }

	while (!ifs.eof()) 
    {
		string line;
        getline(ifs, line);//getting the line
		if(line == "") // catches emptry lines
			continue;
		if(line.at(0) == '#') // catches comments
			continue;
		istringstream ss(line); // creating the string stream

		// Reading commands
		string command;
		ss >> command;

		int num;
		if(command == "PRINT")
		{
			ss >> num;
			DoPrintCommand(command, num);
		}
		else if(command == "RESIDUALS")
		{
			GetResidualsCommand(command);
		}
		else if(command == "RANK")
		{
			cerr.rdbuf(strBufferErrFile);
			ss >> num;
			GetRankCommand(command, num);
		}
		else if(command == "NTH")
		{
			cerr.rdbuf(strBufferErrFile);
			ss >> num;
			GetNthElementCommand(command, num);
		}
		else if(command == "MEDIAN")
		{
			GetMedianCommand(command);
		}
		else if(command == "REMOVE")
		{
			ss >> num;
			DoRemoveCommand(command, num);
		}
		else if(command == "PERFECT")
		{
			IsPerfect(command);
		}
		else if(command == "COMPLETE")
		{
			cout << "COMPLETE command has not been implemented." << endl << endl;
		}
		else
		{
			cerr << "Invalid Command Exception: " << command << " is not a valid command" << endl << endl;
		}

	}
	cerr.rdbuf(strBufferCerr);
	errors.close();
	ifs.close();

	return 1;
}

int Proj2Aux::ReadFromInputFile(char* filename)
{
	ifstream ifs(filename);

	if (!ifs.is_open()) //Can't open file
    {
       cout << "Unable to open file: " << filename << endl << endl;
       return -1;
    }
	string line;
    getline(ifs, line);//getting the line
	istringstream ss(line); // creating the string stream

	//Reading in nums and pushing to tree
	int num;
	ss >> num;
	while(!ss.eof())
	{
		m_tree.insert(num);
		ss >> num;
	}
	m_tree.insert(num);
	
	ifs.close();
	return 1;

}


#endif 