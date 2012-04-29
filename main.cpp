/*
 * 	main.cpp
 *
 *  Created on: 29.04.2012
 *      Author: Felix Jung <felix.jung@wilhelm-gym.net>
 *
 *	Copyright (C) 2012 Felix Jung
 *
 *  This file is part of cubesolver.
 *
 *  cubesolver is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 3.
 *
 *  cubesolver is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with cubesolver.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

bool CheckFile(string filename) {
  fstream File(filename.c_str());
  return File;
}

int main(int argc, char** argv) {
  cout << CheckFile("/home/felix/Desktop/test") << endl;
  char * buff;
  buff = (char*) malloc(400000000);
  for(int i=0;i<400000000;i++) *(buff+i) =42;
  int foo = 0;
  cin >> foo;
}

