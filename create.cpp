void getcenters() {							//documentation just for one because they are very similiar
  centers = (unsigned char*) malloc(centersize);			//allocate the memory for the array

  FILE* pFile;pFile=fopen("centers.bin","rb");
  if(pFile!=0){
    fread(centers,1,centersize,pFile);
    fclose(pFile);
    cout << "loaded center table from disk.\n";
  }else{

    for(int i=0;i<centersize;i++) *(centers+i) = 255;			//everything else is set to max depth
    *(centers+3025/2)=sethalfbyte(255,0,3025%2);                        //The starting Position is set to have depth 0
    cout << "generating center table.\n";				//little status update
    unsigned char depth=0;						//setting of the depth counter
    unsigned char* tmpbegin=(unsigned char*) malloc(2147483648);	//allocating the space for the temporary positions(inaccurate estimate)
    unsigned char* tmptmp=tmpbegin+8;					//just temporary  ??
    *tmpbegin=0;*(tmpbegin+1)=1;*(tmpbegin+2)=2;*(tmpbegin+3)=3; 	//adding starting position to the temporary memory
    *(tmpbegin+4)=8;*(tmpbegin+5)=9;*(tmpbegin+6)=10;*(tmpbegin+7)=11;	//this are two solves opposite center-quads
    //*(tmpbegin+4)=4;*(tmpbegin+5)=5;*(tmpbegin+6)=6;*(tmpbegin+7)=7;	//tmp for testing
    unsigned char* tmpend=tmptmp;					//setting the end of the meaningfull content of the array
    unsigned char* tmppos=tmptmp;
    while (tmpend>tmpbegin){						//continue as long as there are Positions left(while might be wrong)
      tmptmp=tmpbegin;							//set tmp-variable to beginning to let it run through
      tmppos=tmpend;							//set to the last position of the current depth
      depth++;								//increase the depth(too early but works better here)
      while (tmptmp<tmppos){						//do moves as long as you are in the current depth
	for (int i=0;i<36;i++) {					//do all possible moves on it PROTIP: 3 are actually senseless
	  unsigned char a=centermove[i][*tmptmp];
	  unsigned char b=centermove[i][*(tmptmp+1)];
          unsigned char c=centermove[i][*(tmptmp+2)];
          unsigned char d=centermove[i][*(tmptmp+3)];
          unsigned char e=centermove[i][*(tmptmp+4)];
          unsigned char f=centermove[i][*(tmptmp+5)];
          unsigned char g=centermove[i][*(tmptmp+6)];
	  unsigned char h=centermove[i][*(tmptmp+7)];
  //cout <<a+0<<";"<<b+0<<";"<<c+0<<";"<<d+0<<";"<<e+0<<";"<<f+0<<";"<<g+0<<";"<<h+0<<"\n";
	  int j=poscenters(a,b,c,d,e,f,g,h);				//calculate the depth of the resulting positions
	  if (depth<readhalfbyte(*(centers+j/2),j%2)){			//and look it up int the table + compare
	    *(centers+j/2)=sethalfbyte(*(centers+j/2),depth,j%2);	//when it is smaller keep it in the next round.
	    *tmpend=a;
	    *(tmpend+1)=b;
            *(tmpend+2)=c;
            *(tmpend+3)=d;
            *(tmpend+4)=e;
            *(tmpend+5)=f;
            *(tmpend+6)=g;
	    *(tmpend+7)=h;
	    tmpend+=8;
	  }
	}
	tmptmp+=8;
      }
      if (tmpend-tmppos>tmppos-tmpbegin){				//copying functions; 2 cases		(might be replaced by memmove)
	for (int i=tmppos-tmpbegin;i>6;i-=8){				//not everything has to be copied when final area is bigger than given space
	  *(tmppos-i)=*(tmpend-i);
	  *(tmppos-i+1)=*(tmpend-i+1);
          *(tmppos-i+2)=*(tmpend-i+2);
          *(tmppos-i+3)=*(tmpend-i+3);
          *(tmppos-i+4)=*(tmpend-i+4);
          *(tmppos-i+5)=*(tmpend-i+5);
          *(tmppos-i+6)=*(tmpend-i+6);
	  *(tmppos-i+7)=*(tmpend-i+7);
	}
	tmpend=tmpend-tmppos+tmpbegin;
      }
      else{
	for (int i=tmpend-tmppos;i>6;i-=8){
	  *(tmpbegin+i)=*(tmppos+i);
	  *(tmpbegin+i-1)=*(tmppos+i-1);
          *(tmpbegin+i-2)=*(tmppos+i-2);
          *(tmpbegin+i-3)=*(tmppos+i-3);
          *(tmpbegin+i-4)=*(tmppos+i-4);
          *(tmpbegin+i-5)=*(tmppos+i-5);
          *(tmpbegin+i-6)=*(tmppos+i-6);
	  *(tmpbegin+i-7)=*(tmppos+i-7);
	}
	tmpend=tmpbegin-tmppos+tmpend;
      }
      cout << ((tmpend-tmpbegin)>>3) << " positions after depth " << depth+0 << "\n";	//little status update
    }

  FILE* pFile=fopen("centers.bin","wb");
  if(pFile!=0){
    fwrite(centers,1,centersize,pFile);
    fclose(pFile);}
  cout << "center table created\n"; 
  free(tmpbegin);
  }
}

void getedges() {
  edges   = (unsigned char*) malloc(edgesize);

  FILE* pFile;pFile=fopen("edges.bin","rb");
  if(pFile!=0){
    fread(edges,1,edgesize,pFile);
    fclose(pFile);
    cout << "loaded edge table from disk.\n";
  }else{

    *edges=240;
    for(int i=1;i<edgesize;i++) *(edges+i) = 255;
    cout << "initiated edges memory\n";
    unsigned char depth=0;
    unsigned char* tmpbegin=(unsigned char*) malloc(2147483648);
    unsigned char* tmptmp=tmpbegin;
    for(unsigned char i=0;i<7;i++) {*tmptmp= 3*i; tmptmp++;}
    unsigned char* tmpend=tmptmp;
    unsigned char* tmppos=tmptmp;
    while (tmpend>tmpbegin){
      tmptmp=tmpbegin;
      tmppos=tmpend;
      depth++;
      while (tmptmp<tmppos){
	for (int i=0;i<18;i++) {
	  unsigned char a=edgemove[i][*tmptmp];
	  unsigned char b=edgemove[i][*(tmptmp+1)];
          unsigned char c=edgemove[i][*(tmptmp+2)];
          unsigned char d=edgemove[i][*(tmptmp+3)];
          unsigned char e=edgemove[i][*(tmptmp+4)];
          unsigned char f=edgemove[i][*(tmptmp+5)];
          unsigned char g=edgemove[i][*(tmptmp+6)];
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
 for(int i=0;i<10;i++)corners[i] = (unsigned char*) malloc(cornersize/10);
/*
  FILE* pFile;pFile=fopen("corners.bin","rb");
  if(pFile!=0){
    fread(corners,1,cornersize,pFile);
    fclose(pFile);
    cout << "loaded corner table from disk.\n";
  }else{
*/
    *corners[0]=240;
    for(int i=1;i<cornersize;i++) *(corners[i%10]+i/10) = 255;
    unsigned char depth=0;
    unsigned char* tmpbegin=(unsigned char*) malloc(2147483648);
    unsigned char* tmptmp=tmpbegin;
    for(unsigned char i=0;i<8;i++) { *tmptmp=i; tmptmp++;}
    unsigned char* tmpend=tmptmp;
    unsigned char* tmppos=tmptmp;
    while (tmpend>tmpbegin){
      tmptmp=tmpbegin;
      tmppos=tmpend;
      depth++;
      while (tmptmp<tmppos){
	for (int i=0;i<36;i++) {
	  unsigned char a=cornermove[i][*tmptmp];
	  unsigned char b=cornermove[i][*(tmptmp+1)];
          unsigned char c=cornermove[i][*(tmptmp+2)];
          unsigned char d=cornermove[i][*(tmptmp+3)];
          unsigned char e=cornermove[i][*(tmptmp+4)];
          unsigned char f=cornermove[i][*(tmptmp+5)];
          unsigned char g=cornermove[i][*(tmptmp+6)];
          unsigned char h=cornermove[i][*(tmptmp+7)];
	  int j=poscorners(a,b,c,d,e,f,g,h);
	  if (j>cornersize*2)
	    cout << a+0 << ";" << b+0 << ";" << c+0 << ";" << d+0 << ";" << e+0 << ";" << f+0 << ";" << g+0 << ";" << h+0 << "\n";
	  else{
	  if (depth<readhalfbyte(*(corners[(j>>1)%10]+(j>>1)/10),j&1)){
	    *(corners[(j>>1)%10]+(j>>1)/10)=sethalfbyte(*(corners[(j>>1)%10]+(j>>1)/10),depth,j&1);
	    *tmpend=a;
	    *(tmpend+1)=b;
            *(tmpend+2)=c;
            *(tmpend+3)=d;
            *(tmpend+4)=e;
            *(tmpend+5)=f;
            *(tmpend+6)=e;
            *(tmpend+7)=f;
	    tmpend+=8;
	  }
	  }
	}
        tmptmp+=8;
      }
      if (tmpend-tmppos>tmppos-tmpbegin){
	for (int i=tmppos-tmpbegin;i>4;i-=8){
	  *(tmppos-i)=*(tmpend-i);
	  *(tmppos-i+1)=*(tmpend-i+1);
          *(tmppos-i+2)=*(tmpend-i+2);
          *(tmppos-i+3)=*(tmpend-i+3);
          *(tmppos-i+4)=*(tmpend-i+4);
          *(tmppos-i+5)=*(tmpend-i+5);
          *(tmppos-i+6)=*(tmpend-i+6);
          *(tmppos-i+7)=*(tmpend-i+7);
	}
	tmpend=tmpend-tmppos+tmpbegin;
      }
      else{
	for (int i=tmpend-tmppos;i>4;i-=8){
	  *(tmpbegin+i)=*(tmppos+i);
	  *(tmpbegin+i-1)=*(tmppos+i-1);
          *(tmpbegin+i-2)=*(tmppos+i-2);
          *(tmpbegin+i-3)=*(tmppos+i-3);
          *(tmpbegin+i-4)=*(tmppos+i-4);
          *(tmpbegin+i-5)=*(tmppos+i-5);
          *(tmpbegin+i-6)=*(tmppos+i-6);
          *(tmpbegin+i-7)=*(tmppos+i-7);
	}
	tmpend=tmpbegin-tmppos+tmpend;
      }
      cout << ((tmpend-tmpbegin)/8) << " positions after depth " << depth+0 << "\n";
    }
/*
  FILE* pFile=fopen("corners.bin","wb");
  if(pFile!=0){
    fwrite(corners,1,cornersize,pFile);
    fclose(pFile);}
  free(tmpbegin);
  }
*/
}
