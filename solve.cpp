unsigned char* solve(unsigned char* Position){
  unsigned char* Posbegin=Position;
  unsigned char* Postmp=Position;
  Position+=55;
  *(Position+55)=36;
  unsigned char* Posend=Position;
  unsigned char Depth=1;
  unsigned char min=255;
  for (unsigned char i=0;i<23;i++){
    turncube(Postmp,Posend,i);
    *(Posend+55)=37+i;
    Posend+=56;
  }
  while (min>0){
    Postmp=Posbegin;
    Postion=Posend;
    while (Postmp<Position){
      if (Depth>1) unsigned char tmp=*(Postmp+54+Depth)/3*3;
      else unsigned char tmp=36;
      for (unsigned char i=0;i<tmp;i++){
	movecube(Postmp,Posend,i);
	Posend+=55;
	Postmp+=55;
	for (unsigned char j=0;j<Depth;j++) *(Posend+j)=*(Postmp+j);
	Posend+=Depth;
	Postmp+=Depth;
	*Posend=i;
	Posend++;
      }
      for (unsigned char i=tmp+3;i<36;i++){
        movecube(Postmp,Posend,i);
        Posend+=55;
        Postmp+=55;
        for (unsigned char j=0;j<Depth;j++) *(Posend+j)=*(Postmp+j);
        Posend+=Depth;
        Postmp+=Depth;
        *Posend=i;
        Posend++;
      }
    //...
    }
  }
}
