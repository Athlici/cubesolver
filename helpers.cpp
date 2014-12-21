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
  for(int i=0;i<7;i++)
    Cube.edge[i]=edgeturn[move][Cube.edge[i]];
  for(int i=0;i<24;i++){
    Cube.center[i]=centerturn[move][Cube.center[i]];
    Cube.corner[i]=cornerturn[move][Cube.corner[i]];
  }
  return Cube;
}

/*
25s/swap0\[\(\d*\),\(\d*\)\]/swap(Cube.center\[\1\],Cube.center\[\2\]);/g
25s/swap1\[\(\d*\),\(\d*\)\]/swap(Cube.corner\[\1\],Cube.corner\[\2\]);/g
25s/swap2\[\(\d*\),\(\d*\)\]/swap(Cube.edge\[\1\],Cube.edge\[\2\]);/g
25s/;,/;/g
25s/,{\(\d\+\)/\r case \1:/g
25,60s/},{/\r/g
25,115s/,{//g
25,115s/}}/\r      break;/g
*/

cube movecube (cube Cube,uint8_t move){
  switch(move){
    case 0:swap(Cube.center[16],Cube.center[19]);swap(Cube.center[16],Cube.center[18]);swap(Cube.center[16],Cube.center[17]);
      swap(Cube.corner[6],Cube.corner[16]);swap(Cube.corner[6],Cube.corner[21]);swap(Cube.corner[6],Cube.corner[15]);swap(Cube.corner[7],Cube.corner[17]);swap(Cube.corner[7],Cube.corner[20]);swap(Cube.corner[7],Cube.corner[14]);
      swap(Cube.edge[0],Cube.edge[22]);swap(Cube.edge[0],Cube.edge[12]);swap(Cube.edge[0],Cube.edge[10]);swap(Cube.edge[1],Cube.edge[23]);swap(Cube.edge[1],Cube.edge[14]);swap(Cube.edge[1],Cube.edge[11]);swap(Cube.edge[2],Cube.edge[21]);swap(Cube.edge[2],Cube.edge[13]);swap(Cube.edge[2],Cube.edge[9]);
      break;
    case 1:swap(Cube.center[16],Cube.center[18]);swap(Cube.center[17],Cube.center[19]);
      swap(Cube.corner[6],Cube.corner[21]);swap(Cube.corner[7],Cube.corner[20]);swap(Cube.corner[14],Cube.corner[17]);swap(Cube.corner[15],Cube.corner[16]);
      swap(Cube.edge[0],Cube.edge[12]);swap(Cube.edge[1],Cube.edge[14]);swap(Cube.edge[2],Cube.edge[13]);swap(Cube.edge[9],Cube.edge[21]);swap(Cube.edge[10],Cube.edge[22]);swap(Cube.edge[11],Cube.edge[23]);
      break;
    case 2:swap(Cube.center[16],Cube.center[17]);swap(Cube.center[16],Cube.center[18]);swap(Cube.center[16],Cube.center[19]);
      swap(Cube.corner[6],Cube.corner[15]);swap(Cube.corner[6],Cube.corner[21]);swap(Cube.corner[6],Cube.corner[16]);swap(Cube.corner[7],Cube.corner[14]);swap(Cube.corner[7],Cube.corner[20]);swap(Cube.corner[7],Cube.corner[17]);
      swap(Cube.edge[0],Cube.edge[10]);swap(Cube.edge[0],Cube.edge[12]);swap(Cube.edge[0],Cube.edge[22]);swap(Cube.edge[1],Cube.edge[11]);swap(Cube.edge[1],Cube.edge[14]);swap(Cube.edge[1],Cube.edge[23]);swap(Cube.edge[2],Cube.edge[9]);swap(Cube.edge[2],Cube.edge[13]);swap(Cube.edge[2],Cube.edge[21]);
      break;
    case 3:swap(Cube.center[0],Cube.center[12]);swap(Cube.center[0],Cube.center[8]);swap(Cube.center[0],Cube.center[4]);swap(Cube.center[3],Cube.center[15]);swap(Cube.center[3],Cube.center[11]);swap(Cube.center[3],Cube.center[7]);
      swap(Cube.corner[0],Cube.corner[10]);swap(Cube.corner[0],Cube.corner[8]);swap(Cube.corner[0],Cube.corner[5]);
      break;
    case 4:swap(Cube.center[0],Cube.center[8]);swap(Cube.center[3],Cube.center[11]);swap(Cube.center[4],Cube.center[12]);swap(Cube.center[7],Cube.center[15]);
      swap(Cube.corner[0],Cube.corner[8]);swap(Cube.corner[5],Cube.corner[10]);
      break;
    case 5:swap(Cube.center[0],Cube.center[4]);swap(Cube.center[0],Cube.center[8]);swap(Cube.center[0],Cube.center[12]);swap(Cube.center[3],Cube.center[7]);swap(Cube.center[3],Cube.center[11]);swap(Cube.center[3],Cube.center[15]);
      swap(Cube.corner[0],Cube.corner[5]);swap(Cube.corner[0],Cube.corner[8]);swap(Cube.corner[0],Cube.corner[10]);
      break;
    case 6:swap(Cube.center[1],Cube.center[13]);swap(Cube.center[1],Cube.center[9]);swap(Cube.center[1],Cube.center[5]);swap(Cube.center[2],Cube.center[14]);swap(Cube.center[2],Cube.center[10]);swap(Cube.center[2],Cube.center[6]);
      swap(Cube.corner[1],Cube.corner[11]);swap(Cube.corner[1],Cube.corner[9]);swap(Cube.corner[1],Cube.corner[4]);
      break;
    case 7:swap(Cube.center[1],Cube.center[9]);swap(Cube.center[2],Cube.center[10]);swap(Cube.center[5],Cube.center[13]);swap(Cube.center[6],Cube.center[14]);
      swap(Cube.corner[1],Cube.corner[9]);swap(Cube.corner[4],Cube.corner[11]);
      break;
    case 8:swap(Cube.center[1],Cube.center[5]);swap(Cube.center[1],Cube.center[9]);swap(Cube.center[1],Cube.center[13]);swap(Cube.center[2],Cube.center[6]);swap(Cube.center[2],Cube.center[10]);swap(Cube.center[2],Cube.center[14]);
      swap(Cube.corner[1],Cube.corner[4]);swap(Cube.corner[1],Cube.corner[9]);swap(Cube.corner[1],Cube.corner[11]);
      break;
    case 9:swap(Cube.center[20],Cube.center[21]);swap(Cube.center[20],Cube.center[22]);swap(Cube.center[20],Cube.center[23]);
      swap(Cube.corner[2],Cube.corner[19]);swap(Cube.corner[2],Cube.corner[22]);swap(Cube.corner[2],Cube.corner[12]);swap(Cube.corner[3],Cube.corner[18]);swap(Cube.corner[3],Cube.corner[23]);swap(Cube.corner[3],Cube.corner[13]);
      swap(Cube.edge[3],Cube.edge[20]);swap(Cube.edge[3],Cube.edge[15]);swap(Cube.edge[3],Cube.edge[8]);swap(Cube.edge[4],Cube.edge[18]);swap(Cube.edge[4],Cube.edge[16]);swap(Cube.edge[4],Cube.edge[6]);swap(Cube.edge[5],Cube.edge[19]);swap(Cube.edge[5],Cube.edge[17]);swap(Cube.edge[5],Cube.edge[7]);
      break;
    case 10:swap(Cube.center[20],Cube.center[22]);swap(Cube.center[21],Cube.center[23]);
      swap(Cube.corner[2],Cube.corner[22]);swap(Cube.corner[3],Cube.corner[23]);swap(Cube.corner[12],Cube.corner[19]);swap(Cube.corner[13],Cube.corner[18]);
      swap(Cube.edge[3],Cube.edge[15]);swap(Cube.edge[4],Cube.edge[16]);swap(Cube.edge[5],Cube.edge[17]);swap(Cube.edge[6],Cube.edge[18]);swap(Cube.edge[7],Cube.edge[19]);swap(Cube.edge[8],Cube.edge[20]);
      break;
    case 11:swap(Cube.center[20],Cube.center[23]);swap(Cube.center[20],Cube.center[22]);swap(Cube.center[20],Cube.center[21]);
      swap(Cube.corner[2],Cube.corner[12]);swap(Cube.corner[2],Cube.corner[22]);swap(Cube.corner[2],Cube.corner[19]);swap(Cube.corner[3],Cube.corner[13]);swap(Cube.corner[3],Cube.corner[23]);swap(Cube.corner[3],Cube.corner[18]);
      swap(Cube.edge[3],Cube.edge[8]);swap(Cube.edge[3],Cube.edge[15]);swap(Cube.edge[3],Cube.edge[20]);swap(Cube.edge[4],Cube.edge[6]);swap(Cube.edge[4],Cube.edge[16]);swap(Cube.edge[4],Cube.edge[18]);swap(Cube.edge[5],Cube.edge[7]);swap(Cube.edge[5],Cube.edge[17]);swap(Cube.edge[5],Cube.edge[19]);
      break;
    case 12:swap(Cube.center[12],Cube.center[15]);swap(Cube.center[12],Cube.center[14]);swap(Cube.center[12],Cube.center[13]);
      swap(Cube.corner[0],Cube.corner[18]);swap(Cube.corner[0],Cube.corner[11]);swap(Cube.corner[0],Cube.corner[17]);swap(Cube.corner[1],Cube.corner[19]);swap(Cube.corner[1],Cube.corner[10]);swap(Cube.corner[1],Cube.corner[16]);
      swap(Cube.edge[0],Cube.edge[5]);swap(Cube.edge[0],Cube.edge[18]);swap(Cube.edge[0],Cube.edge[23]);swap(Cube.edge[1],Cube.edge[3]);swap(Cube.edge[1],Cube.edge[19]);swap(Cube.edge[1],Cube.edge[21]);swap(Cube.edge[2],Cube.edge[4]);swap(Cube.edge[2],Cube.edge[20]);swap(Cube.edge[2],Cube.edge[22]);
      break;
    case 13:swap(Cube.center[12],Cube.center[14]);swap(Cube.center[13],Cube.center[15]);
      swap(Cube.corner[0],Cube.corner[11]);swap(Cube.corner[1],Cube.corner[10]);swap(Cube.corner[16],Cube.corner[19]);swap(Cube.corner[17],Cube.corner[18]);
      swap(Cube.edge[0],Cube.edge[18]);swap(Cube.edge[1],Cube.edge[19]);swap(Cube.edge[2],Cube.edge[20]);swap(Cube.edge[3],Cube.edge[21]);swap(Cube.edge[4],Cube.edge[22]);swap(Cube.edge[5],Cube.edge[23]);
      break;
    case 14:swap(Cube.center[12],Cube.center[13]);swap(Cube.center[12],Cube.center[14]);swap(Cube.center[12],Cube.center[15]);
      swap(Cube.corner[0],Cube.corner[17]);swap(Cube.corner[0],Cube.corner[11]);swap(Cube.corner[0],Cube.corner[18]);swap(Cube.corner[1],Cube.corner[16]);swap(Cube.corner[1],Cube.corner[10]);swap(Cube.corner[1],Cube.corner[19]);
      swap(Cube.edge[0],Cube.edge[23]);swap(Cube.edge[0],Cube.edge[18]);swap(Cube.edge[0],Cube.edge[5]);swap(Cube.edge[1],Cube.edge[21]);swap(Cube.edge[1],Cube.edge[19]);swap(Cube.edge[1],Cube.edge[3]);swap(Cube.edge[2],Cube.edge[22]);swap(Cube.edge[2],Cube.edge[20]);swap(Cube.edge[2],Cube.edge[4]);
      break;
    case 15:swap(Cube.center[0],Cube.center[20]);swap(Cube.center[0],Cube.center[10]);swap(Cube.center[0],Cube.center[16]);swap(Cube.center[1],Cube.center[21]);swap(Cube.center[1],Cube.center[11]);swap(Cube.center[1],Cube.center[17]);
      swap(Cube.corner[2],Cube.corner[23]);swap(Cube.corner[2],Cube.corner[21]);swap(Cube.corner[2],Cube.corner[7]);
      break;
    case 16:swap(Cube.center[0],Cube.center[10]);swap(Cube.center[1],Cube.center[11]);swap(Cube.center[16],Cube.center[20]);swap(Cube.center[17],Cube.center[21]);
      swap(Cube.corner[2],Cube.corner[21]);swap(Cube.corner[7],Cube.corner[23]);
      break;
    case 17:swap(Cube.center[0],Cube.center[16]);swap(Cube.center[0],Cube.center[10]);swap(Cube.center[0],Cube.center[20]);swap(Cube.center[1],Cube.center[17]);swap(Cube.center[1],Cube.center[11]);swap(Cube.center[1],Cube.center[21]);
      swap(Cube.corner[2],Cube.corner[7]);swap(Cube.corner[2],Cube.corner[21]);swap(Cube.corner[2],Cube.corner[23]);
      break;
    case 18:swap(Cube.center[2],Cube.center[22]);swap(Cube.center[2],Cube.center[8]);swap(Cube.center[2],Cube.center[18]);swap(Cube.center[3],Cube.center[23]);swap(Cube.center[3],Cube.center[9]);swap(Cube.center[3],Cube.center[19]);
      swap(Cube.corner[3],Cube.corner[22]);swap(Cube.corner[3],Cube.corner[20]);swap(Cube.corner[3],Cube.corner[6]);
      break;
    case 19:swap(Cube.center[2],Cube.center[8]);swap(Cube.center[3],Cube.center[9]);swap(Cube.center[18],Cube.center[22]);swap(Cube.center[19],Cube.center[23]);
      swap(Cube.corner[3],Cube.corner[20]);swap(Cube.corner[6],Cube.corner[22]);
      break;
    case 20:swap(Cube.center[2],Cube.center[18]);swap(Cube.center[2],Cube.center[8]);swap(Cube.center[2],Cube.center[22]);swap(Cube.center[3],Cube.center[19]);swap(Cube.center[3],Cube.center[9]);swap(Cube.center[3],Cube.center[23]);
      swap(Cube.corner[3],Cube.corner[6]);swap(Cube.corner[3],Cube.corner[20]);swap(Cube.corner[3],Cube.corner[22]);
      break;
    case 21:swap(Cube.center[4],Cube.center[5]);swap(Cube.center[4],Cube.center[6]);swap(Cube.center[4],Cube.center[7]);
      swap(Cube.corner[4],Cube.corner[13]);swap(Cube.corner[4],Cube.corner[8]);swap(Cube.corner[4],Cube.corner[14]);swap(Cube.corner[5],Cube.corner[12]);swap(Cube.corner[5],Cube.corner[9]);swap(Cube.corner[5],Cube.corner[15]);
      swap(Cube.edge[6],Cube.edge[17]);swap(Cube.edge[6],Cube.edge[12]);swap(Cube.edge[6],Cube.edge[11]);swap(Cube.edge[7],Cube.edge[15]);swap(Cube.edge[7],Cube.edge[14]);swap(Cube.edge[7],Cube.edge[9]);swap(Cube.edge[8],Cube.edge[16]);swap(Cube.edge[8],Cube.edge[13]);swap(Cube.edge[8],Cube.edge[10]);
      break;
    case 22:swap(Cube.center[4],Cube.center[6]);swap(Cube.center[5],Cube.center[7]);
      swap(Cube.corner[4],Cube.corner[8]);swap(Cube.corner[5],Cube.corner[9]);swap(Cube.corner[12],Cube.corner[15]);swap(Cube.corner[13],Cube.corner[14]);
      swap(Cube.edge[6],Cube.edge[12]);swap(Cube.edge[7],Cube.edge[14]);swap(Cube.edge[8],Cube.edge[13]);swap(Cube.edge[9],Cube.edge[15]);swap(Cube.edge[10],Cube.edge[16]);swap(Cube.edge[11],Cube.edge[17]);
      break;
    case 23:swap(Cube.center[4],Cube.center[7]);swap(Cube.center[4],Cube.center[6]);swap(Cube.center[4],Cube.center[5]);
      swap(Cube.corner[4],Cube.corner[14]);swap(Cube.corner[4],Cube.corner[8]);swap(Cube.corner[4],Cube.corner[13]);swap(Cube.corner[5],Cube.corner[15]);swap(Cube.corner[5],Cube.corner[9]);swap(Cube.corner[5],Cube.corner[12]);
      swap(Cube.edge[6],Cube.edge[11]);swap(Cube.edge[6],Cube.edge[12]);swap(Cube.edge[6],Cube.edge[17]);swap(Cube.edge[7],Cube.edge[9]);swap(Cube.edge[7],Cube.edge[14]);swap(Cube.edge[7],Cube.edge[15]);swap(Cube.edge[8],Cube.edge[10]);swap(Cube.edge[8],Cube.edge[13]);swap(Cube.edge[8],Cube.edge[16]);
      break;
    case 24:swap(Cube.center[0],Cube.center[3]);swap(Cube.center[0],Cube.center[2]);swap(Cube.center[0],Cube.center[1]);
      swap(Cube.corner[0],Cube.corner[6]);swap(Cube.corner[0],Cube.corner[4]);swap(Cube.corner[0],Cube.corner[2]);swap(Cube.corner[1],Cube.corner[7]);swap(Cube.corner[1],Cube.corner[5]);swap(Cube.corner[1],Cube.corner[3]);
      swap(Cube.edge[0],Cube.edge[9]);swap(Cube.edge[0],Cube.edge[6]);swap(Cube.edge[0],Cube.edge[3]);swap(Cube.edge[1],Cube.edge[10]);swap(Cube.edge[1],Cube.edge[7]);swap(Cube.edge[1],Cube.edge[4]);swap(Cube.edge[2],Cube.edge[11]);swap(Cube.edge[2],Cube.edge[8]);swap(Cube.edge[2],Cube.edge[5]);
      break;
    case 25:swap(Cube.center[0],Cube.center[2]);swap(Cube.center[1],Cube.center[3]);
      swap(Cube.corner[0],Cube.corner[4]);swap(Cube.corner[1],Cube.corner[5]);swap(Cube.corner[2],Cube.corner[6]);swap(Cube.corner[3],Cube.corner[7]);
      swap(Cube.edge[0],Cube.edge[6]);swap(Cube.edge[1],Cube.edge[7]);swap(Cube.edge[2],Cube.edge[8]);swap(Cube.edge[3],Cube.edge[9]);swap(Cube.edge[4],Cube.edge[10]);swap(Cube.edge[5],Cube.edge[11]);
      break;
    case 26:swap(Cube.center[0],Cube.center[1]);swap(Cube.center[0],Cube.center[2]);swap(Cube.center[0],Cube.center[3]);
      swap(Cube.corner[0],Cube.corner[2]);swap(Cube.corner[0],Cube.corner[4]);swap(Cube.corner[0],Cube.corner[6]);swap(Cube.corner[1],Cube.corner[3]);swap(Cube.corner[1],Cube.corner[5]);swap(Cube.corner[1],Cube.corner[7]);
      swap(Cube.edge[0],Cube.edge[3]);swap(Cube.edge[0],Cube.edge[6]);swap(Cube.edge[0],Cube.edge[9]);swap(Cube.edge[1],Cube.edge[4]);swap(Cube.edge[1],Cube.edge[7]);swap(Cube.edge[1],Cube.edge[10]);swap(Cube.edge[2],Cube.edge[5]);swap(Cube.edge[2],Cube.edge[8]);swap(Cube.edge[2],Cube.edge[11]);
      break;
    case 27:swap(Cube.center[4],Cube.center[23]);swap(Cube.center[4],Cube.center[14]);swap(Cube.center[4],Cube.center[17]);swap(Cube.center[5],Cube.center[20]);swap(Cube.center[5],Cube.center[15]);swap(Cube.center[5],Cube.center[18]);
      swap(Cube.corner[12],Cube.corner[18]);swap(Cube.corner[12],Cube.corner[16]);swap(Cube.corner[12],Cube.corner[14]);
      break;
    case 28:swap(Cube.center[4],Cube.center[14]);swap(Cube.center[5],Cube.center[15]);swap(Cube.center[17],Cube.center[23]);swap(Cube.center[18],Cube.center[20]);
      swap(Cube.corner[12],Cube.corner[16]);swap(Cube.corner[14],Cube.corner[18]);
      break;
    case 29:swap(Cube.center[4],Cube.center[17]);swap(Cube.center[4],Cube.center[14]);swap(Cube.center[4],Cube.center[23]);swap(Cube.center[5],Cube.center[18]);swap(Cube.center[5],Cube.center[15]);swap(Cube.center[5],Cube.center[20]);
      swap(Cube.corner[12],Cube.corner[14]);swap(Cube.corner[12],Cube.corner[16]);swap(Cube.corner[12],Cube.corner[18]);
      break;
    case 30:swap(Cube.center[6],Cube.center[21]);swap(Cube.center[6],Cube.center[12]);swap(Cube.center[6],Cube.center[19]);swap(Cube.center[7],Cube.center[22]);swap(Cube.center[7],Cube.center[13]);swap(Cube.center[7],Cube.center[16]);
      swap(Cube.corner[13],Cube.corner[19]);swap(Cube.corner[13],Cube.corner[17]);swap(Cube.corner[13],Cube.corner[15]);
      break;
    case 31:swap(Cube.center[6],Cube.center[12]);swap(Cube.center[7],Cube.center[13]);swap(Cube.center[16],Cube.center[22]);swap(Cube.center[19],Cube.center[21]);
      swap(Cube.corner[13],Cube.corner[17]);swap(Cube.corner[15],Cube.corner[19]);
      break;
    case 32:swap(Cube.center[6],Cube.center[19]);swap(Cube.center[6],Cube.center[12]);swap(Cube.center[6],Cube.center[21]);swap(Cube.center[7],Cube.center[16]);swap(Cube.center[7],Cube.center[13]);swap(Cube.center[7],Cube.center[22]);
      swap(Cube.corner[13],Cube.corner[15]);swap(Cube.corner[13],Cube.corner[17]);swap(Cube.corner[13],Cube.corner[19]);
      break;
    case 33:swap(Cube.center[8],Cube.center[9]);swap(Cube.center[8],Cube.center[10]);swap(Cube.center[8],Cube.center[11]);
      swap(Cube.corner[8],Cube.corner[22]);swap(Cube.corner[8],Cube.corner[11]);swap(Cube.corner[8],Cube.corner[21]);swap(Cube.corner[9],Cube.corner[23]);swap(Cube.corner[9],Cube.corner[10]);swap(Cube.corner[9],Cube.corner[20]);
      swap(Cube.edge[12],Cube.edge[15]);swap(Cube.edge[12],Cube.edge[18]);swap(Cube.edge[12],Cube.edge[21]);swap(Cube.edge[13],Cube.edge[17]);swap(Cube.edge[13],Cube.edge[20]);swap(Cube.edge[13],Cube.edge[23]);swap(Cube.edge[14],Cube.edge[16]);swap(Cube.edge[14],Cube.edge[19]);swap(Cube.edge[14],Cube.edge[22]);
      break;
    case 34:swap(Cube.center[8],Cube.center[10]);swap(Cube.center[9],Cube.center[11]);
      swap(Cube.corner[8],Cube.corner[11]);swap(Cube.corner[9],Cube.corner[10]);swap(Cube.corner[20],Cube.corner[23]);swap(Cube.corner[21],Cube.corner[22]);
      swap(Cube.edge[12],Cube.edge[18]);swap(Cube.edge[13],Cube.edge[20]);swap(Cube.edge[14],Cube.edge[19]);swap(Cube.edge[15],Cube.edge[21]);swap(Cube.edge[16],Cube.edge[22]);swap(Cube.edge[17],Cube.edge[23]);
      break;
    case 35:swap(Cube.center[8],Cube.center[11]);swap(Cube.center[8],Cube.center[10]);swap(Cube.center[8],Cube.center[9]);
      swap(Cube.corner[8],Cube.corner[21]);swap(Cube.corner[8],Cube.corner[11]);swap(Cube.corner[8],Cube.corner[22]);swap(Cube.corner[9],Cube.corner[20]);swap(Cube.corner[9],Cube.corner[10]);swap(Cube.corner[9],Cube.corner[23]);
      swap(Cube.edge[12],Cube.edge[21]);swap(Cube.edge[12],Cube.edge[18]);swap(Cube.edge[12],Cube.edge[15]);swap(Cube.edge[13],Cube.edge[23]);swap(Cube.edge[13],Cube.edge[20]);swap(Cube.edge[13],Cube.edge[17]);swap(Cube.edge[14],Cube.edge[22]);swap(Cube.edge[14],Cube.edge[19]);swap(Cube.edge[14],Cube.edge[16]);
      break;
  }
  return Cube;
}


cube movecube0(cube Cube,uint8_t move){
  for(int i=0;i<7;i++)
    Cube.edge[i]=edgemove[edgemap[move]][Cube.edge[i]];
  for(int i=0;i<24;i++){
    Cube.center[i]=centermove[move][Cube.center[i]];
    Cube.corner[i]=cornermove[move][Cube.corner[i]];
  }
  return Cube;
}


bool solved(cube Cube){
/*  return Cube.edge==..&&
    Cube.center[0]==..&&Cube.center[1]==..&&Cube.center[2]==..&&
    Cube.corner[0]==..&&Cube.corner[1]==..&&Cube.corner[2]==..;*/
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
