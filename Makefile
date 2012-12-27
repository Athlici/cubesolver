CXXFLAGS= -Ofast -std=c++0x -pthread

release:
	g++ -Ofast -o cubesolver -std=c++0x -pthread main.cpp
#	$(MAKE) clean
#	$(MAKE) cubesolver

cubesolver: arrays.o calc.o
	g++ $(CXXFLAGS) -o cubesolver main.cpp arrays.o calc.o

clean:
	rm -f *.o cubesolver
