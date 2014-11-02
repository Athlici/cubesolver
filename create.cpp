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
			    poscorners(0,1,2,3,4,5)};
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
              uint64_t j=poscorners(a,b,c,d,e,f);
              if (depth<readhalfbyte(~table[k][j/2],j%2)){
                table[k][j/2]=~sethalfbyte(~table[k][j/2],depth,j%2);
                posend[0]=a;posend[1]=b;
                posend[2]=c;posend[3]=d;
                posend[4]=e;posend[5]=f;
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
/*
void getedges() {
  edges   = (uint8_t*) malloc(edgesize);

  FILE* pFile;pFile=fopen("edges.bin","rb");
  if(pFile!=0){
    fread(edges,1,edgesize,pFile);
    fclose(pFile);
    cout << "loaded edge table from disk.\n";
  }else{

    *edges=240;
    for(int i=1;i<edgesize;i++) *(edges+i) = 255;
    cout << "initiated edges memory\n";
    uint8_t depth=0;
    uint8_t* tmpbegin=(uint8_t*) malloc(2147483648);
    uint8_t* tmptmp=tmpbegin;
    for(uint8_t i=0;i<7;i++) {*tmptmp= 3*i; tmptmp++;}
    uint8_t* tmpend=tmptmp;
    uint8_t* tmppos=tmptmp;
    while (tmpend>tmpbegin){
      tmptmp=tmpbegin;
      tmppos=tmpend;
      depth++;
      while (tmptmp<tmppos){
	for (int i=0;i<18;i++) {
	  uint8_t a=edgemove[i][*tmptmp];
	  uint8_t b=edgemove[i][*(tmptmp+1)];
          uint8_t c=edgemove[i][*(tmptmp+2)];
          uint8_t d=edgemove[i][*(tmptmp+3)];
          uint8_t e=edgemove[i][*(tmptmp+4)];
          uint8_t f=edgemove[i][*(tmptmp+5)];
          uint8_t g=edgemove[i][*(tmptmp+6)];
	  int h=posedges(a,b,c,d,e,f,g);
	  if (depth<readhalfbyte(*(edges+(h>>1)),h&1)){
	    *(edges+(h>>1))=sethalfbyte(*(edges+(h>>1)),depth,h&1);
	    *tmpend=a;
	    *(tmpend+1)=b;
            *(tmpend+2)=c;
            *(tmpend+3)=d;
            *(tmpend+4)=e;
            *(tmpend+5)=f;
            *(tmpend+6)=g;
	    tmpend+=7;
	  }
	}
        tmptmp+=7;
      }
      if (tmpend-tmppos>tmppos-tmpbegin){
	for (int i=tmppos-tmpbegin;i>5;i-=7){
	  *(tmppos-i)=*(tmpend-i);
	  *(tmppos-i+1)=*(tmpend-i+1);
          *(tmppos-i+2)=*(tmpend-i+2);
          *(tmppos-i+3)=*(tmpend-i+3);
          *(tmppos-i+4)=*(tmpend-i+4);
          *(tmppos-i+5)=*(tmpend-i+5);
          *(tmppos-i+6)=*(tmpend-i+6);
	}
	tmpend=tmpend-tmppos+tmpbegin;
      }
      else{
	for (int i=tmpend-tmppos;i>5;i-=7){
	  *(tmpbegin+i)=*(tmppos+i);
	  *(tmpbegin+i-1)=*(tmppos+i-1);
          *(tmpbegin+i-2)=*(tmppos+i-2);
          *(tmpbegin+i-3)=*(tmppos+i-3);
          *(tmpbegin+i-4)=*(tmppos+i-4);
          *(tmpbegin+i-5)=*(tmppos+i-5);
          *(tmpbegin+i-6)=*(tmppos+i-6);
	}
	tmpend=tmpbegin-tmppos+tmpend;
      }
      cout << ((tmpend-tmpbegin)/7) << " positions after depth " << depth+0 << "\n";
  }
  FILE* pFile=fopen("edges.bin","wb");
  if(pFile!=0){
    fwrite(edges,1,edgesize,pFile);
    fclose(pFile);}
  free(tmpbegin);
  }
}

void getcorners() {
 corners = (uint8_t*) malloc(cornersize);

  FILE* pFile;pFile=fopen("corners.bin","rb");
  if(pFile!=0){
    fread(corners,1,cornersize,pFile);
    fclose(pFile);
    cout << "loaded corner table from disk.\n";
  }else{

    *corners=240;
    for(int i=1;i<cornersize;i++) *(corners+i) = 255;
    uint8_t depth=0;
    uint8_t* tmpbegin=(uint8_t*) malloc(2147483648);
    uint8_t* tmptmp=tmpbegin;
    for(uint8_t i=0;i<6;i++) { *tmptmp=i; tmptmp++;}
    uint8_t* tmpend=tmptmp;
    uint8_t* tmppos=tmptmp;
    while (tmpend>tmpbegin){
      tmptmp=tmpbegin;
      tmppos=tmpend;
      depth++;
      while (tmptmp<tmppos){
	for (int i=0;i<36;i++) {
	  uint8_t a=cornermove[i][*tmptmp];
	  uint8_t b=cornermove[i][*(tmptmp+1)];
          uint8_t c=cornermove[i][*(tmptmp+2)];
          uint8_t d=cornermove[i][*(tmptmp+3)];
          uint8_t e=cornermove[i][*(tmptmp+4)];
          uint8_t f=cornermove[i][*(tmptmp+5)];
	  int g=poscorners(a,b,c,d,e,f);
	  if (g>cornersize*2)
	    cout << a+0 << ";" << b+0 << ";" << c+0 << ";" << d+0 << ";" << e+0 << ";" << f+0 << "\n";
	  else{
	  if (depth<readhalfbyte(*(corners+(g>>1)),g&1)){
	    *(corners+(g>>1))=sethalfbyte(*(corners+(g>>1)),depth,g&1);
	    *tmpend=a;
	    *(tmpend+1)=b;
            *(tmpend+2)=c;
            *(tmpend+3)=d;
            *(tmpend+4)=e;
            *(tmpend+5)=f;
	    tmpend+=6;
	  }
	  }
	}
        tmptmp+=6;
      }
      if (tmpend-tmppos>tmppos-tmpbegin){
	for (int i=tmppos-tmpbegin;i>4;i-=6){
	  *(tmppos-i)=*(tmpend-i);
	  *(tmppos-i+1)=*(tmpend-i+1);
          *(tmppos-i+2)=*(tmpend-i+2);
          *(tmppos-i+3)=*(tmpend-i+3);
          *(tmppos-i+4)=*(tmpend-i+4);
          *(tmppos-i+5)=*(tmpend-i+5);
	}
	tmpend=tmpend-tmppos+tmpbegin;
      }
      else{
	for (int i=tmpend-tmppos;i>4;i-=6){
	  *(tmpbegin+i)=*(tmppos+i);
	  *(tmpbegin+i-1)=*(tmppos+i-1);
          *(tmpbegin+i-2)=*(tmppos+i-2);
          *(tmpbegin+i-3)=*(tmppos+i-3);
          *(tmpbegin+i-4)=*(tmppos+i-4);
          *(tmpbegin+i-5)=*(tmppos+i-5);
	}
	tmpend=tmpbegin-tmppos+tmpend;
      }
      cout << ((tmpend-tmpbegin)/6) << " positions after depth " << depth+0 << "\n";
    }
  FILE* pFile=fopen("corners.bin","wb");
  if(pFile!=0){
    fwrite(corners,1,cornersize,pFile);
    fclose(pFile);}
  free(tmpbegin);
  }
}
*/
