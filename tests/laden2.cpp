#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

bool ReadFile(unsigned char* mem, int size) {
  FILE* pFile=fopen("test.bin","rb");
  if(pFile!=0){
    int tmp=fread(mem,1,size,pFile);
    fclose(pFile);
    return !tmp;
  } else return true;
}

bool WriteFile(unsigned char* mem, int size) {
  FILE* pFile=fopen("test.bin","wb");
  if(pFile!=0){
    int tmp=fwrite(mem,1,size,pFile);
    fclose(pFile);
    return !tmp;
  } else return true;
}

/**
 * Writes a binary file and reads it if existing. Check file with shell command "xxd -b"
 */

int main() {
  unsigned char* buffer;buffer=(unsigned char*) malloc(256);
//  if(!ReadFile(buffer, 256)) {
//    for(int i=0; i<256; i++) /*cout << buffer[i];*/ cout << *(buffer+i)+0;
//    cout << endl;
//  }

  for(int i=0; i<256; i++)*(buffer+i)=i;
  cout << WriteFile(buffer, 256) << endl;
}

