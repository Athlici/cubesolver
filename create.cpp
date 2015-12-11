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
      uint64_t buffersize = 235620,coindex = 0;
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
            cotab[k][coaddr+0]=(ind>>28);    //cotab[coaddr]=(int32_t) (ind>>4)
            cotab[k][coaddr+1]=(ind>>20);
            cotab[k][coaddr+2]=(ind>>12);
            cotab[k][coaddr+3]=(ind>>4);
            cotab[k][coaddr+4]=sethalfbyte(d,ind%16,1);
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
    uint64_t zeroaddr[3] = {posedges(0,3,6,9,12,15,18),
#if centercount==8
			    poscenters(0,1,2,3,8,9,10,11),
#else
			    poscenters(0,1,2,3,4,5,6,7,8,9,10,11),
#endif
#if cornercount==6
			    poscorners(0,1,2,3,4,5)
#else
			    poscorners(0,1,5,4,8,9,10,11)
#endif
};
    table[k][zeroaddr[k]/2]=~sethalfbyte(255,0,zeroaddr[k]%2);          //The starting Position is set to have depth 0
    uint64_t (*adrfunc[3])(uint64_t a);
    adrfunc[0]=adredges; adrfunc[1]=adrcenters; adrfunc[2]=adrcorners;
    const uint8_t movespace[3] = {36,36,18};

    cout << "generating " << tablename[k] <<" table.\n";		//little status update

    uint64_t count=1;
    for(uint8_t depth=0;count>0;depth++){
      count=0;
      for(uint64_t mover=0;mover<2*tablesize[k];mover++){		//apply moves to all positions in the current depth
        uint8_t mem = readhalfbyte(~table[k][mover/2],mover%2);
        if(depth==mem){
          count++;
          uint64_t adr=(*adrfunc[k])(mover),j=0;
          for(uint8_t i=0;i<movespace[k];i++){			//some of these moves are redundant, TODO: eliminate by checking depth
            switch(k){
	          case 0:
                j=posedges(edgemove[i][(adr>>48)&255],edgemove[i][(adr>>40)&255],edgemove[i][(adr>>32)&255],
	  	          edgemove[i][(adr>>24)&255],edgemove[i][(adr>>16)&255],edgemove[i][(adr>>8)&255],edgemove[i][adr&255]);
                break;
	          case 1:
#if centercount==8
	            j=poscenters(centermove[i][(adr>>35)&31],centermove[i][(adr>>30)&31],centermove[i][(adr>>25)&31],centermove[i][(adr>>20)&31],
	  	          centermove[i][(adr>>15)&31],centermove[i][(adr>>10)&31],centermove[i][(adr>>5)&31],centermove[i][adr&31]);
#else
                j=poscenters(centermove[i][(adr>>55)&31],centermove[i][(adr>>50)&31],centermove[i][(adr>>45)&31],centermove[i][(adr>>40)&31],
                  centermove[i][(adr>>35)&31],centermove[i][(adr>>30)&31],centermove[i][(adr>>25)&31],centermove[i][(adr>>20)&31],
                  centermove[i][(adr>>15)&31],centermove[i][(adr>>10)&31],centermove[i][(adr>>5)&31],centermove[i][adr&31]);
#endif
	            break;
	          case 2:
#if cornercount==6
                j=poscorners(cornermove[i][(adr>>40)&255],cornermove[i][(adr>>32)&255],cornermove[i][(adr>>24)&255],
	  	          cornermove[i][(adr>>16)&255],cornermove[i][(adr>>8)&255],cornermove[i][adr&255]);
#else
                j=poscorners(cornermove[i][(adr>>56)&255],cornermove[i][(adr>>48)&255],cornermove[i][(adr>>40)&255],cornermove[i][(adr>>32)&255]
                  ,cornermove[i][(adr>>24)&255],cornermove[i][(adr>>16)&255],cornermove[i][(adr>>8)&255],cornermove[i][adr&255]);
#endif
		        break;
            }
            if(depth<readhalfbyte(~table[k][j/2],j%2))
              table[k][j/2]=~sethalfbyte(~table[k][j/2],depth+1,j%2);
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
