#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>

using namespace std;

unsigned char *corners, *edges, *centers;
const int cornersize = 48454560;			//Size of the array for cornerdepthlookups in Bytes
const int edgesize = 44089920;				//same for edges
const int centersize = 25741485;			//and centers

#include "arrays.cpp"					//file with all the arrays for making the turns
#include "helpers.cpp"					//various helper files for read, write and movemaking
#include "calc.cpp"					//functions for the depth calculations
#include "create.cpp"					//creates the depthlookuptables
#include "solve.cpp"					//solves a given cube position optimal

int main(int argc, char** argv) {

thread t1(getcenters);					//creation and looding of the tables
thread t2(getedges);
thread t3(getcorners); 

t1.join();
t2.join();
t3.join();

/*
getcenters();
getedges();
getcorners();
*/
// Position einlesen
unsigned char *position;
position=(unsigned char*) malloc(56);
for(int i=0;i<7;i++)*(position+i)=i;
for(int i=0;i<24;i++)*(position+i+7)=i;


// Position lösen

// Done xD

  int foo = 0;						//temporary too make the programm last longer on screen
  cin >> foo;

}
