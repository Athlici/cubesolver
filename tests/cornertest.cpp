#include <iostream>
#include <fstream>
#include <cstdlib>

#include "../arrays.cpp"
#include "../helpers.cpp"

using namespace std;

unsigned char size[5];
unsigned char things[5];

void sort(unsigned char amount){
  for (unsigned char tmp=0; tmp<=amount; tmp++) size[tmp]=things[tmp];
  for (char i=0; i<amount; i++){
    for (unsigned char j=amount-1; j>=0; j--){
      if (things[j]>things[j+1]){
        unsigned char tmp=things[j];
        things[j]=things[j+1];
        things[j+1]=tmp;}
    }
  }
}

int main(int argc, char** argv) {

int tmp=0;

for (things[0];things[0]<24;things[0]++){
  size[0]=things[0];
  for (unsigned char B=0;B<23;B++){
    things[1]=B;
    if (B>=size[0]) things[1]++;
    sort(1);

    for (unsigned char C=0;C<22;C++){
      things[2]=C;
      if (things[2]>=size[0]) {things[2]++;
        if (things[2]>=size[1]) {things[2]++;}}
      sort(2);

      for (unsigned char D=0;D<21;D++){
	things[3]=D;
	if (things[3]>=size[0]) {things[3]++;
	  if (things[3]>=size[1]) {things[3]++;
	    if (things[3]>=size[2]) {things[3]++;}}}
	sort(3);

	for (unsigned char E=0;E<20;E++){
	  things[4]=E;
	  if (things[4]>=size[0]) {things[4]++;
	    if (things[4]>=size[1]) {things[4]++;
	      if (things[4]>=size[2]) {things[4]++;
	  	if (things[4]>=size[3]) {things[4]++;}}}}
	  sort(4);

	  for (unsigned char F=0;F<19;F++){
	    unsigned char f=F;
            if (f>=size[0]) {f++;
              if (f>=size[1]) {f++;
		if (f>=size[2]) {f++;
            	  if (f>=size[3]) {f++;
            	    if (f>=size[4]) f++;}}}}

	    if (poscorners(things[0],things[1],things[2],things[3],things[4],f)!=tmp) {
	      cout << "nonlinearity at:" << things[0]+0 << ";" << B+0 << ";" << C+0 << ";" << D+0 << ";" << E+0 << ";" << F+0 << "\n";
	      cout << things[0]+0 << ";" << things[1]+0 << ";" << things[2]+0 << ";" << things[3]+0 << ";" << things[4]+0 << ";" << f+0 << "\n";
	      cout << "Array:" << size[0]+0 << ";" << size[1]+0 << ";" << size[2]+0 << ";" << size[3]+0 << ";" << size[4]+0 << "\n";
	      cout << poscorners(things[0],things[1],things[2],things[3],things[4],f)+0 << "\n";
	    }
	    tmp++;
	  }
	}
      }
    }
  }
}
}
