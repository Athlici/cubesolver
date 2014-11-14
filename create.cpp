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
    table[k][zeroaddr[k]/2]=~sethalfbyte(255,0,zeroaddr[k]%2);          //The starting Position is set to have depth 0

    cout << "generating " << tablename[k] <<" table.\n";		//little status update

    uint8_t *stack  = (uint8_t*) calloc(16*(elemsize[k]+1),1);	        //allocating the space for the temporary positions(inaccurate estimate)
    for(uint8_t i=0;i<elemsize[k];i++)stack[i+1]=elemsol[k][i];
    uint64_t counter = 0;

    uint8_t depth = 0;						//setting of the depth counter
    stack[0] = 0;
    do{
      if(stack[depth*(elemsize[k]+1)]<36){
//        for(uint8_t i=1;i<=elemsize[k];i++)
//          stack[(depth+1)*(elemsize[k]+1)+i]=move[k][stack[depth*(elemsize[k]+1)]][stack[depth*(elemsize[k]+1)+i]]

        uint8_t om=depth*(elemsize[k]+1),nm=(depth+1)*(elemsize[k]+1);
        uint64_t pos;
        switch(k){
          case 0:
            stack[nm+1]=edgemove[edgemap[stack[om]]][stack[om+1]];
            stack[nm+2]=edgemove[edgemap[stack[om]]][stack[om+2]];
            stack[nm+3]=edgemove[edgemap[stack[om]]][stack[om+3]];
            stack[nm+4]=edgemove[edgemap[stack[om]]][stack[om+4]];
            stack[nm+5]=edgemove[edgemap[stack[om]]][stack[om+5]];
            stack[nm+6]=edgemove[edgemap[stack[om]]][stack[om+6]];
            stack[nm+7]=edgemove[edgemap[stack[om]]][stack[om+7]];
            pos=posedges(stack[nm+1],stack[nm+2],stack[nm+3],stack[nm+4],stack[nm+5],stack[nm+6],stack[nm+7]);
//cout << depth+0 << ":" << stack[nm+1]+0 << "," << stack[nm+2]+0 << ","  << stack[nm+3]+0 << ","  << stack[nm+4]+0 << ","  << stack[nm+5]+0 << ","  << stack[nm+6]+0 << ","  << stack[nm+7]+0 << ";" << pos+0 << "\n";
            break;
          case 1:
            stack[nm+1]=centermove[stack[om]][stack[om+1]];
            stack[nm+2]=centermove[stack[om]][stack[om+2]];
            stack[nm+3]=centermove[stack[om]][stack[om+3]];
            stack[nm+4]=centermove[stack[om]][stack[om+4]];
            stack[nm+5]=centermove[stack[om]][stack[om+5]];
            stack[nm+6]=centermove[stack[om]][stack[om+6]];
            stack[nm+7]=centermove[stack[om]][stack[om+7]];
            stack[nm+8]=centermove[stack[om]][stack[om+8]];
            pos=poscenters(stack[nm+1],stack[nm+2],stack[nm+3],stack[nm+4],stack[nm+5],stack[nm+6],stack[nm+7],stack[nm+8]);
            break;
          case 2:
            stack[nm+1]=cornermove[stack[om]][stack[om+1]];
            stack[nm+2]=cornermove[stack[om]][stack[om+2]];
            stack[nm+3]=cornermove[stack[om]][stack[om+3]];
            stack[nm+4]=cornermove[stack[om]][stack[om+4]];
            stack[nm+5]=cornermove[stack[om]][stack[om+5]];
            stack[nm+6]=cornermove[stack[om]][stack[om+6]];
            pos=poscorners(stack[nm+1],stack[nm+2],stack[nm+3],stack[nm+4],stack[nm+5],stack[nm+6]);
            break;
        }

        stack[depth*(elemsize[k]+1)]++;
        stack[(depth+1)*(elemsize[k]+1)]=0;
        if(depth<maxdepth[k]&&depth<readhalfbyte(~table[k][pos/2],pos%2)){
          depth++;
          table[k][pos/2]=~sethalfbyte(~table[k][pos/2],depth,pos%2);
        }
      } else
        depth--;
      counter++;
      if(counter%1000000==0)cout << counter/1000000 << ":" << depth+0 << "\n";
    }while(stack[0]<36);

  FILE* file=fopen(tablepath[k],"wb");
  if(file!=0){
    fwrite(table[k],1,tablesize[k],file);
    fclose(file);
  }
  cout << tablename[k] << " table created\n"; 
  free(stack);
  }
}
