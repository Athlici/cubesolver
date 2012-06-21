#include <iostream>
#include <fstream>
#include <cstdlib>

#include "../arrays.cpp"
#include "../helpers.cpp"

using namespace std;

int main(int argc, char** argv) {

int tmp=0;

for (unsigned char a=0;a<24;a++){
  for (unsigned char b=0;b<24;b++){
    if (b==a) b++;
    for (unsigned char c=0;c<24;c++){
      if (c==a) c++;
      if (c==b) c++;
      for (unsigned char d=0;d<24;d++){
	if (d==a) d++;
	if (d==b) d++;
	if (d==c) d++;
	for (unsigned char e=0;e<24;e++){
	  if (e==a) e++;
	  if (e==b) e++;
	  if (e==c) e++;
	  if (e==d) e++;
	  for (unsigned char f=0;f<24;f++){
            if (f==a) f++;
            if (f==b) f++;
            if (f==c) f++;
            if (f==d) f++;
            if (f==e) f++;
	    if (poscorners(a,b,c,d,e,f)!=tmp) {
	      cout << "nonlinearity\n";
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



