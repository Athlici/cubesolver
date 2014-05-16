bool solve(unsigned char* Input,unsigned char Depth/*,unsigned char move*/){	//third attempt, recursive → depth first
  if(Depth>0){			//check necessary conditions	// move is there to reduce redundant moves.
    if(Depth>=max(Input)){
      unsigned char* Position=(unsigned char*) malloc(55);
      for(unsigned char i=0;i<36;i++){
	movecube(Input,Position,i);
	if(solve(Position,Depth-1)){
	  *(solution+Depth-1)=i;free(Position);
	  return true;
	}
      }
      free(Position);
      return false;
    }
    else{return false;}
  }
  else{									//Depth==0
    if(solved(Input)){return true;}
    else{return false;}
  }
}
