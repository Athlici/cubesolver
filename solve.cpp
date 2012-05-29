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
    Position=Posend;
    while (Postmp<Position){
      unsigned char tmp;
      if (Depth>1) tmp=*(Postmp+54+Depth)/3*3;
      else tmp=36;
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
    }
    Postmp=Posend;
    for (unsigned char* i=Position;i<Postmp;i+=55+Depth){
      unsigned char tmp=calcdepth(i);
      if(tmp<min){
	min=tmp;
	Posend=Postmp;
	for (unsigned char j=0;j<55+Depth;j++) *(Posend+j)=*(i+j);
	Posend+=55+Depth;
      }
      else if(tmp==min){
        for (unsigned char j=0;j<55+Depth;j++) *(Posend+j)=*(i+j);
	Posend+=55+Depth; 
	}
    }
    Depth++;
  }
}
