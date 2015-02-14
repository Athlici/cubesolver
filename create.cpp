uint64_t genpar(uint8_t k,uint8_t l,uint8_t depth){
  uint64_t count = 0;
  for(uint64_t mover=2*l*tablesize[k]/corecount;mover<2*(l+1)*tablesize[k]/corecount;mover++){				//apply moves to all positions in the current depth
    uint8_t mem = readhalfbyte(~table[k][mover/2],mover%2);
      if(depth==1+mem){
        count++;
        uint64_t adr;
        switch(k){
          case 0:
    	adr=adredges(mover);
            for (uint8_t i=0;i<18;i++) {
              uint64_t j=posedges(edgemove[i][(adr>>48)&255],edgemove[i][(adr>>40)&255],edgemove[i][(adr>>32)&255],
    	    edgemove[i][(adr>>24)&255],edgemove[i][(adr>>16)&255],edgemove[i][(adr>>8)&255],edgemove[i][adr&255]);
              if (depth<readhalfbyte(~table[k][j/2],j%2))
                table[k][j/2]=~sethalfbyte(~table[k][j/2],depth,j%2);
            }
            break;
          case 1:
            adr=adrcenters(mover);
            for (uint8_t i=0;i<36;i++){						//PROTIP: at least 3 are actually redundant
    	  uint64_t j=poscenters(centermove[i][(adr>>55)&31],centermove[i][(adr>>50)&31],centermove[i][(adr>>45)&31],centermove[i][(adr>>40)&31],
	    centermove[i][(adr>>35)&31],centermove[i][(adr>>30)&31],centermove[i][(adr>>25)&31],centermove[i][(adr>>20)&31],
    	    centermove[i][(adr>>15)&31],centermove[i][(adr>>10)&31],centermove[i][(adr>>5)&31],centermove[i][adr&31]);
    	  if (depth<readhalfbyte(~table[k][j/2],j%2))				//and look it up int the table + compare
    	    table[k][j/2]=~sethalfbyte(~table[k][j/2],depth,j%2);		//when it is smaller keep it in the next round.
    	}
    	break;
          case 2:
            adr=adrcorners(mover);
            for (uint8_t i=0;i<36;i++) {
              uint64_t j=poscorners(cornermove[i][(adr>>56)&255],cornermove[i][(adr>>48)&255],cornermove[i][(adr>>40)&255],cornermove[i][(adr>>32)&255]
                ,cornermove[i][(adr>>24)&255],cornermove[i][(adr>>16)&255],cornermove[i][(adr>>8)&255],cornermove[i][adr&255]);
              if (depth<readhalfbyte(~table[k][j/2],j%2))
                table[k][j/2]=~sethalfbyte(~table[k][j/2],depth,j%2);
            }
    	break;
      }
    }
  }
  return count;
}

void gentable(uint8_t k) {						//generalized table creation 0→ edges, 1→ centers, 2→ corners

  table[k] = (uint8_t*) calloc(tablesize[k],1);
  FILE* file  = fopen(tablepath[k],"rb");

  if(file!=0){
    fread(table[k],1,tablesize[k],file);
    cout << "loaded " << tablename[k] << " table from disk.\n";
    fclose(file);
  }else{
    uint64_t zeroaddr[3] = {posedges(0,3,6,9,12,15,18),
			    poscenters(0,1,2,3,4,5,6,7,8,9,10,11),
			    poscorners(0,1,5,4,8,9,10,11)};
    table[k][zeroaddr[k]/2]=~sethalfbyte(255,0,zeroaddr[k]%2);                        //The starting Position is set to have depth 0

    cout << "generating " << tablename[k] <<" table.\n";		//little status update

    uint64_t count=1;
    for(uint8_t depth=1;count>0;depth++){
      count=0;
      future<uint64_t> par[corecount];
      for(uint8_t i=0;i<corecount;i++)
        par[i]=async(launch::async,genpar,k,i,depth);
      for(uint8_t i=0;i<corecount;i++)
        par[i].wait();
      for(uint8_t i=0;i<corecount;i++)
        count+=par[i].get();

      cout << count << " positions after depth " << depth-1 << "\n";	//little status update
    }

  FILE* file=fopen(tablepath[k],"wb");
  if(file!=0){
    fwrite(table[k],1,tablesize[k],file);
    fclose(file);
  }
  cout << tablename[k] << " table created\n"; 
  }
}
