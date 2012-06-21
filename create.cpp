void getcenters() {
  centers = (unsigned char*) malloc(centersize);
//  if(!LoadFile(centers,"centers",centersize)) {
    *centers=15;	//to be calculated
    for(int i=1;i<centersize;i++) *(centers+i) = 15;
    cout << "initialized center memory.\n";
    unsigned char depth=0;
    unsigned char* tmpbegin=(unsigned char*) malloc(1000000);
    unsigned char* tmptmp=tmpbegin;
    for(int i=0;i<8;i++) { *tmptmp=i; tmptmp++;}
    unsigned char* tmpend=tmptmp;
    unsigned char* tmppos=tmptmp;
    while (tmpend>tmpbegin){
      tmptmp=tmpbegin;
      tmppos=tmpend;
      depth++;
      while (tmptmp<tmppos){
	for (int i=0;i<36;i++) {
	  unsigned char a=centermove[i][*tmptmp];
	  unsigned char b=centermove[i][*(tmptmp+1)];
          unsigned char c=centermove[i][*(tmptmp+2)];
          unsigned char d=centermove[i][*(tmptmp+3)];
          unsigned char e=centermove[i][*(tmptmp+4)];
          unsigned char f=centermove[i][*(tmptmp+5)];
          unsigned char g=centermove[i][*(tmptmp+6)];
	  unsigned char h=centermove[i][*(tmptmp+7)];
	  tmptmp+=8;
	  int j=poscenters(a,b,c,d,e,f,g,h);
	  if (depth<readhalfbyte(*(centers+j),j%2)){
	    *(centers+i)=sethalfbyte(*(centers+j),depth,j%2);
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
      }
      if (tmpend-tmppos>tmppos-tmpbegin){
	for (int i=tmppos-tmpbegin;i>6;i-=8){
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
      cout << ((tmpend-tmpbegin)>>3) << " positions after depth " << depth+0 << "\n";
    }
//  }
}

void getedges() {
  edges   = (unsigned char*) malloc(edgesize);
//  if(!LoadFile(edges,"edges",edgesize)) {
    *edges=15;
    for(int i=1;i<edgesize;i++) *(edges+i) = 255;
    unsigned char depth=0;
    unsigned char* tmpbegin=(unsigned char*) malloc(1000000);
    unsigned char* tmptmp=tmpbegin;
    for(int i=0;i<7;i++) {*tmptmp= 3*i; tmptmp++;}
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
	  tmptmp+=7;
	  int h=posedges(a,b,c,d,e,f,g);
	  if (depth<readhalfbyte(*(edges+(h>>2)),h%2)){
	    *(edges+h)=sethalfbyte(*(edges+(h>>2)),depth,h%2);
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
    }
      cout << ((tmpend-tmpbegin)>>3) << " positions after depth " << depth+0 << "\n";
//  }
}

void getcorners() {
 corners = (unsigned char*) malloc(cornersize);
//  if(!LoadFile(corners,"corners",cornersize)) {
    *corners=15;
    for(int i=1;i<cornersize;i++) *(corners+i) = 255;
    unsigned char depth=0;
    unsigned char* tmpbegin=(unsigned char*) malloc(1000000);
    unsigned char* tmptmp=tmpbegin;
    for(int i=0;i<6;i++) { *tmptmp=i; tmptmp++;}
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
	  tmptmp+=6;
	  int g=poscorners(a,b,c,d,e,f);
	  if (depth<readhalfbyte(*(corners+(g>>1)),g%2)){
	    *(corners+i)=sethalfbyte(*(corners+(g>>1)),depth,g%2);
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
    }
//  }
}
