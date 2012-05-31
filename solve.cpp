unsigned char* solve(unsigned char* Position){
  unsigned char* Posbegin=Position;
  unsigned char* Postmp=Position;
  Position+=55;
  *(Position+55)=36;
  unsigned char* Posend=Position;
  unsigned char Depth=0;
  unsigned char min=255;
  for (unsigned char i=0;i<23;i++){
    turncube(Postmp,Posend,i);
    *(Posend+55)=37+i;
    Posend+=56;
  }
  while (min>0){
    Postmp=Posbegin;
    Position=Posend;
    Depth++;
    while (Postmp<Position){
      unsigned char tmp;
      if (Depth>2) tmp=*(Postmp+55+Depth)/3*3;
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
      unsigned char tmp=*(edges+posedges(*i,*(i+1),*(i+2),*(i+3),*(i+4),*(i+5),*(i+6)))+
//        *(corners+poscorners(*(i+7),*(i+8),*(i+9),*(i+10),*(i+15),*(i+16),*(i+17),*(i+18)))+
//        *(corners+poscorners(*(i+11),*(i+12),*(i+13),*(i+14),*(i+19),*(i+20),*(i+21),*(i+22)))+
//        *(corners+poscorners(*(i+23),*(i+24),*(i+25),*(i+26),*(i+27),*(i+28),*(i+29),*(i+30)))+
        *(centers+poscenters(*(i+31),*(i+32),*(i+33),*(i+34),*(i+39),*(i+40),*(i+41),*(i+42)))+
        *(centers+poscenters(*(i+35),*(i+36),*(i+37),*(i+38),*(i+43),*(i+44),*(i+45),*(i+46)))+
        *(centers+poscenters(*(i+47),*(i+48),*(i+49),*(i+50),*(i+51),*(i+52),*(i+53),*(i+54)));
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
    for (int i=0;i<(Posend-Postmp);i+=1) *(Posbegin+i)=*(Postmp+i);
    Posend=Posbegin-Posend+Postmp;
  }
}
