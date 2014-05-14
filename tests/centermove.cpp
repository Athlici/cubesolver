#include <iostream>
#include <cstdlib>

#include "../arrays.cpp"

using namespace std;

int main(void){

for(int i=0;i<23;i++){
  unsigned char pos[24],count=0;
  for(int j=0;j<24;j++)pos[j]=j;
  for(bool done=true;done;count++){
    done=false;
    for(int j=0;j<24;j++){
      pos[j]=centerturn[i][pos[j]];
      if(pos[j]!=j)done=true;
    }
  }
  cout << "Cycle length of move " << i+0 << " is " << count+0 << "\n";
}

}
