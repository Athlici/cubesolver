#include <iostream>
#include <fstream>
#include <cstdlib>

typedef unsigned int uint;
typedef unsigned char uchar;
uchar *corners, *edges, *centers;
using namespace std;

#include "../arrays.cpp"
#include "../calc.cpp"
#include "../helpers.cpp"

unsigned char size[6];
unsigned char things[6];

void sort(unsigned char amount){
  for (unsigned char tmp=0; tmp<=amount; tmp++) size[tmp]=things[tmp];
  for (char i=0; i<amount; i++){
    for (unsigned char j=amount--; j>=0; j--){
      if (things[j]>things[j+1])/*{
        unsigned char tmp=things[j];
        things[j]=things[j+1];
        things[j+1]=tmp;}*/
	swap(things[j],things[j+1]);
      /*unsigned char tmp=things[j]^((things[j]^things[j++]) & -(things[j]<things[j++]));
      things[j]+=things[j++]-tmp;
      things[j++]=tmp;*/
    }
  }
}

int main() {

int tmp=0;

for (things[0];things[0]<24;things[0]++){
  cout << "checking positions with first edge: " << things[0]+0 << "\n";
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
/* I have no memory of how this code is supposed to work.
tmp=0;

for (things[0];things[0]<24;things[0]++){
  size[0]=things[0];
  for (unsigned char B=0;B<23;B++){
    things[1]=B;
    if (B>=size[0]) things[1]+=3;
    sort(1);

    for (unsigned char C=0;C<22;C++){
      things[2]=C;
      if (things[2]>=size[0]) {things[2]+=3;
        if (things[2]>=size[1]) {things[2]+=3;}}
      sort(2);

      for (unsigned char D=0;D<21;D++){
	things[3]=D;
	if (things[3]>=size[0]) {things[3]+=3;
	  if (things[3]>=size[1]) {things[3]+=3;
	    if (things[3]>=size[2]) {things[3]+=3;}}}
	sort(3);

	for (unsigned char E=0;E<20;E++){
	  things[4]=E;
	  if (things[4]>=size[0]) {things[4]+=3;
	    if (things[4]>=size[1]) {things[4]+=3;
	      if (things[4]>=size[2]) {things[4]+=3;
	  	if (things[4]>=size[3]) {things[4]+=3;}}}}
	  sort(4);

	  for (unsigned char F=0;F<19;F++){
	    things[5]=F;
            if (things[5]>=size[0]) {things[5]+=3;
              if (things[5]>=size[1]) {things[5]+=3;
		if (things[5]>=size[2]) {things[5]+=3;
            	  if (things[5]>=size[3]) {things[5]+=3;
            	    if (things[5]>=size[4]) {things[5]+=3;}}}}}
	    sort(5);

	    for (unsigned char G=0;G<18;G++){
	      unsigned char g=G;
            if (g>=size[0]) {g+=3;
              if (g>=size[1]) {g+=3;
                if (g>=size[2]) {g+=3;
                  if (g>=size[3]) {g+=3;
                    if (g>=size[4]) {g+=3;
		      if (g>=size[5]) {g+=3;}}}}}}

	    if (posedges(things[0],things[1],things[2],things[3],things[4],things[5],g)!=tmp) {
	      cout << "nonlinearity at:" << things[0]+0 << ";" << B+0 << ";" << C+0 << ";" << D+0 << ";" << E+0 << ";" << F+0 << ";" << G+0 << "\n";
	      cout << things[0]+0 << ";" << things[1]+0 << ";" << things[2]+0 << ";" << things[3]+0 << ";" << things[4]+0 << ";" << things[5]+0 << ";" << g+0 << "\n";
	      cout << "Array:" << size[0]+0 << ";" << size[1]+0 << ";" << size[2]+0 << ";" << size[3]+0 << ";" << size[4]+0 << ";" << size[5]+0 << "\n";
	      cout << posedges(things[0],things[1],things[2],things[3],things[4],things[5],g)+0 << "\n";
	    }
	    tmp++;
	    }
	  }
	}
      }
    }
  }
}
*/
}
