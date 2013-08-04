#include <iostream>
#include <cstdlib>

#include "../arrays.cpp"
#include "../helpers.cpp"
#include "../calc.cpp"

using namespace std;

unsigned char taken[20]={4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};		//if I would only know how to pass arrays.
unsigned char pos[24]={128,128,128,128,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};	//position of the number in the array

int main(void){

//generate all the numbers which are independent when sorted by size and don't contain equal numbers
//only iterate through the numbers which are bigger than the prestanding ones

unsigned char A=0,B=1,C=2,D=3,E=4,F=5,G=6,H=7,e=0,f=0,g=0,h=0;
int count=0

do{
  if(count!=poscenters(A,B,C,D,E,F,G,H)) cout << A+0 << ";" << B+0 << ";" << C+0 << ";" << D+0 << ";" << E+0 << ";" << F+0 << ";" 
	<< G+0 << ";" << H+0 << ";" << count+0 << "\n";
  count++;
  if(h!=16){h++;H=taken[h+3];}									//take the next free number
  else{
    if(g!=16){g++;G=taken[g+2];h=g;H=taken[h+3];}						//same, but reset h
    else{
      if(f!=16){f++;F=taken[f+1];g=f;G=taken[g+2];h=g;H=taken[h+3];}				//and so on
      else{
	if(e!=16){e++;E=taken[e];f=e;F=taken[f+1];g=f;G=taken[g+2];h=g;H=taken[h+3];}
	else{
	  if(d!=23){fix(d);d++;}								//increase, but update the taken numbers
	  else{
	    if(c!=22){fix(c);c++;/*have to shift the whole array by one position*/}
	    else{
	      if(b!=21){fix(b);b++;/*even more of this shit*/}
	      else{
		fix(a);a++;/*don't even get me started*/
	      }
	    }
	  }
	  e=0;f=0;g=0;h=0;E=taken[e];F=taken[f];G=taken[g];H=taken[h];	//and reset the lower bytes;this would be TWO asm instructions :( 
	}
      }
    }
  }
}while(A!=20||B!=21||C!=22||D!=23||E!=16||F!=17||G!=18||H!=19)

}

inline void fix(unsigned char a){		//number to be corrected. (easy because the list is already sorted)
  taken[pos[a+1]]=a;pos[a]=pos[a+1];pos[a+1]=128;
}
