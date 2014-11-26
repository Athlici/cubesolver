#include <iostream>
#include <cstdlib>
#include <stdint.h>

using namespace std;

uint64_t setchar(uint64_t input,uint8_t shift,uint8_t change){
  shift*=8;
/*  asm ( "rol %1,%0    \n\t"
        "mov %2,%%al  \n\t"
        "ror %1,%0    \n\t"
        : "+a" (input) : "r" (shift), "r" (change) );*/
  input=(input<<(64-shift))^(input>>shift);
asm ("mov %1,%%al" : "+a" (input) : "r" (change) );
  return (input<<shift)^(input>>(64-shift));
}

uint8_t getchar(uint64_t input,uint8_t shift){
  return (input>>(8*shift))&255;
}


int main(void){

uint64_t tmp=setchar(0,0,0);
tmp=setchar(tmp,1,1);
tmp=setchar(tmp,2,2);
tmp=setchar(tmp,3,3);
tmp=setchar(tmp,4,4);
tmp=setchar(tmp,5,5);
tmp=setchar(tmp,6,6);
tmp=setchar(tmp,7,7);
for(int i=0;i<8;i++)cout << getchar(tmp,i)+0 << ";";
cout << "\n";

}
