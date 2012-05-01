void getcenters() {
 centers = (unsigned char*) malloc(centersize);
 if(!LoadFile(centers,"centers",centersize)) {
   for(int i=0;i<centersize;i++) *(centers+i) = 255;
 }
}

void getedges() {
  edges   = (unsigned char*) malloc(edgesize);
  if(!LoadFile(edges,"edges",edgesize)) {
    *edges=240;
    for(int i=1;i<edgesize;i++) *(edges+i) = 255;
    unsigned char depth=0;
    unsigned char* tmpbegin=(unsigned char*) malloc(1000000);
    unsigned char* tmptmp=tmpbegin;
    for(int i=0;i<7;i++) {
      *tmptmp= 3i;
      tmptmp++;}
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
	  if (depth<readhalfbyte(*(edges+h),h%2)){
	    *(edges+h)=sethalfbyte(*(edges+h),depth,h%2);
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
	for (int i=tmppos-tmpbegin;i>5;i-=7){			//>= oder > ???
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
	tmpend=tmpbegin+tmpend-tmppos;
      }
    }
  }
}

void getcorners() {
 corners = (char*) malloc(cornersize);
 if (!LoadFile(corners,"corners",cornersize)) {
   for(int i=0;i<cornersize;i++) *(corners+i) = 255;	
 }
}
