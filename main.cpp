#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <algorithm>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define centercount 12
#define cornercount  8
#define splitcomp    1
#define disktablegen 1

using namespace std;

typedef struct {
  uint8_t edge[7];
  uint8_t center[24];
  uint8_t corner[24];
} cube ;

uint8_t *table[3];
const uint64_t tablesize[3] = {44089920,
#if centercount==8
25741485,
#else
46849502700,
#endif
#if cornercount==6
48454560,
#else
14827095360,
#endif
};

#if splitcomp
uint8_t *cotab[3];
const uint64_t cotabsize[3] = {13,108089320,34977176};
#endif

const char* tablepath[3] = {"edges.bin","centers.bin","corners.bin"};
const char* tablename[3] = {"edge","center","corner"};
//const uint8_t  elemsize [3] = {7,8,6};
//const uint8_t  elemsol[3][8]= {{0,3,6,9,12,15,18,0},{0,1,2,3,8,9,10,11},{0,1,2,3,4,5,0,0}};

uint8_t solution[20];                   //Add more bytes once those length become feasible

#include "arrays.cpp"					//file with all the arrays for making the turns
#include "helpers.cpp"					//various helper files for read, write and movemaking
#include "ifshit.cpp"
#include "calc.cpp"				    	//functions for the depth calculations
#include "create.cpp"					//creates the depthlookuptables
#include "solve.cpp"					//solves a given cube position optimal

int main(int argc, char** argv) {

//thread t1(gentable[0]);					//parallel creation and loading of the tables
//thread t2(gentable[1]);
//thread t3(gentable[2]); 
//t1.join();
//t2.join();
//t3.join();

//gentable(0);
gentable(1);
gentable(2);

//uint8_t n = 12;

//cube Cube=goal();
//Cube.corner[4]=5;
//Cube.corner[5]=4;
/*
cube Cube=goal();
uint8_t moves[15]={29, 3, 33, 21, 10, 34, 1, 35, 11, 25, 16, 5, 35, 16, 0};
for(uint8_t i=0;i<n;i++) Cube=movecube(Cube,moves[i]);
//printcube(Cube);
*/

uint64_t depthcount[3][12]={{0}};
for(uint8_t k=1;k<3;k++){
  for(uint64_t i=0;i<2*tablesize[k];i++){
    uint8_t tmp = read2bit(table[k][i/4],i%4) + 7;
    if(tmp==7)
      tmp = colookup(k,i);
    depthcount[k][tmp]++;
  }
  for(uint8_t i=0;i<12;i++)
    cout << "positions in depth " << i+0 << ":" << depthcount[k][i] << "\n";
}

/*
for(uint64_t i=0;i<cotabsize[0];i++)
  cout << nextfree(0,i)+0 << "\n";
*/
/*
for(uint64_t i=0;i<cotabsize[1];i++){
  if(cotab[1][5*i+4]==0)
    cout << i+0 << ",";
}
*/
/*
uint64_t old=nextfree(1,0);
for(uint64_t i=1;i<cotabsize[1];i++){
  uint64_t tmp=nextfree(1,i);
  if(tmp==old)
    cout << i+0 << ":" << tmp+0 << "\n";
  old=tmp;
}
*/
/*
cout << minDepth(Cube)+0 << "\n";

for(uint8_t i=minDepth(Cube);i<=n&&(!solve(Cube,i));i++)
  cout << "finished depth " << i+0 << "\n";
for(uint8_t i=0;i<n;i++)cout << solution[i]+0 << ";"; cout << "\n";
*/
}
