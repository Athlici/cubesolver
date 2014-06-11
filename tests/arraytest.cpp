#include <iostream>

using namespace std;

#include "../arrays.cpp"

int main(int argc, char** argv) {

  bool full[24];

  for (int i=0;i<36;i++){
    for (int j=0;j<24;j++) full[j]=false;
    for (int j=0;j<24;j++){
      if (full[cornermove[i][j]]) cout << "DoubLL Numb3r in line " << i+0 << "\n";
      else full[cornermove[i][j]]=true;
    if (cornermove[i][cornermove[i][cornermove[i][cornermove[i][j]]]]!=j) cout << "Logic corner mistake in line " << i+0 << " char " << j+0 << "\n";
    }
  }

  for (int i=0;i<36;i++){
    for (int j=0;j<24;j++) full[j]=false;
    for (int j=0;j<24;j++){
      if (full[centermove[i][j]]) cout << "DoubLL Numb3r in line " << i+0 << "\n";
      else full[centermove[i][j]]=true;
    if (centermove[i][centermove[i][centermove[i][centermove[i][j]]]]!=j) cout << "Logic center mistake in line " << i+0 << " char " << j+0 << "\n";
    }
  }

  for (int i=0;i<18;i++){
    for (int j=0;j<24;j++) full[j]=false;
    for (int j=0;j<24;j++){
      if (full[edgemove[i][j]]) cout << "DoubLL Numb3r in line " << i+0 << "\n";
      else full[edgemove[i][j]]=true;
    if (edgemove[i][edgemove[i][edgemove[i][edgemove[i][j]]]]!=j) cout << "Logic edge mistake in line " << i+0 << " char " << j+0 << "\n";
    }
  }

  for (int i=0;i<23;i++){
    for (int j=0;j<24;j++) full[j]=false;
    for (int j=0;j<24;j++){
      if (full[centerturn[i][j]]) cout << "DoubLL Numb3r in line " << i+0 << "\n";
      else full[centerturn[i][j]]=true;
//    if (centerturn[i][centerturn[i][centerturn[i][centerturn[i][j]]]]!=j) cout << "Logic centerturn mistake in line " << i+0 << " char " << j+0 << "\n";
    }
  }

  for (int i=0;i<23;i++){
    for (int j=0;j<24;j++) full[j]=false;
    for (int j=0;j<24;j++){
      if (full[cornerturn[i][j]]) cout << "DoubLL Numb3r in line " << i+0 << "\n";
      else full[cornerturn[i][j]]=true;
//    if (cornerturn[i][cornerturn[i][cornerturn[i][cornerturn[i][j]]]]!=j) cout << "Logic cornerturn mistake in line " << i+0 << " char " << j+0 << "\n";
    }
  }

  for (int i=0;i<23;i++){
    for (int j=0;j<24;j++) full[j]=false;
    for (int j=0;j<24;j++){
      if (full[edgeturn[i][j]]) cout << "DoubLL Numb3r in line " << i+0 << "\n";
      else full[edgeturn[i][j]]=true;
//    if (cornerturn[i][cornerturn[i][cornerturn[i][cornerturn[i][j]]]]!=j) cout << "Logic cornerturn mistake in line " << i+0 << " char " << j+0 << "\n";
    }
  }

}
