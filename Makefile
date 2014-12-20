CXXFLAGS= -Ofast -funroll-all-loops -std=c++0x -pthread -ggdb

release:
	g++ $(CXXFLAGS) -o cubesolver main.cpp
#	$(MAKE) clean
#	$(MAKE) cubesolver

cubesolver: arrays.o calc.o
	g++ $(CXXFLAGS) -o cubesolver main.cpp arrays.o calc.o

clean:
	rm -f *.o cubesolver
