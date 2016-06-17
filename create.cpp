uint64_t genpar(uint8_t k,uint8_t l,uint8_t depth){
  void     (*adrfunc[3])(uint8_t*,uint64_t)        = {&adredges, &adrcenters, &adrcorners};
  uint64_t (*posfunc[3])(uint8_t*)                 = {&posedges, &poscenters, &poscorners};
  void     (*movfunc[3])(uint8_t*,uint8_t,uint8_t) = {&turnedges,&turncenters,&turncorners};
  const uint8_t movespace[3] = {18,36,36};
  uint8_t tmp[3]={7,centercount,cornercount};
  uint8_t n=tmp[k];
  uint64_t count = 0;
  for(uint64_t mover=l*tablecount[k]/corecount;mover<(l+1)*tablecount[k]/corecount;mover++){              //apply moves to all positions in the current depth
    uint8_t mem = readtabval(k,mover);
    if(depth==mem){
      count++;
      uint8_t current[n],next[n];
      (*adrfunc[k])(current,mover);
//      if(depth==2){
//      for(uint8_t i=0;i<6;i++)
//        cout << current[i]+0 << ",";
//      cout << current[6]+0 << "},{";
//      }
      for(uint8_t i=0;i<movespace[k];i++){			//some of these moves are redundant, TODO: eliminate by checking depth
        memcpy(next,current,n);
        (*movfunc[k])(next,i,n);
        uint64_t pos=(*posfunc[k])(next);
        if(depth<readtabval(k,pos))
          settabval(k,pos,depth+1);
	  }
	}
  }
  return count;
}


void gentable(uint8_t k) {						//generalized table creation 0→ edges, 1→ centers, 2→ corners
  FILE* file  = fopen(tablepath[k],"rb");
  table[k] = (uint8_t*) calloc(1,tablecount[k]/2);
  if(table[k]==NULL){
    cout << "allocation failure?";
    exit(1);
  }
  if(file!=0){
#if tablecompression==0
    fread(table[k],1,tablecount[k]/2,file);
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
          uint8_t t = 0,d = readnibble(~buffer[j/2],j%2);
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
    uint8_t sed[7]={0,3,6,9,12,15,18};
    uint8_t sce[12]={0,1,2,3,4,5,6,7,8,9,10,11};    //center12/.centermap - 1
    uint8_t sco[8]={0,1,2,3,4,5,6,7};               //corner8/.cornermap - 1
    uint64_t zeroaddr[3] = {posedges(sed),poscenters(sce),poscorners(sco)};
    settabval(k,zeroaddr[k],0);                                 //The starting Position is set to have depth 0

    cout << "generating " << tablename[k] <<" table.\n";		//little status update

    uint64_t count=1;
    for(uint8_t depth=0;count>0;depth++){
      count=0;
      future<uint64_t> par[corecount];
      for(uint8_t i=0;i<corecount;i++)
        par[i]=async(launch::async,genpar,k,i,depth);
      for(uint8_t i=0;i<corecount;i++)
        par[i].wait();
      for(uint8_t i=0;i<corecount;i++)
        count+=par[i].get();
      cout << count << " positions after depth " << depth+0 << "\n";	//little status update
    }

  FILE* file=fopen(tablepath[k],"wb");
  if(file!=0){
    fwrite(table[k],1,tablecount[k]/2,file);
    fclose(file);
  }
  cout << tablename[k] << " table created\n"; 
  }
}
