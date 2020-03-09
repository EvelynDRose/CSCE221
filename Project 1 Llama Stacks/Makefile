all: driver1.o LlamaNode.o Llama.o OvCoInt.o
	g++ -Wall -std=c++11 driver1.o OvCoInt.o -o output.out
	
driver1.o : driver1.cpp 
	g++ -Wall -g -c -std=c++11 driver1.cpp
	
LlamaNode.o : LlamaNode.cpp LlamaNode.h
	g++ -Wall -g -c -std=c++11 LlamaNode.cpp
	
Llama.o : Llama.cpp Llama.h
	g++ -Wall -g -c -std=c++11 Llama.cpp
	
OvCoInt.o : OvCoInt.cpp OvCoInt.h
	g++ -Wall -g -c -std=c++11 OvCoInt.cpp


# -f removes any error messages if the file is not present
clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
run:
	./output.out
