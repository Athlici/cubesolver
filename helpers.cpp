#define ROT1(a,b,c,d) swap(a,b);swap(c,d);swap(a,c);      //(a b c d)
#define ROT2(a,b,c,d) swap(a,c);swap(b,d);                //(a c)(b d)
#define ROT3(a,b,c,d) swap(a,c);swap(c,d);swap(a,b);      //(d c b a)

#define FourTurn(m,a,b,c,d) \
  case m:                   \
    ROT1(a,b,c,d)           \
    break;                  \
  case m+1:                 \
    ROT2(a,b,c,d)           \
    break;                  \
  case m+2:                 \
    ROT3(a,b,c,d)           \
    break;

#define EightTurn(m,a,b,c,d,e,f,g,h) \
  case m:                            \
    ROT1(a,b,c,d) ROT1(e,f,g,h)      \
    break;                           \
  case m+1:                          \
    ROT2(a,b,c,d) ROT2(e,f,g,h)      \
    break;                           \
  case m+2:                          \
    ROT3(a,b,c,d) ROT3(e,f,g,h)      \
    break;                           \

//the edges are done inconsistently, because orientation is a bitch
void turnedges(uint8_t* addr,const uint8_t move){
  const uint8_t edgemove[18][24] = 
    {{22,23,21,3,4,5,6,7,8,2,0,1,10,9,11,15,16,17,18,19,20,13,12,14},
     {12,14,13,3,4,5,6,7,8,21,22,23,0,2,1,15,16,17,18,19,20,9,10,11},
     {10,11,9,3,4,5,6,7,8,13,12,14,22,21,23,15,16,17,18,19,20,2,0,1},
     {0,1,2,20,18,19,4,5,3,9,10,11,12,13,14,8,6,7,16,17,15,21,22,23},
     {0,1,2,15,16,17,18,19,20,9,10,11,12,13,14,3,4,5,6,7,8,21,22,23},
     {0,1,2,8,6,7,16,17,15,9,10,11,12,13,14,20,18,19,4,5,3,21,22,23},
     {5,3,4,19,20,18,6,7,8,9,10,11,12,13,14,15,16,17,23,21,22,1,2,0},
     {18,19,20,21,22,23,6,7,8,9,10,11,12,13,14,15,16,17,0,1,2,3,4,5},
     {23,21,22,1,2,0,6,7,8,9,10,11,12,13,14,15,16,17,5,3,4,19,20,18},
     {0,1,2,3,4,5,17,15,16,7,8,6,11,10,9,14,13,12,18,19,20,21,22,23},
     {0,1,2,3,4,5,12,14,13,15,16,17,6,8,7,9,10,11,18,19,20,21,22,23},
     {0,1,2,3,4,5,11,9,10,14,13,12,17,16,15,7,8,6,18,19,20,21,22,23},
     {9,10,11,0,1,2,3,4,5,6,7,8,12,13,14,15,16,17,18,19,20,21,22,23},
     {6,7,8,9,10,11,0,1,2,3,4,5,12,13,14,15,16,17,18,19,20,21,22,23},
     {3,4,5,6,7,8,9,10,11,0,1,2,12,13,14,15,16,17,18,19,20,21,22,23},
     {0,1,2,3,4,5,6,7,8,9,10,11,15,17,16,18,19,20,21,22,23,12,14,13},
     {0,1,2,3,4,5,6,7,8,9,10,11,18,20,19,21,22,23,12,14,13,15,16,17},
     {0,1,2,3,4,5,6,7,8,9,10,11,21,23,22,12,14,13,15,16,17,18,19,20}};
  if(move<18)
    for(uint8_t i=0;i<7;i++)
      addr[i]=edgemove[move][addr[i]];
}

void turncenters(uint8_t* addr,const uint8_t move){
  switch(move){
    FourTurn(0,19,18,17,16)   //these could be simplified to rot instructions
    FourTurn(3,20,21,22,23)   //over a uint32, should speed be an issue
    FourTurn(6,15,14,13,12)
    FourTurn(9,4,5,6,7)
    FourTurn(12,3,2,1,0)
    FourTurn(15,8,9,10,11)
    EightTurn(18,12,8,4,0,15,11,7,3)
    EightTurn(21,13,9,5,1,14,10,6,2)
    EightTurn(24,0,20,10,16,1,21,11,17)
    EightTurn(27,2,22,8,18,3,23,9,19)
    EightTurn(30,4,23,14,17,5,20,15,18)
    EightTurn(33,6,21,12,19,7,22,13,16)
  }
}

void turncorners(uint8_t* addr,const uint8_t move){
  switch(move){  //These as well, with a uint64_t respectively
    EightTurn(0,6,16,21,15,7,17,20,14)
    EightTurn(3,2,19,22,12,3,18,23,13)
    EightTurn(6,0,18,11,17,1,19,10,16)
    EightTurn(9,5,12,9,15,4,13,8,14)
    EightTurn(12,7,5,3,1,6,4,2,0)
    EightTurn(15,8,22,11,21,9,23,10,20)
    FourTurn(18,0,10,8,5)
    FourTurn(21,1,11,9,4)
    FourTurn(24,2,23,21,7)
    FourTurn(27,3,22,20,6)
    FourTurn(30,18,16,14,12)
    FourTurn(33,19,17,15,13)
  }
}

cube turncube(cube Cube,const uint8_t move){
  turnedges(Cube.edge,move);
  turncenters(Cube.center,move);
  turncorners(Cube.corner,move);
  return Cube;
}

cube cubeisometrie(cube Cube,const uint8_t move){

}

uint8_t sethalfbyte(const uint8_t &a/*Eingangsbyte*/,const uint8_t &b/*Modifikation*/,const uint8_t &c/*lower(0) or upper half(1)*/){
  return (b<<4*c)|(a&(240-225*c));          //returns the upper part of the byte when c==1 otherwise the lower part
}

uint8_t readhalfbyte(const uint8_t &a/*Eingangsbyte*/,const uint8_t &c/*lower(0) or upper half(1)*/){
  return (a>>4*c)&15;                       //sets the upper part of the byte when c==1 otherwise the lower part
}

#if disktablegen || splitcomp
inline uint8_t set2bit(uint8_t a/*Eingangsbyte*/,uint8_t b/*Modifikation*/,uint8_t c/*which 2bit*/){
      return (b<<2*c)|(a&(255-(3<<2*c)));
}

inline uint8_t read2bit(uint8_t a/*Eingangsbyte*/, uint8_t c/*which 2bit*/){
      return (a>>2*c)&3;
}
#endif
/*
//next two functions are taken from wikipedia, should be optimised to rol in asm
uint32_t rotl32 (uint32_t value, unsigned int count) {
    const unsigned int mask = (CHAR_BIT*sizeof(value)-1);
    count &= mask;
    return (value<<count) | (value>>( (-count) & mask ));
}

uint64_t rotl64 (uint64_t value, unsigned int count) {
    const unsigned int mask = (CHAR_BIT*sizeof(value)-1);
    count &= mask;
    return (value<<count) | (value>>( (-count) & mask ));
}*/

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
