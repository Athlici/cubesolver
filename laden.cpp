#include <iostream>
#include <fstream>
using namespace std;

int ReadFile(char* mem, string filename, int size) {
	fstream File(filename.c_str(), ios::in | ios::binary);
	if(!File.read(mem, size)) {File.clear(); return 1;} else return 0;
}

int WriteFile(char* mem, string filename, int size) {
	fstream File(filename.c_str(), ios::out | ios::binary);
	if(!File.write(mem, size)) {File.clear(); return 1;} else return 0;
}

/**
 * Writes a binary file and reads it if existing. Check file with shell command "xxd -b"
 */

int main() {
	char buffer[100];
  if(!ReadFile(buffer, "test.bin", 100)) {
	for(int i = 0; i<100; i++) cout << buffer[i];
	cout << endl;}

	for(int i = 0; i<100; i++) buffer[i] = i;
	cout << WriteFile(buffer, "test.bin", 100) << endl;
}

