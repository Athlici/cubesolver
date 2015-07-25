void scramble(uint8_t k/*, uint64_t s*/){
  FILE* file = fopen(tablepath[k],"rb");
  table[k] = (uint8_t*) calloc(nextprime[k]/2+1,1);
  fread(table[k],1,tablesize[k],file);
  for(uint64_t i=nextprime[k]/2;i>=tablesize[k];i--)
    table[k][i]=153;
//  uint64_t i=1;
//  uint8_t prev=readhalfbyte(table[k][0],1);
//  do{
//    i=(i*s)%nextprime[k];
//    uint8_t tmp=readhalfbyte(table[k][i/2],i%2);
//    table[k][i/2]=sethalfbyte(table[k][i/2],prev,i%2);
//    prev=tmp;
//  }while(i>1);
  fclose(file);
}

void convert(uint8_t k, uint64_t s){	//swap the tables or adjust k to be 0 or 1
  //allocate memory for buffer, index and coded table
  const int64_t compsize[2]={147950693494,46383713506};
  int64_t min=0,max=0;
//  uint8_t* index = (uint8_t*) calloc(compsize[k]/8+64,1);
  const uint8_t  ptree[12] = {12,11,10,9,8,7,5,4,3,1,2,6};	//centers and corners have the same depth distribution
  int64_t pos = 0,addr = 1;

  for(int64_t i=0;i<nextprime[k];i++){
//    index[pos/8]+=1<<(7-pos%8);
    addr=(addr+s)%nextprime[k];
    pos+=ptree[readhalfbyte(~table[k][addr/2],addr%2)];
    if(i%64==0){
      int64_t diff=8092*((i/8092)*compsize[k]/nextprime[k])+(i%8092)*compsize[k]/nextprime[k]-pos;
      if(diff>max)max=diff; else
      if(diff<min)min=diff;
      if(max-min>maxdiff){
//	cout << "aborted constant " << s << " maximum spanwidth reached\n";
//	free(index);
	return;
      }
    }
  }
  cout << "constant " << s << " leads to: minimal offset: " << min << "  maximal offset: " << max << " spanwidth:" << max-min << "\n";
  maxdiff = max - min;
//  free(index);
  return;
}

bool primitiveroot(uint64_t s){
//  uint64_t divisors[4]={17148,20751708,9884730244,14827095366};
  uint64_t divisors[6]={1488018,187773558,1319704302,13385572206,31233001814,46849502721};
  for(uint8_t i=0;i<6;i++){
    uint64_t res=1, base=s;
    for(uint64_t exp=divisors[i];exp>0;exp>>=1){
      uint64_t l=base&((1<<20)-1),h=base>>20;
      if(exp%2==1)
        res=((1<<20)*((res*h)%nextprime[1])+res*l)%nextprime[1];
      base=((1<<20)*(((1<<20)*h*h)%nextprime[1]+2*h*l)+l*l)%nextprime[1];
    }
    if(res==1)
      return false;
  }
  return true;
}

void threading(uint8_t k, uint8_t l){
//  for(uint64_t i=nextprime[k]*(l+1)/4;i>nextprime[k]*l/4;i--){

//  default_random_engine generator;
//  uint64_t seeds[4]={2843501823,4008880998,456947876,369300986};
//  generator.seed(seeds[l]);
//  uniform_real_distribution<double> distribution(6.0,10.47);
  for(uint64_t i=0;i<nextprime[k]/corecount;i++){
//    uint64_t n = pow(10.0,distribution(generator));
    if(primitiveroot(corecount*i+l))
      convert(k,corecount*i+l);
    if(i%1000==0)
      cout << "Thread " << l+0 << " is at " << i << "\n";
  }
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
