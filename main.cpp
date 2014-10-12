#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <stdint.h>

using namespace std;

typedef struct cube {
  uint8_t edge[8];
  uint8_t center[24];
  uint8_t corner[24];
};
/*
uint8_t *corners, *edges, *centers, *solution;
const uint64_t edgesize   = 44089920;                   //Size of the array for cornerdepthlookups in Bytes
const uint64_t centersize = 25741485;
const uint64_t cornersize = 48454560;                   //maybe ifdev for different versions
*/

uint8_t *table[3];
uint64_t tablesize[3] = {44089920,25741485,48454560};
string   tablepath[3] = {"edges.bin","centers.bin","corners.bin"};
string   tablename[3] = {"edge","center","corner"};

#include "arrays.cpp"					//file with all the arrays for making the turns
#include "helpers.cpp"					//various helper files for read, write and movemaking
#include "calc.cpp"					//functions for the depth calculations
#include "create.cpp"					//creates the depthlookuptables
#include "solve1.cpp"					//solves a given cube position optimal

int main(int argc, char** argv) {

thread t1(getcenters);					//parallel creation and loading of the tables
thread t2(getedges);
thread t3(getcorners); 

t1.join();
t2.join();
t3.join();


//getcenters();						//sequencial version
//getedges();
//getcorners();

//{22, 33, 11, 18, 15, 20, 19}
//movecube(position,position,22);
//movecube(position,position,33);
//movecube(position,position,11);
//movecube(position,position,18);
//movecube(position,position,15);
//movecube(position,position,20);
//movecube(position,position,8);
//printcube(position);

  uint foo = 0;						//temporary too make the programm last longer on screen
  cin >> foo;

}
