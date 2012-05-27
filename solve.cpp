unsigned char* solve(unsigned char* Position){
  unsigned char* Posbegin=Position;
  unsigned char* Postmp=Position;
  Position+=55;
  unsigned char* Posend=Position;
  unsigned char Depth=0;
  for (int i=0;i<23;i++){
    movecube(Postmp,Posend,i);
    Posend+=55;
  } 
}
