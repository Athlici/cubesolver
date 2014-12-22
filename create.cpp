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
    cout << zeroaddr[0]+0 << ";" << zeroaddr[1]+0 << ";" << zeroaddr[2]+0 << "\n";
    table[k][zeroaddr[k]/2]=~sethalfbyte(255,0,zeroaddr[k]%2);                        //The starting Position is set to have depth 0

    cout << "generating " << tablename[k] <<" table.\n";		//little status update

    uint64_t count=1;
    for(uint64_t depth=1;count>0;depth++){
      count=0;
      for(uint64_t mover=0;mover<2*tablesize[k];mover++){						//apply moves to all positions in the current depth
//	uint64_t mem=~table[k][mover];
	uint8_t mem = readhalfbyte(~table[k][mover/2],mover%2);
/*	for(uint64_t add=0;add<16;add++){*/
	  if(depth==1+mem/*(mem>>4*add&15)*/){
	    count++;
	    uint64_t adr;
            switch(k){
	      case 0:
	        adr=adredges(mover/*+add*/);
                for (uint8_t i=0;i<18;i++) {
                  uint64_t j=posedges(edgemove[i][(adr>>48)&255],edgemove[i][(adr>>40)&255],edgemove[i][(adr>>32)&255],
	    	    edgemove[i][(adr>>24)&255],edgemove[i][(adr>>16)&255],edgemove[i][(adr>>8)&255],edgemove[i][adr&255]);
                  if (depth<readhalfbyte(~table[k][j/2],j%2))
                    table[k][j/2]=~sethalfbyte(~table[k][j/2],depth,j%2);
                }
                break;
	      case 1:
                adr=adrcenters(mover/*+add*/);
                for (uint8_t i=0;i<36;i++){						//PROTIP: at least 3 are actually redundant
	          uint64_t j=poscenters(centermove[i][(adr>>56)&255],centermove[i][(adr>>48)&255],centermove[i][(adr>>40)&255],centermove[i][(adr>>32)&255],
	    	    centermove[i][(adr>>24)&255],centermove[i][(adr>>16)&255],centermove[i][(adr>>8)&255],centermove[i][adr&255]);
if(j>2*tablesize[k])
  cout << mover+0 << "->" << adr+0 << "->" << j+0 << ":" << ((adr>>56)&255)+0 << ";" << ((adr>>48)&255)+0 << ";" << ((adr>>40)&255)+0 << ";" << ((adr>>32)&255)+0 << ";" << ((adr>>24)&255)+0 << ";" << ((adr>>16)&255)+0 << ";" << ((adr>>8)&255)+0 << ";" << (adr&255)+0 << " --> " << centermove[i][(adr>>56)&255]+0 << ";" << centermove[i][(adr>>48)&255]+0 << ";" << centermove[i][(adr>>40)&255]+0 << ";" << centermove[i][(adr>>32)&255]+0 << ";" << centermove[i][(adr>>24)&255]+0 << ";" << centermove[i][(adr>>16)&255]+0 << ";" << centermove[i][(adr>>8)&255]+0 << ";" << centermove[i][adr&255]+0 << "\n";
	          if (depth<readhalfbyte(~table[k][j/2],j%2))				//and look it up int the table + compare
	            table[k][j/2]=~sethalfbyte(~table[k][j/2],depth,j%2);	        //when it is smaller keep it in the next round.
	        }
	        break;
	      case 2:
                adr=adrcorners(mover/*+add*/);
                for (uint8_t i=0;i<36;i++) {
                  uint64_t j=poscorners(cornermove[i][(adr>>40)&255],cornermove[i][(adr>>32)&255],cornermove[i][(adr>>24)&255],
	    	    cornermove[i][(adr>>16)&255],cornermove[i][(adr>>8)&255],cornermove[i][adr&255]);
                  if (depth<readhalfbyte(~table[k][j/2],j%2))
                    table[k][j/2]=~sethalfbyte(~table[k][j/2],depth,j%2);
                }
	        break;
	    }
	  }
//	}
      }
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
