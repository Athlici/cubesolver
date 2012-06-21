/*
 * 	main.cpp
 *
 *  Created on: 29.04.2012
 *      Author: Felix Jung <felix.jung@wilhelm-gym.net>
 *
 *	Copyright (C) 2012 Felix Jung, Tobias Stamm
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

unsigned char *corners, *edges, *centers;
const int cornersize = 48454560;
const int edgesize = 44089920;
const int centersize = 25741485;

#include "arrays.cpp"
#include "helpers.cpp"
#include "create.cpp"
#include "solve.cpp"

int main(int argc, char** argv) {
// getcenters();
// getedges();
 getcorners(); 

// Position einlesen

// Position lösen

// Done xD

  int foo = 0;
  cin >> foo;

}
