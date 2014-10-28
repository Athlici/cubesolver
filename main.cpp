#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <stdint.h>
#include <string.h>

using namespace std;

typedef struct {
  uint8_t edge[7];
  uint8_t center[24];
  uint8_t corner[24];
} cube ;

uint8_t *table[3];
const uint64_t tablesize[3] = {44089920,25741485,48454560};
const char*    tablepath[3] = {"edges.bin","centers.bin","corners.bin"};
const char*    tablename[3] = {"edge","center","corner"};
uint64_t elemsize [3] = {7,6,8};
const uint8_t  elemsol[3][8]= {{0,1,2,3,4,5,6,0},{0,1,2,3,4,5,0,0},{0,1,2,3,8,9,10,11}};

#include "arrays.cpp"					//file with all the arrays for making the turns
#include "helpers.cpp"					//various helper files for read, write and movemaking
#include "calc.cpp"					//functions for the depth calculations
#include "create.cpp"					//creates the depthlookuptables
//#include "solve1.cpp"					//solves a given cube position optimal

int main(int argc, char** argv) {

//thread t1(getcenters);					//parallel creation and loading of the tables
//thread t2(getedges);
//thread t3(getcorners); 
//
//t1.join();
//t2.join();
//t3.join();


//getcenters();						//sequencial version
//getedges();
//getcorners();

gentable(1);

//{22, 33, 11, 18, 15, 20, 19}
//movecube(position,position,22);
//movecube(position,position,33);
//movecube(position,position,11);
//movecube(position,position,18);
//movecube(position,position,15);
//movecube(position,position,20);
//movecube(position,position,8);
//printcube(position);

printcube(goal());

  uint foo = 0;						//temporary too make the programm last longer on screen
  cin >> foo;

}
