#include <iostream>

using namespace std;

#include "arrays.cpp"

//still full of well hidden bugs

unsigned char edge[6][24] = {		{22,23,21,3,4,5,6,7,8,2,0,1,10,9,11,15,16,17,18,19,20,13,12,14},
                                	{0,1,2,20,18,19,4,5,3,9,10,11,12,13,14,8,6,7,16,17,15,21,22,23},
                                	{5,3,4,19,20,18,6,7,8,9,10,11,12,13,14,15,16,17,23,21,22,1,2,0},
	                                {0,1,2,3,4,5,17,15,16,7,8,6,11,10,9,14,13,12,18,19,20,21,22,23},
        	                        {9,10,11,0,1,2,3,4,5,6,7,8,12,13,14,15,16,17,18,19,20,21,22,23},
                	                {0,1,2,3,4,5,6,7,8,9,10,11,15,17,16,18,19,20,21,22,23,12,14,13}};
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
bool full[24];
int main(int argc, char** argv) {
/*  for (int i=0;i<12;i++){
    for (int j=0;j<24;j++) full[j]=false;
    for (int j=0;j<24;j++){
      if (full[corner[i][j]]) cout << "Doubbel Numb3r in line " << i+0 << "\n";
      else full[corner[i][j]]=true;
    }
  }*/
  for (int i=0;i<6;i++){
    for (int j=0;j<24;j++){
     edgemove[3*i][j]=edge[i][j];
     edgemove[3*i+1][j]=edge[i][edge[i][j]];
     edgemove[3*i+2][j]=edge[i][edge[i][edge[i][j]]];
     //if (edge[i][edge[i][edge[i][edge[i][j]]]]!=j) cout << "Logic edge mistake in line " << i+0 << " char " << j+0 << "\n";
    }
  }
  for (int i=0;i<12;i++){
    for (int j=0;j<24;j++){
     centermove[3*i][j]=center[i][j];
     centermove[3*i+1][j]=center[i][center[i][j]];
     centermove[3*i+2][j]=center[i][center[i][center[i][j]]];
     //if (center[i][center[i][center[i][center[i][j]]]]!=j) cout << "Logic center mistake in line " << i+0 << " char " << j+0 << "\n";
     cornermove[3*i][j]=corner[i][j];
     cornermove[3*i+1][j]=corner[i][corner[i][j]];
     cornermove[3*i+2][j]=corner[i][corner[i][corner[i][j]]];
     //if (corner[i][corner[i][corner[i][corner[i][j]]]]!=j) cout << "Logic corner mistake in line " << i+0 << " char " << j+0 << "\n";  
    }
  }
  for (int i=0;i<3;i++){
    for (int j=0;j<24;j++){
     edgeturn[i][j]=edgemove[12+i][edgemove[15+i][edgemove[18+i][edgemove[21+i][j]]]];
     centerturn[i][j]=centermove[12+i][centermove[15+i][centermove[18+i][centermove[21+i][j]]]];
     cornerturn[i][j]=cornermove[12+i][cornermove[15+i][cornermove[18+i][cornermove[21+i][j]]]];
    }
  }
  for (int k=0;k<3;k++){
    for (int j=0;j<24;j++){
       edgeturn[4*k+3][j]=edgemove[k][edgemove[3+k][edgemove[6+k][edgemove[9+k][j]]]];
       centerturn[4*k+3][j]=centermove[k][centermove[3+k][centermove[6+k][centermove[9+k][j]]]];
       cornerturn[4*k+3][j]=cornermove[k][cornermove[3+k][cornermove[6+k][cornermove[9+k][j]]]];
    }
    for (int i=0;i<3;i++){
      for (int j=0;j<24;j++){
       edgeturn[i+4*(k+1)][j]=edgemove[12+i][edgemove[15+i][edgemove[18+i][edgemove[21+i][
					edgemove[k][edgemove[3+k][edgemove[6+k][edgemove[9+k][j]]]]]]]];
       centerturn[i+4*(k+1)][j]=centermove[12+i][centermove[15+i][centermove[18+i][centermove[21+i][
					centermove[k][centermove[3+k][centermove[6+k][centermove[9+k][j]]]]]]]];
       cornerturn[i+4*(k+1)][j]=cornermove[12+i][cornermove[15+i][cornermove[18+i][cornermove[21+i][
					cornermove[k][cornermove[3+k][cornermove[6+k][cornermove[9+k][j]]]]]]]];
      }
    }
  }
  for (int k=0;k<2;k++){
    for (int j=0;j<24;j++){
       edgeturn[4*k+15][j]=edgemove[24+2*k][edgemove[27+2*k][edgemove[30+2*k][edgemove[33+2*k][j]]]];
       centerturn[4*k+15][j]=centermove[24+2*k][centermove[27+2*k][centermove[30+2*k][centermove[33+2*k][j]]]];
       cornerturn[4*k+15][j]=cornermove[24+2*k][cornermove[27+2*k][cornermove[30+2*k][cornermove[33+2*k][j]]]];
    }
    for (int i=0;i<3;i++){
      for (int j=0;j<24;j++){
       edgeturn[i+4*(k+4)][j]=edgemove[12+i][edgemove[15+i][edgemove[18+i][edgemove[21+i][
					edgemove[24+2*k][edgemove[27+2*k][edgemove[30+2*k][edgemove[33+2*k][j]]]]]]]];
       centerturn[i+4*(k+4)][j]=centermove[12+i][centermove[15+i][centermove[18+i][centermove[21+i][
					centermove[24+2*k][centermove[27+2*k][centermove[30+2*k][centermove[33+2*k][j]]]]]]]];
       cornerturn[i+4*(k+4)][j]=cornermove[12+i][cornermove[15+i][cornermove[18+i][cornermove[21+i][
					cornermove[24+2*k][cornermove[27+2*k][cornermove[30+2*k][cornermove[33+2*k][j]]]]]]]];
      }
    }
  }
  cout << "unsigned char centermove[36][24] =  {   ";
  for (int i=0;i<35;i++){
    cout << "                                        {";
    for (int j=0;j<23;j++) cout << centermove[i][j]+0 << ",";
    cout << centermove[i][23]+0 << "},\n";
  }
  cout << "                                        {";
  for (int j=0;j<23;j++) cout << centermove[35][j]+0 << ",";
  cout << centermove[35][23]+0 << "}};\n";

  cout << "unsigned char cornermove[18][24] =  {   ";
  for (int i=0;i<35;i++){
    cout << "                                        {";
    for (int j=0;j<23;j++) cout << cornermove[i][j]+0 << ",";
    cout << centermove[i][23]+0 << "},\n";
  }
  cout << "                                        {";
  for (int j=0;j<23;j++) cout << centermove[35][j]+0 << ",";
  cout << centermove[35][23]+0 << "}};\n";

  cout << "unsigned char edgemove[18][24] =  {   ";
  for (int i=0;i<17;i++){
    cout << "                                        {";
    for (int j=0;j<23;j++) cout << edgemove[i][j]+0 << ",";
    cout << edgemove[i][23]+0 << "},\n";
  }
  cout << "                                        {";
  for (int j=0;j<23;j++) cout << edgemove[17][j]+0 << ",";
  cout << edgemove[17][23]+0 << "}};\n";

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
