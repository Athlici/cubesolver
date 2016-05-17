void gentable(uint8_t k) {						//generalized table creation 0→ edges, 1→ centers, 2→ corners

  FILE* file  = fopen(tablepath[k],"rb");
  if(file!=0){
#if splitcomp==0
    table[k] = (uint8_t*) calloc(tablesize[k],1);
    fread(table[k],1,tablesize[k],file);
#else
    if(k==0){
      table[k] = (uint8_t*) calloc(tablesize[k],1);
      fread(table[k],1,tablesize[k],file);
    }else{
      table[k] = (uint8_t*) calloc(tablesize[k]/2,1);
      cotab[k] = (uint8_t*) calloc(cotabsize[k]*5,1);
      uint64_t buffersize = 102965940,coindex = 0;
      uint8_t *buffer;
      buffer = (uint8_t*) calloc(buffersize,1);
      for(uint64_t i=0;i<tablesize[k]/buffersize;i++){
        fread(buffer,1,buffersize,file);
        for(uint64_t j=0;j<2*buffersize;j++){
          uint8_t t = 0,d = readhalfbyte(~buffer[j/2],j%2);
          uint64_t ind = i*2*buffersize+j;
          if(6<d && d<11)
            t=d-7;
          else{
            uint64_t coaddr=5*nextfree(k,coindex);
            cotab[k][coaddr+0]=(ind>>29);    //cotab[coaddr]=(int32_t) (ind>>4)
            cotab[k][coaddr+1]=(ind>>21);
            cotab[k][coaddr+2]=(ind>>13);
            cotab[k][coaddr+3]=(ind>>5);
            cotab[k][coaddr+4]=((ind%32)<<3)+(d-4*(d==11));
            coindex++;
          }
          table[k][ind/4] = set2bit(table[k][ind/4],t,ind%4);
        }
      }
      free(buffer);
    }
#endif
    cout << "loaded " << tablename[k] << " table from disk.\n";
    fclose(file);
  }else{
    uint64_t zeroaddr[3] = {posedges(0,3,6,9,12,15,18), //get this shit out of here
#if centercount==8
	            		    poscenters(0,1,2,3,8,9,10,11),
#else
			                poscenters(0,1,2,3,4,5,6,7,8,9,10,11),
#endif
#if cornercount==6
			                poscorners(0,1,2,3,4,5)
#else
			                poscorners(0,1,5,4,8,9,10,11)   //fix this with the new arraytables
#endif
};
    table[k][zeroaddr[k]/2]=~sethalfbyte(255,0,zeroaddr[k]%2);          //The starting Position is set to have depth 0
    void (*adrfunc[3])()={&adredges, &adrcenters, &adrcorners};
    void (*posfunc[3])()={&posedges, &poscenters, &poscorners};
    void (*movfunc[3])()={&movedges, &movcenters, &movcorners};
    uint8_t n={7,centercount,cornercount}[k];
    const uint8_t movespace[3] = {36,36,18};

    cout << "generating " << tablename[k] <<" table.\n";		//little status update

    uint64_t count=1;
    for(uint8_t depth=0;count>0;depth++){
      count=0;
      for(uint64_t mover=0;mover<2*tablesize[k];mover++){		//apply moves to all positions in the current depth
        uint8_t mem = readhalfbyte(~table[k][mover/2],mover%2);
        if(depth==mem){
          count++;
          uint8_t current[n],next[n];
          (*adrfunc[k])(current,mover);
          for(uint8_t i=0;i<movespace[k];i++){			//some of these moves are redundant, TODO: eliminate by checking depth
            memcpy(next,current,n);
            (*movfunc[k])(next,i,n);
            uint64_t pos=(*posfunc[k])(next);
            if(depth<readhalfbyte(~table[k][pos/2],pos%2))
              table[k][pos/2]=~sethalfbyte(~table[k][pos/2],depth+1,pos%2);
	      }
	    }
      }
      cout << count << " positions after depth " << depth+0 << "\n";	//little status update
    }

  FILE* file=fopen(tablepath[k],"wb");
  if(file!=0){
    fwrite(table[k],1,tablesize[k],file);
    fclose(file);
  }
  cout << tablename[k] << " table created\n"; 
  }
}
