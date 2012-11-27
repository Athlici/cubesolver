#include <iostream>
#include <cstdlib>

#include "../arrays.cpp"
#include "../helpers.cpp"

using namespace std;

int main(void){

//generate all the numbers which are independent when sorted by size and don't contain equal numbers
//only iterate through the numbers which are bigger than the prestanding ones

int tmp=0;

for (unsigned char A=0;A<21;A++){
  for (unsigned char B=A+1;B<22;B++){
    for (unsigned char C=B+1;C<23;C++){
      for (unsigned char D=C+1;D<24;D++){
	for (unsigned char E=D+1;E<21;E++){				//start these last loops at the minimum free positions => Array
	  for (unsigned char F=E+1;F<22;F++){
	    for (unsigned char G=F+1;G<23;G++){
	      for (unsigned char H=G+1;H<24;H++){
		if (poscenters(A,B,C,D,E,F,G,H)!=tmp){
	cout << A+0 << ";" << B+0 << ";" << C+0 << ";" << D+0 << ";" << E+0 << ";" << F+0 << ";" << G+0 << ";" << H+0 << ";" << tmp+0 << "\n";
		}
		tmp++;
	      }
	    }
	  }
	}
      }
    }
  }
}

}

