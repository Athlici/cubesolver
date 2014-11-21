#include <iostream>
#include <cstdlib>
#include <stdint.h>

#include "../arrays.cpp"

using namespace std;

int main(void){

for(int k=0;k<3;k++){
  const char *out[]={"edge","corner","center"};
  cout << "Calculating cycle lenght for " << out[k] << "table:\n";
  for(int i=0;i<23;i++){
    unsigned char pos[24],count=0;
    for(int j=0;j<24;j++)pos[j]=j;
    for(bool done=true;done;count++){
      done=false;
      for(int j=0;j<24;j++){
        switch(k){
	  case 0:pos[j]=edgeturn[i][pos[j]];break;
	  case 1:pos[j]=cornerturn[i][pos[j]];break;
	  case 2:pos[j]=centerturn[i][pos[j]];
	}
        if(pos[j]!=j)done=true;
      }
    }
    cout << "Cycle length of move " << i+0 << " is " << count+0 << "\n";
  }
}

}
