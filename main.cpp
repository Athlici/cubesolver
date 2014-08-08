#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <stdint.h>

using namespace std;

typedef unsigned int uint;
typedef unsigned char uchar;
typedef uint64_t ulong;

uchar *corners[32], *edges, *centers, *solution;
const ulong cornersize = 14827095360;			//Size of the array for cornerdepthlookups in Bytes
const uint edgesize    = 44089920;				//same for edges
const uint centersize  = 25741485;			//and centers

#include "arrays.cpp"					//file with all the arrays for making the turns
#include "helpers.cpp"					//various helper files for read, write and movemaking
#include "calc.cpp"					//functions for the depth calculations
#include "create.cpp"					//creates the depthlookuptables
//#include "solve1.cpp"					//solves a given cube position optimal

int main(int argc, char** argv) {

//thread t1(getcenters);					//creation and looding of the tables
//thread t2(getedges);
thread t3(getcorners); 

//t1.join();
//t2.join();
t3.join();


//getcenters();
//getedges();
//getcorners();

// Position einlesen
//uchar *position;
//position=(uchar*) malloc(55);//solution=(uchar*) malloc(50);
//for(uchar i=0;i<7;i++)*(position+i)=3*i;		//just setting a solved edges/corners/centers set
//for(uchar i=0;i<24;i++){*(position+i+7)=i;*(position+i+31)=i;}

//{22, 33, 11, 18, 15, 20, 19}
//movecube(position,position,22);
//movecube(position,position,33);
//movecube(position,position,11);
//movecube(position,position,18);
//movecube(position,position,15);
//movecube(position,position,20);
//movecube(position,position,8);
//printcube(position);

//uchar *result; result=(uchar*) malloc(55);

//for(uchar i=0;i<23;i++){
//  movecube(position,result,i);
//  printcube(result);
//}

//{{0,1,2,3,4,5},{17,16,7,6,14,15},{11,10,21,20,8,9},{18,19,23,22,13,12}}
//{{7,8,9,10,11,12},{24,23,14,13,21,22},{18,17,28,27,15,16},{25,26,30,29,20,19}}

/*
uchar searchspace=0;
while(!solve(position,searchspace))			//Add in threads here to account for cubeturns.(better way???)
{cout << "finished search at Depth: " << searchspace+0 << "\n";searchspace++;}

cout << "solution found with " << searchspace+0 << " moves.\n" ;
for(uint j=0;j<searchspace;j++) cout << *(solution+j)+0 << ";" ;
cout << "\n";
*/

//solve(position);

// Position lösen

// Done xD

//  uint foo = 0;						//temporary too make the programm last longer on screen
//  cin >> foo;

}
