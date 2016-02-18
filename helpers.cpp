//I believe the inconsistent notation with regards to shift direction stems from x86 endianness
#define ROT1(a,b,c,d) {swap(a,b);swap(c,d);swap(a,c);}       //(a b c d) in cycle notation
#define ROT2(a,b,c,d) {swap(a,c);swap(b,d)}                  //(a c)(b d) in cycle notation
#define ROT3(a,b,c,d) {swap(a,c);swap(c,d);swap(a,b);}       //(d c b a) in cycle notation
#define CERL(off,dis) *((uint32_t*) cube.center+off) = rotl32(*((uint32_t*) Cube.center+off),dis)
#define CER8

//Write Macros in such a way, that the first 18 moves are given by 6*(cycle,2*cycle,offset)
//and the second 18 by 6*(,cycle,2*cycle)
//maybe store edge orientation and permutation seperately

{{0,1,2,3},{4,5,6,7},{}}

cube turncube (cube Cube,uint8_t move){
  switch(move) {
    case 0:     //U
      *((uint32_t*) Cube.edge  +0) = rotl32(*((uint32_t*) Cube.edge  +0), 8);
      *((uint64_t*) Cube.corner+0) = rotl64(*((uint64_t*) Cube.corner+0),16);
      CERL(0,8);
      break;
    case 1:     //U²
      *((uint32_t*) Cube.edge  +0) = rotl32(*((uint32_t*) Cube.edge  +0),16);
      *((uint64_t*) Cube.corner+0) = rotl64(*((uint64_t*) Cube.corner+0),32);
      CERL(0,16);
      break;
    case 2:     //U'
      *((uint32_t*) Cube.edge  +0) = rotl32(*((uint32_t*) Cube.edge  +0),24);
      *((uint64_t*) Cube.corner+0) = rotl64(*((uint64_t*) Cube.corner+0),48);
      CERL(0,24);
      break;
    case 3:     //D
      *((uint32_t*) Cube.edge  +0) = rotl32(*((uint32_t*) Cube.edge  +4), 8);
      ROT1(Cube.corner[8],Cube.corner[22],Cube.corner[11],Cube.corner[21]);
      ROT1(Cube.corner[9],Cube.corner[23],Cube.corner[10],Cube.corner[20]);
      CERL(8,8);
      break;
    case 4:     //D²
      *((uint32_t*) Cube.edge  +0) = rotl32(*((uint32_t*) Cube.edge  +4),16);
      ROT2(Cube.corner[8],Cube.corner[22],Cube.corner[11],Cube.corner[21]);
      ROT2(Cube.corner[9],Cube.corner[23],Cube.corner[10],Cube.corner[20]);
      CERL(8,16);
      break;
    case 5:     //D'
      *((uint32_t*) Cube.edge  +0) = rotl32(*((uint32_t*) Cube.edge  +4),24);
      ROT3(Cube.corner[8],Cube.corner[22],Cube.corner[11],Cube.corner[21]);
      ROT3(Cube.corner[9],Cube.corner[23],Cube.corner[10],Cube.corner[20]);
      CERL(8,24);
      break;
    case 6:     //L
      break;
    case 7:     //L²
      break;
    case 8:     //L'
      break;
    case 9:     //R
      break;
    case 10:    //R²
      break;
    case 11:    //R'
      break;
    case 12:    //F
      break;
    case 13:    //F²
      break;
    case 14:    //F'
      break;
    case 15:    //B
      break;
    case 16:    //B²
      break;
    case 17:    //B'
      break;
    case 18:    //u
      break;
    case 19:    //u²
      break;
    case 20:    //u'
      break;
    case 21:    //d
      break;
    case 22:    //d²
      break;
    case 23:    //d'
      break;
    case 24:    //l
      break;
    case 25:    //l²
      break;
    case 26:    //l'
      break;
    case 27:    //r
      break;
    case 28:    //r²
      break;
    case 29:    //r'
      break;
    case 30:    //f
      break;
    case 31:    //f²
      break;
    case 32:    //f'
      break;
    case 33:    //b
      break;
    case 34:    //b²
      break;
    case 35:    //b'
      break;
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
    if(Cube.center[i]!=i/6 || Cube.corner[i]!=i) return false;
  
  return true;
}

cube goal(void){
  cube Cube;
  for(int i=0;i<7;i++)
    Cube.edge[i]=3*i;
  for(int i=0;i<24;i++){
    Cube.center[i]=i/6;     //there are only 6 colours
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
