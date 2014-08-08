#include <iostream>
#include <cstdlib>
#include <stdint.h>

using namespace std;

typedef unsigned int uint;
typedef unsigned char uchar;
typedef uint64_t ulong;

uchar *corners[32];
const ulong cornersize = 14827095360;			//Size of the array for cornerdepthlookups in Bytes

int main(int argc, char** argv) {

for(uchar i=0;i<=255;i++) cout << (~i)+0 << ";" ;

for(int i=0;i<32;i++) corners[i]=(unsigned char*) calloc(1,cornersize/32);

  uint foo = 0;
  cin >> foo;
}
