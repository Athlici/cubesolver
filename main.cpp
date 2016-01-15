#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <future>
#include <algorithm>
#include <stdint.h>
#include <string.h>
#include <math.h>

using namespace std;

typedef struct {
  uint8_t edge[7];
  uint8_t center[24];
  uint8_t corner[24];
} cube ;

uint8_t *table[3];
const uint64_t tablesize[3] = {44089920,23424751350,/*14827095360*/7413547680};
const char*    tablepath[3] = {"edges.bin","centers.bin","corners.bin"};
const char*    tablename[3] = {"edge","center","corner"};
const uint8_t  elemsize [3] = {7,12,8};
const uint8_t  elemsol[3][12]= {{0,3,6,9,12,15,18,0,0,0,0,0},{0,1,2,3,4,5,6,7,8,9,10,11},{0,1,5,4,8,9,10,11,0,0,0,0}};
const uint8_t  corecount    = 4;
const uint8_t  maxdepth     = 17;

uint8_t solution[36][20];

#include "arrays.cpp"					//file with all the arrays for making the turns
#include "helpers.cpp"					//various helper files for read, write and movemaking
#include "ifshit.cpp"                                   //long nested ifs for centerpos
#include "calc.cpp"					//functions for the depth calculations
#include "create.cpp"					//creates the depthlookuptables
#include "solve.cpp"					//solves a given cube position optimal

int main(int argc, char** argv) {

//base action on hash of binary file?
//implement things with map over uint64_t
//merge all cubesolvers into one, switch based on #define or global vars

//thread t1(gentable,0);					//parallel creation and loading of the tables
//thread t2(gentable,1);
//thread t3(gentable,2); 
//t1.join();
//t2.join();
//t3.join();

//gentable(0);
gentable(1);
//gentable(2);

//cube Cube=goal();						//examples for testing
//Cube.corner[4]=5;						//corner flip parity
//Cube.corner[5]=4;

//uint8_t moves[17]={29, 3, 33, 21, 10, 34, 1, 35, 11, 25, 16, 5, 35, 16, 0, 19, 3};  //random position
//for(uint8_t i=0;i<maxdepth;i++) Cube=movecube(Cube,moves[i]);
//printcube(Cube);

//cout << minDepth(Cube)+0 << "\n";

//for(uint8_t i=minDepth(Cube);i<=maxdepth&&(!solvepar(Cube,i));i++)
//  cout << "finished depth " << i+0 << "\n";
//solve(Cube,7);

}
