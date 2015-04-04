void convert(uint8_t k){	//swap the tables or adjust k to be 0 or 1
  //allocate memory for buffer, index and coded table
  const int64_t compsize[2]={147950693494,46383713506};
  int64_t min=0,max=0;
  FILE* file=fopen(tablepath[k],"rb");
  const uint64_t buffersize = 510;
  uint8_t* buffer = (uint8_t*) calloc(buffersize,1);
  table[k] = (uint8_t*) calloc(compsize[k]/8+32,1);
//  uint8_t* index[k] = calloc(tablesize[k]/8,1);			//maybe incorrect, due to factors
  const uint8_t  ptree[12] = {12,11,10,9,8,7,5,4,3,1,2,6};	//centers and corners have the same depth distribution
  int64_t pos = 0;
cout << "starting reading file\n";

  for(int64_t i=0;i<tablesize[k];i+=buffersize){		//Can be integrated into generate
    fread(buffer,1,buffersize,file);
    for(int64_t j=0;j<2*buffersize;j++){
      table[k][pos/8]+=1<<(7-pos%8);
      pos+=ptree[readhalfbyte(~buffer[j/2],j%2)];
      if((2*i+j)%64==0){
//cout << i << " " << j << " " << pos << " " << compsize[k]*(2*i+j)/(tablesize[k])-pos << "\n";
	int64_t diff=compsize[k]*(2*i+j)/(2*tablesize[k])-pos;
	if(diff>max)max=diff; else
	if(diff<min)min=diff;
      }
    }
//    if((i/510)%1000==0)
//      cout << "finished block " << i/510 << " at position " << pos << "\n";
  }
//write table (+index?) to file
  cout << "minimal offset: " << min << "  maximal offset: " << max << "\n";
  fclose(file);
  file=fopen(comppath[k],"wb");
  fwrite(table[k],1,compsize[k]/8+32,file);
  fclose(file);
}

//create method to create index on the fly
/*
uint8_t decode(uint64_t addr,uint8_t k){
  int16_t offset=index[k][addr/64];            //lookup offset in index
//get mem , 2*8Byte or optimized
//do bitmagic to jump to correct position
//count number of zeroes

  const uint8_t rtree[12] = {9,10,8,7,6,11,5,4,3,2,1,0};	//inverse permutation to ptree
  return rtree[zc];
}
*/
