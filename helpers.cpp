cube turncube (cube Cube,uint8_t move){
  for(int i=0;i<7;i++)
    Cube.edge[i]=edgeturn[move][Cube.edge[i]];
  for(int i=0;i<24;i++){
    Cube.center[i]=centerturn[move][Cube.center[i]];
    Cube.corner[i]=cornerturn[move][Cube.corner[i]];
  }
  return Cube;
}

cube movecube (cube Cube,uint8_t move){
  for(int i=0;i<7;i++)
    Cube.edge[i]=edgemove[edgemap[move]][Cube.edge[i]];
  for(int i=0;i<24;i++){
    Cube.center[i]=centermove[move][Cube.center[i]];
    Cube.corner[i]=cornermove[move][Cube.corner[i]];
  }
  return Cube;
}

bool solved(cube Cube){
  for(int i=0;i<7;i++)
    if(Cube.edge[i]!=3*i) return false;
  for(int i=0;i<24;i++)
    if(Cube.center[i]!=i || Cube.corner[i]!=i) return false;
  
  return true;
}

cube goal(void){
  cube Cube;
  for(int i=0;i<7;i++)
    Cube.edge[i]=3*i;
  for(int i=0;i<24;i++){
    Cube.center[i]=i;
    Cube.corner[i]=i;
  }
  return Cube;
}

void printcube(cube Cube){
  cout << "edges: " ;
  for(int i=0;i<7;i++)cout << Cube.edge[i]+0 << ";";
  cout << "\ncenters: ";
  for(int i=0;i<24;i++)cout << Cube.center[i]+0 << ";";
  cout << "\ncorners: ";
  for(int i=0;i<24;i++)cout << Cube.corner[i]+0 << ";";
  cout << "\n" ;
}
