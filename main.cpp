#include <iostream>             //text in/output
#include <fstream>              //file in/output
#include <cstdlib>
#include <algorithm>            //?swap? and merge
#include <future>               //threads
#include <stdint.h>             //usefull integer names
#include <limits.h>
#include <string.h>
#include <math.h>               //quberoot, redundant now?

//Number of centerpieces to use, 8,12 or 24 considerable memory use implications
#define centercount 12
//Number of cornerpieces to use, 8,9
#define cornercount  8
//Utilise rotation/mirror symmetrie to reduce position count
#define symred 1
//Whether to use additive tables or plain maximum ones
#define addtables 0
//How to compress the tables in memory, 0: nibbles, 1: 2bit + lookup tree, 2: mod 3
#define tablecompression 0
//How to use the disk during table creation, 0: don't, 1: 2bit in memory, 2: memory cached bfs
#define disktablegen 0
//how many threads to use to generate the tables
#define corecount 8

using namespace std;

//the cube structure stores at which position the indexed part is.
typedef struct {
  uint8_t edge[7];
  uint8_t center[24];
  uint8_t corner[24];
} cube ;

#include "tablecount.cpp"
uint8_t* table[3];
const char* tablepath[3] = {"edges.bin","centers.bin","corners.bin"};
const char* tablename[3] = {"edge","center","corner"};

uint8_t solution[36][20];               //TODO: this is most ugly, fix it!

#include "helpers.cpp"					//various helper files for read, write and movemaking
#include "calc.cpp"				    	//un/ranking of the permutations for table lookup
#include "create.cpp"					//creates the various pattern databases
#include "solve.cpp"					//the actual search algorithms to solve a given cube

int main(int argc, char** argv) {

  initsymfuncs();

  for(uint8_t i=0;i<3;i++)                //generate the tables, one after another
    gentable(i);
  
  //the following are example positions for testing purposes
  
  uint8_t n = 15;
  
  //cube Cube=goal();
  //Cube.corner[4]=5;
  //Cube.corner[5]=4;
  
  cube Cube=goal();
  uint8_t moves[15]={29, 3, 33, 21, 10, 34, 1, 35, 11, 25, 16, 5, 35, 16, 0};
  for(uint8_t i=0;i<n;i++) Cube=turncube(Cube,moves[i]);
  //printcube(Cube);
  
  cout << minDepth(goal())+0 << "\n";
  
  cout << minDepth(Cube)+0 << "\n";
  
  for(uint8_t i=minDepth(Cube);i<=n&&(!solvepar(Cube,i));i++)
    cout << "finished depth " << i+0 << "\n";
  for(uint8_t j=0;j<36;j++){
    for(uint8_t i=0;i<n;i++)
      cout << solution[j][i]+0 << ";"; 
    cout << "\n";
  }

/*  //test edge commutativity
for(uint8_t i=0;i<3;i++){
  for(uint8_t j=0;j<3;j++){
    for(uint8_t k=0;k<6;k++){
      uint8_t foo[7]={0,3,6,9,12,15,18};
      uint8_t bar[7]={0,3,6,9,12,15,18};
      turnedges(foo,6*i+j);
      turnedges(bar,6*i+k);
      turnedges(foo,6*i+k);
      turnedges(bar,6*i+j);
      if(posedges(foo)!=posedges(bar)){
        for(uint8_t m=0;m<7;m++)
          cout << foo[m]+0 << ":" << bar[m]+0 << "-";
        cout << "\n" << i+0 << ":" << j+0 << ":" << k+0 << "\n";
      }
    }
  }
}
*/
/*
uint8_t perm[8];
for(uint16_t i=0;i<40320;i++){
  permadr(perm,i,8);
  uint64_t tmp=permpos(perm,8);
  for(uint8_t i=0;i<8;i++)
    if(perm[i]>7)
      cout << "error";
  if(tmp!=i)
    cout << "Mismatch at " << tmp+0 << "," << i+0 << "\n";
}

uint8_t subset[8];
for(uint16_t i=0;i<735471;i++){
  binadr(subset,i,8);
  uint64_t x=binpos(subset,8);
  uint8_t tmp[8];
  for(uint8_t i=0;i<8;i++)
    tmp[i]=subset[i];
  symcorners(tmp,readnibble(cornsymred[i/2],i%2));
  sort(tmp,tmp+8);
  uint64_t y=
  if(x!=i){
    for(uint8_t j=0;j<8;j++)
      cout << subset[j]+0 << ";";
    cout << "\n" << i+0 << ";" << x+0 << "\n";
  }
}
*/
/*
uint8_t foo[7],bar[7];
for(uint64_t x=0;x<tablecount[0];x++){
  adredges(foo,x);
  memcpy(bar,foo,7);
  uint64_t res=posedges(bar);
  if(x!=res){
    cout << "Results at:" << x+0 << ";" << res << "\n";
    for(uint8_t i=0;i<7;i++)
      cout << foo[i]+0 << ";";
    cout << "\n";
  }
}
*/
/*
uint8_t foo[8],bar[8];
for(uint64_t x=0;x<tablecount[2];x++){
  adrcorners(foo,x);
  memcpy(bar,foo,8);
  uint64_t res=poscorners(bar);
  if(x!=res){
    cout << "Results at:" << x+0 << ";" << res << "\n";
    for(uint8_t i=0;i<8;i++)
      cout << foo[i]+0 << ";";
    cout << "\n";
  }
}
*/
/*
uint8_t foo[12],bar[12];
for(uint64_t x=0;x<tablecount[1];x++){
  adrcenters(foo,x);
  memcpy(bar,foo,12);
  uint64_t res=poscenters(bar);
  if(x!=res){
    cout << "Results at:" << x+0 << ";" << res << "\n";
    for(uint8_t i=0;i<12;i++)
      cout << foo[i]+0 << ";";
    cout << "\n";
  }
}
*/
/* Check correctness of this at some point by running the symred on the old tables
uint8_t tmp[4];
for(uint8_t i=0;i<3)
  tmp[i]=
*/
}
