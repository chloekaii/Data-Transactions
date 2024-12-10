CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

all: main

main: main.o InMemoryDB.o
	$(CXX) -o main main.o InMemoryDB.o

main.o: main.cpp InMemoryDB.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

InMemoryDB.o: InMemoryDB.cpp InMemoryDB.h
	$(CXX) $(CXXFLAGS) -c InMemoryDB.cpp -o InMemoryDB.o

clean:
	rm -f main main.o InMemoryDB.o
