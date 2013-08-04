unsigned char* solve(unsigned char* Input){
  unsigned char* Position;Position=unsigned char malloc(2147483648);	//2Gigs, really necessary?
  unsigned char* Posbegin=Position,Postmp=Position;
  for(unsigned char i=0;i<55;i++)*(Position+i)=*(Input+i);	//copy the original position in.
  *(Position+55)=36;                                    //add a "zero" move to starting position
  unsigned char* Posend=Position+56;		
  unsigned char Depth=max(Position);                    //set Depth to first minimum.	//correct function call?
  for (unsigned char i=0;i<22;i++){                     //add the 23 remaining symmetric positions (cuberturns)
    turncube(Postmp,Posend,i);
    *(Posend+55)=37+i;
    unsigned char tmp=max(Posend);if(Depth>tmp)Depth=tmp;	//and now select the global minimum
    Posend+=56;}
  cout << "initialization done! \n";

  do{							//set the tmp-var to the beginning and the pointers
    for(unsigned char i=0;i<55;i++)*(Position+i)=*(Input+i);	//and the origininal position again
    Posend
    for(unsigned char i=0;i<22;i++){
      turncube(Position,Posend,i);*(Posend+55)=37+i;Posend+=56;}
    Posbegin=Posend;tmp=1;		//for the boundaries of the new depth "empty".
    for(;tmp<=Depth;tmp++){					//go trough all the moves one by one
      for(Postmp=Position;Postmp<Posbegin;Postmp+=55+Depth){		//56?
  //      if(i>1)tmp=*(((Postmp+55+Depth)/3)*3);else tmp=36;	//truncate to a number divisible by 3	//optimization to be done later
        for(unsigned char i=0,i<36,i++){
  	  movecube(Postmp,Posend,i);
  	  if(max(Posend)+tmp<=Depth){			//if it fullfills the heuristic write to the end of memory;
  	    Posend+=55;Postmp+=55;	//there might be one move missing.
            for (unsigned char j=0;j<Depth;j++) *(Posend+j)=*(Postmp+j);	//Don't forget to copy the moves as well.
            Posend+=Depth;Postmp+=Depth;*Posend=i;Posend++;
  	  }
        }
      }
      //copy stuff back and set the new boundaries.
    }
    Depth++;						//at this point depth does count the rotation move
  }while(Posend-Posbegin==0)				//repeat as long as there is no solution.

  unsigned char *back;back=(unsigned char*) malloc(1+Depth*(Posend-Posbegin)/(Depth+55));
  *back=Depth;
  for (int i=0;i<(Posend-Posbegin)/(Depth+55);i++){
    for (int j=0;j<=Depth;j++)*(back+1+i*Depth+j)=*(Posbegin+i*(Depth+55)+j+55);
  }
  free(Position);	//cleanup; number of solutions*length of solutions.
  return back;
}
