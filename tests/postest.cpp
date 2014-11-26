#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include <math.h>

using namespace std;

typedef struct {
  uint8_t edge[7];
  uint8_t center[24];
  uint8_t corner[24];
} cube ;

uint8_t *table[3];

#include "../arrays.cpp"
#include "../helpers.cpp"
#include "../calc.cpp"

int main(void){
/*
  for(uint64_t x=0;x<51482970;x++){
    uint64_t adr=adrcenters(x);
    uint64_t pos=poscenters((adr>>56)&255,(adr>>48)&255,(adr>>40)&255,(adr>>32)&255,(adr>>24)&255,(adr>>16)&255,(adr>>8)&255,adr&255);
    if(pos!=x)
      cout << x+0 << ":" << adr+0 << ":" << pos+0 << "\n";
  }

  for(uint64_t x=0;x<88179840;x++){
    uint64_t adr=adredges(x);
    if(posedges((adr>>48)&255,(adr>>40)&255,(adr>>32)&255,(adr>>24)&255,(adr>>16)&255,(adr>>8)&255,adr&255)!=x) 
      cout << x+0 << ":" << adr+0 << "\n";
  }
*/
  for(uint64_t x=0;x<14827095360;x++){
    uint64_t adr=adrcorners(x);
    if(poscorners(adr>>56,(adr>>48)&255,(adr>>40)&255,(adr>>32)&255,(adr>>24)&255,(adr>>16)&255,(adr>>8)&255,adr&255)!=x) 
      cout << x+0 << ":" << adr+0 << "\n";
  }

}
