unsigned char* solve(unsigned char* Position){
  unsigned char* Posbegin=Position;			//set variables
  unsigned char* Postmp=Position;
  *(Position+55)=36;					//add a "zero" move to starting position
  Position+=56;
  unsigned char* Posend=Position;
  unsigned char Depth=0;				//set Depth to 0
  unsigned char min=255;				//set minimal Depth to max
  for (unsigned char i=0;i<22;i++){			//add the 23 remaining symmetric positions (cuberturns)
    turncube(Postmp,Posend,i);
    *(Posend+55)=37+i;
    Posend+=56;
  }
  while (min>0){					//continue as long as there is no solution found
    Postmp=Posbegin;					//set tmp Variables to go through the Positions
    Position=Posend;
    Depth++;
    while (Postmp<Position){				//go through current depth
      unsigned char tmp;
      if (Depth>2) tmp=*(Postmp+55+Depth)/3*3;		//don't work double on the same position
      else tmp=36;					//(maybe there is a smarter way to do this)(add 1 Byte for the cubemove and then 36?)
      for (unsigned char i=0;i<tmp;i++){		//do all moves till the double ones
	movecube(Postmp,Posend,i);
	Posend+=55;
	Postmp+=55;
	for (unsigned char j=0;j<Depth;j++) *(Posend+j)=*(Postmp+j);
	Posend+=Depth;
	Postmp+=Depth;					//and write to the end of memory
	*Posend=i;
	Posend++;
      }
      for (unsigned char i=tmp+3;i<36;i++){		//the same but for all moves behind the Doubll ones
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
    for (unsigned char* i=Position;i<Postmp;i+=56+Depth){	//value each new position
      unsigned char tmp=42;
/*(edges+posedges(*i,*(i+1),*(i+2),*(i+3),*(i+4),*(i+5),*(i+6)))+	//based on the sum of the lookup tables
//        *(corners+poscorners(*(i+),*(i+),*(i+),*(i+),*(i+),*(i+)))+
//        *(corners+poscorners(*(i+),*(i+),*(i+),*(i+),*(i+),*(i+)))+
//        *(corners+poscorners(*(i+),*(i+),*(i+),*(i+),*(i+),*(i+)))+
//        *(corners+poscorners(*(i+),*(i+),*(i+),*(i+),*(i+),*(i+)))+
        *(centers+poscenters(*(i+31),*(i+32),*(i+33),*(i+34),*(i+39),*(i+40),*(i+41),*(i+42)))+
        *(centers+poscenters(*(i+35),*(i+36),*(i+37),*(i+38),*(i+43),*(i+44),*(i+45),*(i+46)))+
        *(centers+poscenters(*(i+47),*(i+48),*(i+49),*(i+50),*(i+51),*(i+52),*(i+53),*(i+54)));*/
      if(tmp<min){						//and keep only minimal values
	min=tmp;
	Posend=Postmp;
	for (unsigned char j=0;j<56+Depth;j++) *(Posend+j)=*(i+j);
	Posend+=56+Depth;
      }
      else if(tmp==min){
        for (unsigned char j=0;j<56+Depth;j++) *(Posend+j)=*(i+j);
	Posend+=56+Depth; 
	}
    }
    for (int i=0;i<(Posend-Postmp);i+=1) *(Posbegin+i)=*(Postmp+i);	//plain backcopying of the postitions
    Posend=Posbegin-Posend+Postmp;
  }
}
