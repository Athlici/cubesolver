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
      unsigned char tmp=*(edges+posedges(*i,*(i+1),*(i+2),*(i+3),*(i+4),*(i+5),*(i+6)))+	//based on the sum of the lookup tables
	    *(corners+poscorners(*(i+7),*(i+8),*(i+9),*(i+10),*(i+11),*(i+12)))+
	    *(corners+poscorners(cornerturn[*(i+13)][],cornerturn[*(i+14)][],
		cornerturn[*(i+15)][2],cornerturn[*(i+16)][2],cornerturn[*(i+17)][2],cornerturn[*(i+18)][2]))+	//14,13,12
	    *(corners+poscorners(cornerturn[*(i+19)][2],cornerturn[*(i+20)][2],
		cornerturn[*(i+21)][1],cornerturn[*(i+22)][1],cornerturn[*(i+23)][1],cornerturn[*(i+24)][1]))+
	    *(corners+poscorners(cornerturn[*(i+25)][1],cornerturn[*(i+26)][1],
		cornerturn[*(i+27)][0],cornerturn[*(i+28)][0],cornerturn[*(i+29)][0],cornerturn[*(i+30)][0]))+
	    *(centers+poscenters(*(i+31),*(i+32),*(i+33),*(i+34),*(i+39),*(i+40),*(i+41),*(i+42)))+
	    *(centers+poscenters(centerturn[*(i+35)][3],centerturn[*(i+36)][3],centerturn[*(i+37)][3],
		centerturn[*(i+38)][3],centerturn[*(i+43)][3],centerturn[*(i+44)][3],centerturn[*(i+45)][3],centerturn[*(i+46)][3]))+
	    *(centers+poscenters(centerturn[*(i+47)][0],centerturn[*(i+48)][0],centerturn[*(i+49)][0],
		centerturn[*(i+50)][0],centerturn[*(i+51)][0],centerturn[*(i+52)][0],centerturn[*(i+53)][0],centerturn[*(i+54)][0]));
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
