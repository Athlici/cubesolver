#include <iostream>
#include <fstream>
#include <cstdlib>

#include "../arrays.cpp"
#include "../helpers.cpp"

using namespace std;

int main(int argc, char** argv) {

int tmp=0;
unsigned char size[5]; 

for (unsigned char a=0;a<24;a++){
  for (unsigned char B=0;B<23;B++){
    unsigned char b=B;
    if (B>=a) {b++;
    size[0]=a; size[1]=b;}
    else {size[0]=b; size[1]=a;}

    for (unsigned char C=0;C<22;C++){
      unsigned char c=C;
      if (c>=size[0]) {c++;
        if (c>=size[1]) {c++;
	  size[2]=c;}
	else {size[2]=size[1]; size[1]=c;}}
      else {size[2]=size[1]; size[1]=size[0]; size[0]=c;}

      for (unsigned char D=0;D<21;D++){
	unsigned char d=D;
	if (d>=size[0]) {d++;
	  if (d>=size[1]) {d++;
	    if (d>=size[2]) {d++;size[3]=d;}
	    else {size[3]=size[2]; size[2]=d;}}
	  else {size[3]=size[2]; size[2]=size[1]; size[1]=d;}}
	else {size[3]=size[2]; size[2]=size[1]; size[1]=size[0]; size[0]=d;}

	for (unsigned char E=0;E<20;E++){
	  unsigned char e=E;
	  if (e>=size[0]) {e++;
	    if (e>=size[1]) {e++;
	      if (e>=size[2]) {e++;
	  	if (e>=size[3]) {e++; size[4]=e;}
		else {size[4]=size[3]; size[3]=e;}}
	      else {size[4]=size[3]; size[3]=size[2]; size[2]=e;}}
	    else {size[4]=size[3]; size[3]=size[2]; size[2]=size[1]; size[1]=e;}}
	  else {size[4]=size[3]; size[3]=size[2]; size[2]=size[1]; size[1]=size[0]; size[0]=e;}

	  for (unsigned char F=0;F<19;F++){
	    unsigned char f=F;
            if (f>=size[0]) {f++;
              if (f>=size[1]) {f++;
		if (f>=size[2]) {f++;
            	  if (f>=size[3]) {f++;
            	    if (f>=size[4]) f++;}}}}
	    /*f+=(f>=size[0]);
            f+=(f>=size[1]);
            f+=(f>=size[2]);
            f+=(f>=size[3]);
            f+=(f>=size[4]);*/

	    if (poscorners(a,b,c,d,e,f)!=tmp) {
	      cout << "nonlinearity at:" << a+0 << ";" << B+0 << ";" << C+0 << ";" << D+0 << ";" << E+0 << ";" << F+0 << "\n";
	      cout << a+0 << ";" << b+0 << ";" << c+0 << ";" << d+0 << ";" << e+0 << ";" << f+0 << "\n";}
	    tmp++;
	    //cout << a+0 << ";" << b+0 << ";" << c+0 << ";" << d+0 << ";" << e+0 << ";" << f+0 << "\n" << poscorners(a,b,c,d,e,f)+0 << "\n";
	  }
	}
      }
    }
  }
}

}



