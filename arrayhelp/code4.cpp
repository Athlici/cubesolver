#include <iostream>

using namespace std;

#include "../arrays.cpp"

unsigned char center[12][24] = {	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,19,16,17,18,20,21,22,23},
                                	{12,1,2,15,0,5,6,3,4,9,10,7,8,13,14,11,16,17,18,19,20,21,22,23},
                                	{0,13,14,3,4,1,2,7,8,5,6,11,12,9,10,15,16,17,18,19,20,21,22,23},
	                                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21,22,23,20},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,15,12,13,14,16,17,18,19,20,21,22,23},
        	                        {20,21,2,3,4,5,6,7,8,9,16,17,12,13,14,15,0,1,18,19,10,11,22,23},
					{0,1,22,23,4,5,6,7,18,19,10,11,12,13,14,15,16,17,2,3,20,21,8,9},
                                        {0,1,2,3,5,6,7,4,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {3,0,1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,23,20,6,7,8,9,10,11,12,13,17,18,16,4,5,19,15,21,22,14},
                                        {0,1,2,3,4,5,21,22,8,9,10,11,19,16,14,15,7,17,18,6,20,12,13,23},
                                        {0,1,2,3,4,5,6,7,9,10,11,8,12,13,14,15,16,17,18,19,20,21,22,23}};
unsigned char corner[12][24] = {	{0,1,2,3,4,5,16,17,8,9,10,11,12,13,7,6,21,20,18,19,14,15,22,23},
                                	{10,1,2,3,4,0,6,7,5,9,8,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                	{0,11,2,3,1,5,6,7,8,4,10,9,12,13,14,15,16,17,18,19,20,21,22,23},
	                                {0,1,19,18,4,5,6,7,8,9,10,11,2,3,14,15,16,17,23,22,20,21,12,13},
        	                        {18,19,2,3,4,5,6,7,8,9,16,17,12,13,14,15,1,0,11,10,20,21,22,23},
                	                {0,1,23,3,4,5,6,2,8,9,10,11,12,13,14,15,16,17,18,19,20,7,22,21},
                	                {0,1,2,22,4,5,3,7,8,9,10,11,12,13,14,15,16,17,18,19,6,21,20,23},
                                	{0,1,2,3,13,12,6,7,14,15,10,11,9,8,4,5,16,17,18,19,20,21,22,23},
                                	{6,7,0,1,2,3,4,5,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
	                                {0,1,2,3,4,5,6,7,8,9,10,11,18,13,12,15,14,17,16,19,20,21,22,23},
        	                        {0,1,2,3,4,5,6,7,8,9,10,11,12,19,14,13,16,15,18,17,20,21,22,23},
                	                {0,1,2,3,4,5,6,7,22,23,20,21,12,13,14,15,16,17,18,19,9,8,11,10}};

int main(int argc, char** argv) {
  for (int i=0;i<3;i++){
    for (int j=0;j<24;j++){
     centerturn[i][j]=centermove[12+i][centermove[15+i][centermove[18+i][centermove[21+i][j]]]];
     cornerturn[i][j]=cornermove[12+i][cornermove[15+i][cornermove[18+i][cornermove[21+i][j]]]];
    }
  }
  for (int k=0;k<3;k++){
    for (int j=0;j<24;j++){
       centerturn[4*k+3][j]=centermove[k][centermove[3+k][centermove[6+k][centermove[9+k][j]]]];
       cornerturn[4*k+3][j]=cornermove[k][cornermove[3+k][cornermove[6+k][cornermove[9+k][j]]]];
    }
    for (int i=0;i<3;i++){
      for (int j=0;j<24;j++){
       centerturn[i+4*(k+1)][j]=centermove[12+i][centermove[15+i][centermove[18+i][centermove[21+i][
					centermove[k][centermove[3+k][centermove[6+k][centermove[9+k][j]]]]]]]];
       cornerturn[i+4*(k+1)][j]=cornermove[12+i][cornermove[15+i][cornermove[18+i][cornermove[21+i][
					cornermove[k][cornermove[3+k][cornermove[6+k][cornermove[9+k][j]]]]]]]];
      }
    }
  }
  for (int k=0;k<2;k++){
    for (int j=0;j<24;j++){
       centerturn[4*k+15][j]=centermove[24+2*k][centermove[27+2*k][centermove[30+2*k][centermove[33+2*k][j]]]];
       cornerturn[4*k+15][j]=cornermove[24+2*k][cornermove[27+2*k][cornermove[30+2*k][cornermove[33+2*k][j]]]];
    }
    for (int i=0;i<3;i++){
      for (int j=0;j<24;j++){
       centerturn[i+4*(k+4)][j]=centermove[12+i][centermove[15+i][centermove[18+i][centermove[21+i][
					centermove[24+2*k][centermove[27+2*k][centermove[30+2*k][centermove[33+2*k][j]]]]]]]];
       cornerturn[i+4*(k+4)][j]=cornermove[12+i][cornermove[15+i][cornermove[18+i][cornermove[21+i][
					cornermove[24+2*k][cornermove[27+2*k][cornermove[30+2*k][cornermove[33+2*k][j]]]]]]]];
      }
    }
  }

  cout << "unsigned char centerturn[23][24] =  {   ";
  for (int i=0;i<22;i++){
    cout << "                                        {";
    for (int j=0;j<23;j++) cout << centerturn[i][j]+0 << ",";
    cout << centerturn[i][23]+0 << "},\n";
  }
  cout << "                                        {";
  for (int j=0;j<23;j++) cout << centerturn[22][j]+0 << ",";
  cout << centerturn[22][23]+0 << "}};\n";

  cout << "unsigned char cornerturn[23][24] =  {   ";
  for (int i=0;i<22;i++){
    cout << "                                        {";
    for (int j=0;j<23;j++) cout << cornerturn[i][j]+0 << ",";
    cout << cornerturn[i][23]+0 << "},\n";
  }
  cout << "                                        {";
  for (int j=0;j<23;j++) cout << cornerturn[22][j]+0 << ",";
  cout << cornerturn[22][23]+0 << "}};\n";

}
