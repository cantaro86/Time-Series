PROGRAM_NAME=main
OBJECTS=main.o TimeSeries.o       

CXX=g++


CXXFLAGS += -Wall -Werror -std=c++17
LIBS=-lm                  




$(PROGRAM_NAME):$(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_NAME) $(OBJECTS) $(LIBS)

	@echo " "
	@echo "Compilation completed!"
	@echo " "



main.o:TimeSeries.hpp main.cpp  
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp


TimeSeries.o:TimeSeries.hpp 
	$(CXX) $(CXXFLAGS) -c -o TimeSeries.o TimeSeries.cpp



clean:
	rm -f *.o
	rm -f *~
	rm -f core


cat: 
	cat Makefile


all:	$(PROGRAM_NAME) clean
