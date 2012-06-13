#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {

unsigned char a=14,b=7,c=18,d=24;
/* if (a<b) b--;
 if (a<c) c--;
 if (b<c) c--;
 if (a<d) d--;
 if (b<d) d--;
 if (c<d) d--;*/
b-=(a<b);
c-=(a<c);
c-=(b<c);
d-=(a<d);
d-=(b<d);
d-=(c<d);

cout << a+0 << ";" << b+0 << ";" << c+0 << ";" << d+0 << "\n";

}
