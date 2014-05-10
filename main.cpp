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
/*
thread t1(getcenters);					//creation and looding of the tables
thread t2(getedges);
thread t3(getcorners); 

t1.join();
t2.join();
t3.join();
*/

getcenters();
//getedges();
//getcorners();

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

unsigned char *i;i=position;
/*int address[8]={posedges(*i,*(i+1),*(i+2),*(i+3),*(i+4),*(i+5),*(i+6)),       //calc all the addresses
  poscorners(*(i+7),*(i+8),*(i+9),*(i+10),*(i+11),*(i+12)),
  poscorners(cornerturn[*(i+13)][2],cornerturn[*(i+14)][2],cornerturn[*(i+15)][2],cornerturn[*(i+16)][2],
    cornerturn[*(i+17)][2],cornerturn[*(i+18)][2]),
  poscorners(cornerturn[*(i+19)][1],cornerturn[*(i+20)][1],cornerturn[*(i+21)][1],cornerturn[*(i+22)][1],
    cornerturn[*(i+23)][1],cornerturn[*(i+24)][1]),
  poscorners(cornerturn[*(i+25)][0],cornerturn[*(i+26)][0],cornerturn[*(i+27)][0],cornerturn[*(i+28)][0],
    cornerturn[*(i+29)][0],cornerturn[*(i+30)][0]),
  poscenters(*(i+31),*(i+32),*(i+33),*(i+34),*(i+39),*(i+40),*(i+41),*(i+42)),
  poscenters(centerturn[*(i+35)][3],centerturn[*(i+36)][3],centerturn[*(i+37)][3],centerturn[*(i+38)][3],
    centerturn[*(i+43)][3],centerturn[*(i+44)][3],centerturn[*(i+45)][3],centerturn[*(i+46)][3]),
  poscenters(centerturn[*(i+47)][0],centerturn[*(i+48)][0],centerturn[*(i+49)][0],centerturn[*(i+50)][0],
    centerturn[*(i+51)][0],centerturn[*(i+52)][0],centerturn[*(i+53)][0],centerturn[*(i+54)][0])};
*/


int address[3]={poscenters(*(i+31),*(i+32),*(i+33),*(i+34),*(i+39),*(i+40),*(i+41),*(i+42)),
  poscenters(centerturn[*(i+35)][3],centerturn[*(i+36)][3],centerturn[*(i+37)][3],centerturn[*(i+38)][3],
    centerturn[*(i+43)][3],centerturn[*(i+44)][3],centerturn[*(i+45)][3],centerturn[*(i+46)][3]),
  poscenters(centerturn[*(i+47)][0],centerturn[*(i+48)][0],centerturn[*(i+49)][0],centerturn[*(i+50)][0],
    centerturn[*(i+51)][0],centerturn[*(i+52)][0],centerturn[*(i+53)][0],centerturn[*(i+54)][0])};

cout << "centeradresses: " << address[0]+0 << ";" << address[1]+0 << ";" << address[2]+0 << "\n";
cout << "centerdepths: " << readhalfbyte(*(centers+address[0]/2),address[0]%2)+0 << ";" << readhalfbyte(*(centers+address[1]/2),address[1]%2)+0 
	<< ";" << readhalfbyte(*(centers+address[3]/2),address[3]%2)+0 << "\n";


/*
cout << "edgedepth: " << readhalfbyte(*(edges+address[0]/2),address[0]&1)+0 << "; cornerdepths: " << readhalfbyte(*(corners+address[1]/2),address[1]&1)+0 << ";" << readhalfbyte(*(corners+address[2]/2),address[2]&1)+0 << ";" << readhalfbyte(*(corners+address[3]/2),address[3]&1)+0 << ";" << readhalfbyte(*(corners+address[4]/2),address[4]&1)+0 << "; centerdepths: " << readhalfbyte(*(centers+address[5]/2),address[5]&1)+0 << ";" << readhalfbyte(*(centers+address[6]/2),address[6]&1)+0 << ";" << readhalfbyte(*(centers+address[7]/2),address[7]&1)+0 << "\n";
cout << "edgedepth: " << address[0]+0 << "; cornerdepths: " << address[1]+0 << ";" << address[2]+0 << ";" << address[3]+0 << ";" << address[4]+0 << "; centerdepths: " << address[5]+0 << ";" << address[6]+0 << ";" << address[7]+0 << "\n";
*/

/*
  centers = (unsigned char*) malloc(centersize);                        //allocate the memory for the array
  for(int i=0;i<centersize;i++) *(centers+i) = 255;                     //everything else is set to max depth
*(centers+3025/2)=sethalfbyte(255,0,3025%2);
*/
/*
int address=poscenters(*(i+31),*(i+32),*(i+33),*(i+34),*(i+39),*(i+40),*(i+41),*(i+42));
cout << readhalfbyte(*(centers+address/2),address%2)+0 << "\n";
*/
/*
unsigned char searchspace=0;
while(!solve(position,searchspace))			//Add in threads here to account for cubeturns.(better way???)
{cout << "finished search at Depth: " << searchspace+0 << "\n";searchspace++;}

cout<< "solution found with " << searchspace+0 << " moves.\n" ;
*/
// Position lösen

// Done xD

//  int foo = 0;						//temporary too make the programm last longer on screen
//  cin >> foo;

}
