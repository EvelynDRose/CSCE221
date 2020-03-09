#/*****************************************
#** File:    Makefile
#** Project: CSCE 221 Project 2
#** Author:  Evelyn ROse
#** Date:    3/6/2020
#** Section: 518
#** E-mail:  kimshi12345@tamu.edu
#**
#**  C++ file:
#**	Do NOT modify this file! 
#**
#**	This is the Proj 3 driver that handles CL args 
#**      and gets the show on the road.
#**
#**     DON'T PANIC! Just let Vogons be Vogons...
#**
#*******************************************/

all: main.o AugmentedBinarySearchTree.o
	g++ -Wall -std=c++11 main.o -o Proj2.out
	
main.o : main.cpp Exceptions.h Proj2Aux.h
	g++ -Wall -g -c -std=c++11 main.cpp
	
AugmentedBinarySearchTree.o : AugmentedBinarySearchTree.cpp AugmentedBinarySearchTree.h
	g++ -Wall -g -c -std=c++11 AugmentedBinarySearchTree.cpp

# -f removes any error messages if the file is not present
clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
run:
	./output.out $(FILE) $(COMMANDS) 2>error.txt
