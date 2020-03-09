all: driver.o
	g++ -Wall driver.o -o output.out

driver.o : driver.cpp Address.h AmazonTruck.h Dimension.h Liquid.h Package.h
	g++ -Wall -c driver.cpp

# -f removes any error messages if the file is not present
clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
run:
	./output.out