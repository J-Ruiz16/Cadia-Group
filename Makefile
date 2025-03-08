CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

all: stacker

stacker: main.o stacker.o
	$(CXX) $(CXXFLAGS) -o stacker main.o stacker.o

main.o: main.cpp stacker.h
	$(CXX) $(CXXFLAGS) -c main.cpp

stacker.o: stacker.cpp stacker.h
	$(CXX) $(CXXFLAGS) -c stacker.cpp

clean:
	rm -f *.o stacker
