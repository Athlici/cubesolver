CXXFLAGS= -Ofast -std=c++0x -ggdb -Wall -fno-strict-aliasing -pthread -funroll-all-loops

release:
	g++ $(CXXFLAGS) -o cubesolver main.cpp
#	$(MAKE) clean
#	$(MAKE) cubesolver

cubesolver: arrays.o calc.o
	g++ $(CXXFLAGS) -o cubesolver main.cpp arrays.o calc.o

clean:
	rm -f *.o cubesolver
