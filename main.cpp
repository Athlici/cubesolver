#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <stdint.h>

using namespace std;

typedef unsigned int uint;
typedef unsigned char uchar;
typedef uint64_t ulong;

uchar *corners, *edges, *centers, *solution;
const uint cornersize = 48454560;			//Size of the array for cornerdepthlookups in Bytes
const uint edgesize = 44089920;				//same for edges
const uint centersize = 25741485;			//and centers

#include "arrays.cpp"					//file with all the arrays for making the turns
#include "helpers.cpp"					//various helper files for read, write and movemaking
#include "calc.cpp"					//functions for the depth calculations
#include "create.cpp"					//creates the depthlookuptables
#include "solve1.cpp"					//solves a given cube position optimal

int main(int argc, char** argv) {

thread t1(getcenters);					//creation and looding of the tables
thread t2(getedges);
thread t3(getcorners); 

t1.join();
t2.join();
t3.join();


//getcenters();
//getedges();
//getcorners();

// Position einlesen
uchar *position;
position=(uchar*) malloc(55);//solution=(uchar*) malloc(50);
for(uchar i=0;i<7;i++)*(position+i)=3*i;		//just setting a solved edges/corners/centers set
for(uchar i=0;i<24;i++){*(position+i+7)=i;*(position+i+31)=i;}

//{22, 33, 11, 18, 15, 20, 19}
//movecube(position,position,22);
//movecube(position,position,33);
//movecube(position,position,11);
//movecube(position,position,18);
movecube(position,position,15);
movecube(position,position,20);
movecube(position,position,8);
/*
uchar *i;i=position;

  uint address[8]={posedges(*i,*(i+1),*(i+2),*(i+3),*(i+4),*(i+5),*(i+6)),      //calc all the addresses
    poscorners(*(i+7),*(i+8),*(i+9),*(i+10),*(i+11),*(i+12)),
    poscorners(cornerturn[0][*(i+24)],cornerturn[0][*(i+23)],cornerturn[0][*(i+14)],cornerturn[0][*(i+13)],
      cornerturn[0][*(i+21)],cornerturn[0][*(i+22)]),
    poscorners(cornerturn[1][*(i+18)],cornerturn[1][*(i+17)],cornerturn[1][*(i+28)],cornerturn[1][*(i+27)],
      cornerturn[1][*(i+15)],cornerturn[1][*(i+16)]),
    poscorners(cornerturn[2][*(i+25)],cornerturn[2][*(i+26)],cornerturn[2][*(i+30)],cornerturn[2][*(i+29)],
      cornerturn[2][*(i+20)],cornerturn[2][*(i+19)]),
    poscenters(*(i+31),*(i+32),*(i+33),*(i+34),*(i+39),*(i+40),*(i+41),*(i+42)),
    poscenters(centerturn[3][*(i+35)],centerturn[3][*(i+36)],centerturn[3][*(i+37)],centerturn[3][*(i+38)],
      centerturn[3][*(i+43)],centerturn[3][*(i+44)],centerturn[3][*(i+45)],centerturn[3][*(i+46)]),
    poscenters(centerturn[0][*(i+47)],centerturn[0][*(i+48)],centerturn[0][*(i+49)],centerturn[0][*(i+50)],
      centerturn[0][*(i+51)],centerturn[0][*(i+52)],centerturn[0][*(i+53)],centerturn[0][*(i+54)])};

cout << "edgedepth: " << readhalfbyte(*(edges+address[0]/2),address[0]&1)+0 << "; cornerdepths: " << readhalfbyte(*(corners+address[1]/2),address[1]&1)+0 << ";" << readhalfbyte(*(corners+address[2]/2),address[2]&1)+0 << ";" << readhalfbyte(*(corners+address[3]/2),address[3]&1)+0 << ";" << readhalfbyte(*(corners+address[4]/2),address[4]&1)+0 << "; centerdepths: " << readhalfbyte(*(centers+address[5]/2),address[5]&1)+0 << ";" << readhalfbyte(*(centers+address[6]/2),address[6]&1)+0 << ";" << readhalfbyte(*(centers+address[7]/2),address[7]&1)+0 << "\n";
cout << "edgeadress: " << address[0]+0 << "; corneradresss: " << address[1]+0 << ";" << address[2]+0 << ";" << address[3]+0 << ";" << address[4]+0 << "; centeradresss: " << address[5]+0 << ";" << address[6]+0 << ";" << address[7]+0 << "\n";
*/
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

solve(position);

// Position lösen

// Done xD

//  uint foo = 0;						//temporary too make the programm last longer on screen
//  cin >> foo;

}
