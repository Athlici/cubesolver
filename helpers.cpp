/*
int LoadFile(unsigned char* mem, string filename, int size) {
	fstream File(filename.c_str(), ios::in | ios::binary);
	if(!File.read(mem, size)) {File.clear(); return 1;} else return 0;  // return 1 in case of read error
}

int WriteFile(unsigned char* mem, string filename, int size) {
	fstream File(filename.c_str(), ios::out | ios::binary);
	if(!File.write(mem, size)) {File.clear(); return 1;} else return 0;
}
*/

cube turncube (cube Cube,uint8_t move){
  for(int i=0;i<8;i++)
    cube.edge[i]=edgeturn[move][cube.edge[i]];
  for(int i=0;i<24;i++){
    cube.center[i]=centerturn[move][cube.center[i]];
    cube.corner[i]=cornerturn[move][cube.corner[i]];
  }
  return Cube;
}

cube movecube (cube Cube,uint8_t move){
  for(int i=0;i<8;i++)
    cube.edge[i]=edgemove[move][cube.edge[i]];
  for(int i=0;i<24;i++){
    cube.center[i]=centermove[move][cube.center[i]];
    cube.corner[i]=cornermove[move][cube.corner[i]];
  }
  return Cube;
}

bool solved(cube Cube){
/*  return Cube.edge==..&&
    Cube.center[0]==..&&Cube.center[1]==..&&Cube.center[2]==..&&
    Cube.corner[0]==..&&Cube.corner[1]==..&&Cube.corner[2]==..;*/
  for(int i=0;i<8;i++)
    if(Cube.edge[i]!=i) return false;
  for(int i=0;i<24;i++)
    if(Cube.center[i]!=i && Cube.corner[i]!=i) return false;
  
  return true;
}

void printcube(cube Cube){
  cout << "edges: " ;
  for(int i=0;i<8;i++)cout << Cube.edge[i]+0 << ";";
  cout << "\ncenters: ";
  for(int i=0;i<24;i++)cout << Cube.center[i]+0 << ";";
  cout << "\ncorners: ";
  for(int i=0;i<24;i++)cout << Cube.corner[i]+0 << ";";
  cout << "\n" ;
}
