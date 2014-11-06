void gentable(uint8_t k) {						//generalized table creation 0→ edges, 1→ centers, 2→ corners

  table[k] = (uint8_t*) calloc(tablesize[k],1);
  FILE* file  = fopen(tablepath[k],"rb");

  if(file!=0){
    fread(table[k],1,tablesize[k],file);
    cout << "loaded " << tablename[k] << " table from disk.\n";
    fclose(file);
  }else{
    uint64_t zeroaddr[3] = {posedges(0,3,6,9,12,15,18),
			    poscenters(0,1,2,3,8,9,10,11),
			    poscorners(0,1,5,4,8,9,10,11)};
    table[k][zeroaddr[k]/2]=~sethalfbyte(255,0,zeroaddr[k]%2);                        //The starting Position is set to have depth 0

    cout << "generating " << tablename[k] <<" table.\n";		//little status update

    uint8_t  depth  = 0;						//setting of the depth counter
    uint8_t *start  = (uint8_t*) malloc(2147483648);	                //allocating the space for the temporary positions(inaccurate estimate)
    uint8_t *posend = start + elemsize[k];
    for(uint8_t i=0;i<elemsize[k];i++)start[i]=elemsol[k][i];
    uint8_t *mover,*depthend;
    
    while (posend>start){
      mover=start;
      depthend=posend;
      depth++;
      while (mover<depthend){						//apply moves to all positions in the current depth
//  for(int i=0;i<elemsize[k];i++)cout << mover[i]+0 << ";"; cout << "\n";
        switch(k){
	  case 0:
            for (uint8_t i=0;i<18;i++) {
              uint8_t  a=edgemove[i][mover[0]],b=edgemove[i][mover[1]];
              uint8_t  c=edgemove[i][mover[2]],d=edgemove[i][mover[3]];
              uint8_t  e=edgemove[i][mover[4]],f=edgemove[i][mover[5]];
              uint8_t  g=edgemove[i][mover[6]];
              uint64_t j=posedges(a,b,c,d,e,f,g);
              if (depth<readhalfbyte(~table[k][j/2],j%2)){
                table[k][j/2]=~sethalfbyte(~table[k][j/2],depth,j%2);
                posend[0]=a;posend[1]=b;
                posend[2]=c;posend[3]=d;
                posend[4]=e;posend[5]=f;
                posend[6]=g;
                posend+=elemsize[k];
              }
            }
            break;
	  case 1:
            for (uint8_t i=0;i<36;i++){						//PROTIP: at least 3 are actually redundant
	      uint8_t  a=centermove[i][mover[0]],b=centermove[i][mover[1]];
              uint8_t  c=centermove[i][mover[2]],d=centermove[i][mover[3]];
              uint8_t  e=centermove[i][mover[4]],f=centermove[i][mover[5]];
              uint8_t  g=centermove[i][mover[6]],h=centermove[i][mover[7]];
	      uint64_t j=poscenters(a,b,c,d,e,f,g,h);				//calculate the depth of the resulting positions
	      if (depth<readhalfbyte(~table[k][j/2],j%2)){			//and look it up int the table + compare
	        table[k][j/2]=~sethalfbyte(~table[k][j/2],depth,j%2);	//when it is smaller keep it in the next round.
	        posend[0]=a;posend[1]=b;
                posend[2]=c;posend[3]=d;
                posend[4]=e;posend[5]=f;
                posend[6]=g;posend[7]=h;
	        posend+=elemsize[k];
	      }
	    }
	    break;
	  case 2:
            for (uint8_t i=0;i<36;i++) {
              uint8_t  a=cornermove[i][mover[0]],b=cornermove[i][mover[1]];
              uint8_t  c=cornermove[i][mover[2]],d=cornermove[i][mover[3]];
              uint8_t  e=cornermove[i][mover[4]],f=cornermove[i][mover[5]];
              uint8_t  g=cornermove[i][mover[6]],h=cornermove[i][mover[7]];
              uint64_t j=poscorners(a,b,c,d,e,f,g,h);
              if (depth<readhalfbyte(~table[k][j/2],j%2)){
                table[k][j/2]=~sethalfbyte(~table[k][j/2],depth,j%2);
                posend[0]=a;posend[1]=b;
                posend[2]=c;posend[3]=d;
                posend[4]=e;posend[5]=f;
                posend[6]=g;posend[7]=h;
                posend+=elemsize[k];
	      }
            }
	    break;
	}
	mover+=elemsize[k];  //go to next Position
      }
      memmove(start,depthend,posend-depthend);
      posend=start+(posend-depthend);
      cout << (posend-start)/elemsize[k] << " positions after depth " << depth+0 << "\n";	//little status update
    }

  FILE* file=fopen(tablepath[k],"wb");
  if(file!=0){
    fwrite(table[k],1,tablesize[k],file);
    fclose(file);
  }
  cout << tablename[k] << " table created\n"; 
  free(start);
  }
}
