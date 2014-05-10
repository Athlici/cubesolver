#include <iostream>
#include <cstdlib>

#include "../arrays.cpp"
#include "../helpers.cpp"
#include "../calc.cpp"

using namespace std;

int main(void){

  cout << "read test (15): upper=" << readhalfbyte(15,1)+0 << " lower=" << readhalfbyte(15,0)+0 << "\n";
  cout << "set test (0): upper→1=" << sethalfbyte(0,15,1)+0 << " lower→1=" << sethalfbyte(0,15,0)+0 << "\n";

}

