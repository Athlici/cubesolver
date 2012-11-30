#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

unsigned char *corners, *edges, *centers;
const int cornersize = 48454560;			//Size of the array for cornerdepthlookups in Bytes
const int edgesize = 44089920;				//same for edges
const int centersize = 25741485;			//and centers

#include "arrays.cpp"					//file with all the arrays for making the turns
#include "helpers.cpp"					//various helper files for read, write, turnmaking and depthcalculations
#include "create.cpp"					//creates the depthlookuptables
#include "solve.cpp"					//solves a given cube position optimal

int main(int argc, char** argv) {
 getcenters();					//creation and looding of the tables
 getedges();
 getcorners(); 

// Position einlesen

// Position lösen

// Done xD

  int foo = 0;						//temporary too make the programm last longer on screen
  cin >> foo;

}
