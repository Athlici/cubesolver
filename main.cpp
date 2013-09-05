#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>

using namespace std;

unsigned char *corners, *edges, *centers, *solution;
const int cornersize = 48454560;			//Size of the array for cornerdepthlookups in Bytes
const int edgesize = 44089920;				//same for edges
const int centersize = 25741485;			//and centers

#include "arrays.cpp"					//file with all the arrays for making the turns
#include "helpers.cpp"					//various helper files for read, write and movemaking
#include "calc.cpp"					//functions for the depth calculations
#include "create.cpp"					//creates the depthlookuptables
#include "solve2.cpp"					//solves a given cube position optimal

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
position=(unsigned char*) malloc(55);solution=(unsigned char*) malloc(50);
for(unsigned char i=0;i<7;i++)*(position+i)=i;		//just setting a solved edges/corners/centers set
for(unsigned char i=0;i<24;i++){*(position+i+7)=i;*(position+i+31)=i;}

//{22, 33, 11, 18, 15, 20, 19}
movecube(position,position,22);
movecube(position,position,33);
movecube(position,position,11);
movecube(position,position,18);
movecube(position,position,15);
movecube(position,position,20);
movecube(position,position,8);

unsigned char searchspace=0;
while(!solve(position,searchspace))			//Add in threads here to account for cubeturns.(better way???)
{cout << "finished search at Depth: " << searchspace+0 << "\n";searchspace++;}

cout<< "solution found with " << searchspace+0 << " moves.\n" ;

// Position lösen

// Done xD

//  int foo = 0;						//temporary too make the programm last longer on screen
//  cin >> foo;

}
