unsigned char* solve(unsigned char* Position){
  unsigned char* Posbegin=Position;
  unsigned char* Postmp=Position;
  Position+=55;
  unsigned char* Posend=Position;
  unsigned chat Depth=0;
  movecube(Postmp,Posend,move);
  Posend+=55;
  movecube(Postmp,Posend,move);
  Posend+=55;
  movecube(Postmp,Posend,move);
  Posend+=55;
  for (int i=0;i<3;i++){
    movecube(Postmp,Posend,move);
    Posend+=55;Postmp+=55;
    movecube(Postmp,Posend,move);
    Posend+=55;
    movecube(Postmp,Posend,move);
    Posend+=55;
    movecube(Postmp,Posend,move);
    Posend+=55;
  }
  movecube(Postmp,Posend,move);
  Posend+=55;Postmp+=55;
  movecube(Postmp,Posend,move);
  Posend+=55;
  movecube(Postmp,Posend,move);
  Posend+=55;
  movecube(Postmp,Posend,move);
  Posend+=55;
  movecube(Postmp,Posend,move);
  Posend+=55;Postmp+=55;
  movecube(Postmp,Posend,move);
  Posend+=55;
  movecube(Postmp,Posend,move);
  Posend+=55;
  movecube(Postmp,Posend,move);
  Posend+=55;
  
}
