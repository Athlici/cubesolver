#include <iostream>

using namespace std;

#include "arrays.cpp"

unsigned char edge[6][24] = {		{22,23,21,3,4,5,6,7,8,2,0,1,10,9,11,15,16,17,18,19,20,13,12,14},
                                	{0,1,2,20,18,19,4,5,3,9,10,11,12,13,14,8,6,7,16,17,15,21,22,23},
                                	{5,3,4,19,20,18,6,7,8,9,10,11,12,13,14,15,16,17,23,21,22,1,2,0},
	                                {0,1,2,3,4,5,17,15,16,7,8,6,11,10,9,14,13,12,18,19,20,21,22,23},
        	                        {9,10,11,0,1,2,3,4,5,6,7,8,12,13,14,15,16,17,18,19,20,21,22,23},
                	                {0,1,2,3,4,5,6,7,8,9,10,11,15,17,16,18,19,20,21,22,23,12,14,13}};
int main(int argc, char** argv) {
  for (int i=0;i<6;i++){
    for (int j=0;j<24;j++){
     edgemove[3*i][j]=edge[i][j];
     edgemove[3*i+1][j]=edge[i][edge[i][j]];
     edgemove[3*i+2][j]=edge[i][edge[i][edge[i][j]]];
    }
  }

  cout << "unsigned char edgemove[18][24] =  {   ";
  for (int i=0;i<17;i++){
    cout << "                                        {";
    for (int j=0;j<23;j++) cout << edgemove[i][j]+0 << ",";
    cout << edgemove[i][23]+0 << "},\n";
  }
  cout << "                                        {";
  for (int j=0;j<23;j++) cout << edgemove[17][j]+0 << ",";
  cout << edgemove[17][23]+0 << "}};\n";
}
