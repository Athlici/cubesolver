#include <iostream>			//change the constants so that they admit the nonimplemented moves

using namespace std;

#include "../arrays.cpp"

unsigned char edge[6][24] = {		{22,23,21,3,4,5,6,7,8,2,0,1,10,9,11,15,16,17,18,19,20,13,12,14},
                                	{0,1,2,20,18,19,4,5,3,9,10,11,12,13,14,8,6,7,16,17,15,21,22,23},
                                	{5,3,4,19,20,18,6,7,8,9,10,11,12,13,14,15,16,17,23,21,22,1,2,0},
	                                {0,1,2,3,4,5,17,15,16,7,8,6,11,10,9,14,13,12,18,19,20,21,22,23},
        	                        {9,10,11,0,1,2,3,4,5,6,7,8,12,13,14,15,16,17,18,19,20,21,22,23},
                	                {0,1,2,3,4,5,6,7,8,9,10,11,15,17,16,18,19,20,21,22,23,12,14,13}};

int main(int argc, char** argv) {
  for (int j=0;j<24;j++){
  for (int i=0;i<3;i++){				//sets the first 3 lines
     edgeturn[i][j]=edgemove[6+i][edgemove[9+i][j]];
  }
    for (int k=0;k<3;k++){
      edgeturn[4*k+3][j]=edgemove[k][edgemove[3+k][j]];
      for (int i=0;i<3;i++){
        edgeturn[i+4*(k+1)][j]=edgemove[6+i][edgemove[9+i][edgemove[k][edgemove[3+k][j]]]];
      }
    }
    for (int k=0;k<2;k++){
      edgeturn[4*k+15][j]=edgemove[12+2*k][edgemove[15+2*k][j]];
      for (int i=0;i<3;i++){
        edgeturn[i+4*(k+4)][j]=edgemove[6+i][edgemove[9+i][edgemove[12+2*k][edgemove[15][j]]]];
      }
    }
  }
  cout << "unsigned char edgeturn[23][24] =  {   ";
  for (int i=0;i<22;i++){
    cout << "                                        {";
    for (int j=0;j<23;j++) cout << edgeturn[i][j]+0 << ",";
    cout << edgeturn[i][23]+0 << "},\n";
  }
  cout << "                                        {";
  for (int j=0;j<23;j++) cout << edgeturn[22][j]+0 << ",";
  cout << edgeturn[22][23]+0 << "}};\n";
}
