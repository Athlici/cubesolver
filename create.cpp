void gentable(uint8_t k) {						//generalized table creation 0→ edges, 1→ centers, 2→ corners

  table[k] = (uint8_t*) calloc(tablesize[k],1);
  FILE* file  = fopen(tablepath[k],"rb");

  if(file!=0){
    fread(table[k],1,tablesize[k],file);
    cout << "loaded " << tablename[k] << " table from disk.\n";
    fclose(file);
  }else{
    uint64_t zeroaddr[3] = {
#if centercount==8
			    poscenters(0,1,2,3,8,9,10,11),
#else
			    poscenters(0,1,2,3,4,5,6,7,8,9,10,11),
#endif
#if cornercount==6
			    poscorners(0,1,2,3,4,5),
#else
			    poscorners(0,1,5,4,8,9,10,11),
#endif
			    posedges(0,3,6,9,12,15,18)};
    table[k][zeroaddr[k]/2]=~sethalfbyte(255,0,zeroaddr[k]%2);          //The starting Position is set to have depth 0
    uint64_t (*adrfunc[3])(uint64_t a);
    adrfunc[0]=adrcenters; adrfunc[1]=adrcorners; adrfunc[2]=adredges;
    const uint8_t movespace[3] = {36,36,18};

    cout << "generating " << tablename[k] <<" table.\n";		//little status update

    uint64_t count=1;
    for(uint8_t depth=0;count>0;depth++){
      count=0;
      for(uint64_t mover=0;mover<2*tablesize[k];mover++){		//apply moves to all positions in the current depth
	uint8_t mem = readhalfbyte(~table[k][mover/2],mover%2);
	if(depth==mem){
	  count++;
	  uint64_t adr=(*adrfunc[k])(mover),j;
          for (uint8_t i=0;i<movespace[k];i++){			//some of these moves are redundant, TODO: eliminate by checking depth
            switch(k){
	      case 0:
#if centercount==8
	        j=poscenters(centermove[i][(adr>>35)&31],centermove[i][(adr>>30)&31],centermove[i][(adr>>25)&31],centermove[i][(adr>>20)&31],
	  	    centermove[i][(adr>>15)&31],centermove[i][(adr>>10)&31],centermove[i][(adr>>5)&31],centermove[i][adr&31]);
#else
                j=poscenters(centermove[i][(adr>>55)&31],centermove[i][(adr>>50)&31],centermove[i][(adr>>45)&31],centermove[i][(adr>>40)&31],
                  centermove[i][(adr>>35)&31],centermove[i][(adr>>30)&31],centermove[i][(adr>>25)&31],centermove[i][(adr>>20)&31],
                  centermove[i][(adr>>15)&31],centermove[i][(adr>>10)&31],centermove[i][(adr>>5)&31],centermove[i][adr&31]);
#endif
	        break;
	      case 1:
#if cornercount==6
                j=poscorners(cornermove[i][(adr>>40)&255],cornermove[i][(adr>>32)&255],cornermove[i][(adr>>24)&255],
	  	    cornermove[i][(adr>>16)&255],cornermove[i][(adr>>8)&255],cornermove[i][adr&255]);
#else
                j=poscorners(cornermove[i][(adr>>56)&255],cornermove[i][(adr>>48)&255],cornermove[i][(adr>>40)&255],cornermove[i][(adr>>32)&255]
                  ,cornermove[i][(adr>>24)&255],cornermove[i][(adr>>16)&255],cornermove[i][(adr>>8)&255],cornermove[i][adr&255]);
#endif
		break;
	      case 2:
                j=posedges(edgemove[i][(adr>>48)&255],edgemove[i][(adr>>40)&255],edgemove[i][(adr>>32)&255],
	  	    edgemove[i][(adr>>24)&255],edgemove[i][(adr>>16)&255],edgemove[i][(adr>>8)&255],edgemove[i][adr&255]);
                break;
            }
            if (depth<readhalfbyte(~table[k][j/2],j%2))
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
