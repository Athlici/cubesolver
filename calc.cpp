static const uint8_t BitsSetTable256[256] = {
#   define B2(n) n,     n+1,     n+1,     n+2
#   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
    B6(0), B6(1), B6(1), B6(2)
};

uint64_t bin(uint8_t k,uint8_t n){
  static const uint32_t bintable[8][24] =
      {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
      {0,0,1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136,153,171,190,210,231,253},
      {0,0,0,1,4,10,20,35,56,84,120,165,220,286,364,455,560,680,816,969,1140,1330,1540,1771},
      {0,0,0,0,1,5,15,35,70,126,210,330,495,715,1001,1365,1820,2380,3060,3876,4845,5985,7315,8855},
      {0,0,0,0,0,1,6,21,56,126,252,462,792,1287,2002,3003,4368,6188,8568,11628,15504,20349,26334,33649},
      {0,0,0,0,0,0,1,7,28,84,210,462,924,1716,3003,5005,8008,12376,18564,27132,38760,54264,74613,100947},
      {0,0,0,0,0,0,0,1,8,36,120,330,792,1716,3432,6435,11440,19448,31824,50388,77520,116280,170544,245157},
      {0,0,0,0,0,0,0,0,1,9,45,165,495,1287,3003,6435,12870,24310,43758,75582,125970,203490,319770,490314}};
  return bintable[k][n];
}
/*
static const uint16_t bin[3][24] = 
  {{0,0,1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136,153,171,190,210,231,253}, 
  {0,0,0,1,4,10,20,35,56,84,120,165,220,286,364,455,560,680,816,969,1140,1330,1540,1771}, 
  {0,0,0,0,1,5,15,35,70,126,210,330,495,715,1001,1365,1820,2380,3060,3876,4845,5985,7315,8855}};
*/
uint64_t id(uint8_t x){return x;}

uint64_t mod4(uint8_t x){return x%4;}

uint64_t div4(uint8_t x){return x/4;}

uint64_t binpos(uint8_t* a,uint8_t n,uint64_t (*f)(uint8_t)=id){
    uint64_t res=0;
    for(uint8_t i=0;i<n;i++)
      res+=bin(i,(*f)(a[i]));
    return res;
}

void binadr(uint8_t* res,uint64_t x,int8_t n){
  for(int8_t i=n-1;i>=0;i--){
    uint8_t pos=23;
    while(bin(i,pos)>x) pos--;
    res[i]=pos;
    x-=bin(i,pos);
  }
}

uint64_t permrank(uint8_t* a,uint8_t* b,uint8_t n){
  if(n==1)
    return 0;
  uint8_t s=a[n-1];
  swap(a[n-1],a[b[n-1]]);
  swap(b[s],b[n-1]);
  return s+n*permrank(a,b,n-1);
}

uint64_t permpos(uint8_t* a,uint8_t n){
  uint8_t b[n];
  for(uint8_t i=0;i<n;i++)
    b[a[i]]=i;
  return permrank(a,b,n);
}

void permadr(uint8_t* res,uint64_t x,int8_t n){
  for(uint8_t i=0;i<n;i++)
    res[i]=i;
  for(int8_t i=n;i>1;x/=i--)
    swap(res[i-1],res[x%i]);
}

//Might be reformulated, involves ugly 7 out of 8 choice though.
uint64_t posedges(uint8_t* a){
  uint8_t A[7]={a[0],a[1],a[2],a[3],a[4],a[5],a[6]}; //memcpy?
  for(uint8_t i=0;i<6;i++)
    for(uint8_t j=i+1;j<7;j++)
      if(a[i]<a[j])
        A[i]-=3;
  return (A[6]+6*(A[5]+9*(A[4]+12*(A[3]+15*(A[2]+18*(A[1]+21*A[0]))))));
}

void adredges(uint8_t* res,uint64_t x){  //stores the result in the array of the first argument
  for(uint8_t i=6;i<=24;i+=3){		//which can be extracted from the argument
    res[i/3-2] = x % i;				//in reduced form
    x /= i;
  }
  for(uint8_t i=0;i<6;i++)			//therefore we increase them dependently
    for(uint8_t j=i+1;j<7;j++)
      if(res[j]/3<=res[i]/3) 
	    res[i]+=3;
}

#if symred==1
uint16_t srposcorn[735471]={0};
uint8_t cornsymred[367736]={0};
uint32_t sradrcorn[46372]; //slightly wastefull, almost all values are below 2^16
uint16_t srposcent[10626]={0};
uint16_t sradrcent[2706];

void initsymfuncs(){
  uint32_t count=1;
  for(uint32_t i=0;i<735471;i++){
    uint32_t pos[16],min=-1;
    uint8_t  minind=0;
    for(uint8_t j=0;j<16;j++){
      uint8_t subset[8];
      binadr(subset,i,8);
      symcorners(subset,j);
      sort(subset,subset+8);
      pos[j]=binpos(subset,8);
      if(pos[j]<min){
        min=pos[j];
        minind=j;
      }
    }
    cornsymred[i/2]=setnibble(cornsymred[i/2],minind,i%2);
    if(srposcorn[i]==0){
      for(uint8_t j=0;j<16;j++)
        srposcorn[pos[j]]=count;
      sradrcorn[count-1]=min;
      count++;
    }
  }
  for(uint32_t i=0;i<735471;i++) srposcorn[i]--;
  cout << "Wrote " << count-1 << " corner orbits to the table!\n";
  
  count=1;
  for(uint16_t i=0;i<10626;i++){
    uint16_t pos[4],min=-1;
    uint8_t  minind=0;
    for(uint8_t j=0;j<4;j++){
      uint8_t subset[4];
      binadr(subset,i,4);
      symcenters(subset,j);
      sort(subset,subset+4);
      pos[j]=binpos(subset,4);
      if(pos[j]<min){
        min=pos[j];
        minind=j;
      }
    }
    srposcent[i]+=minind;
    if(srposcent[i]<4){
      for(uint8_t j=0;j<4;j++)
        srposcent[pos[j]]=4*count+srposcent[pos[j]]%4;
      sradrcent[count-1]=min;
      count++;
    }
  }
  for(uint32_t i=0;i<10626;i++) srposcent[i]-=4;
  cout << "Wrote " << count-1 << " center orbits to the table!\n";
}
#endif
uint64_t poscorners(uint8_t* a){
  uint8_t pos[cornercount];
  memcpy(pos,a,cornercount);
  sort(pos,pos+cornercount);
  uint32_t x=binpos(pos,cornercount);
#if symred==1
  symcorners(a,readnibble(cornsymred[x/2],x%2));
#endif
  uint32_t bmp=0;
  uint8_t perm[cornercount]={0};
  for(uint8_t i=0;i<cornercount;i++)
    bmp+=(1<<a[i]);
  for(uint8_t i=0;i<cornercount;i++){
    uint32_t mask=bmp&((1<<a[i])-1);        //create a mask including only x<a[i]
    for(uint8_t j=0;j<24;j+=8)    //and reduce a[i] appropiatly
      perm[i]+=BitsSetTable256[(mask>>j)%256];
  }
#if symred==1
  return 46371*permpos(perm,8)+srposcorn[x];
#elif cornercount==8
  return 735471*permpos(perm,8)+x;
#else
  return 134596*permpos(perm,6)+x;
#endif
}

void adrcorners(uint8_t* res,uint64_t pos){
#if symred==1
  uint64_t x=sradrcorn[pos%46371];pos/=46371;
#elif cornercount==8
  uint64_t x=pos%735471;pos/=735471;
#else
  uint64_t x=pos%134596;pos/=134596;
#endif
  uint64_t y=pos;
  uint8_t tmp[cornercount];
  binadr(tmp,x,cornercount);
  uint8_t perm[cornercount];
  permadr(perm,y,cornercount);
  for(uint8_t i=0;i<cornercount;i++)
    res[i]=tmp[perm[i]];
}

uint64_t poscenters(uint8_t* a){
  uint64_t res=0;

  if(a[0]>a[1])swap(a[0],a[1]); //Sort the white pieces, hold off on the rest until
  if(a[2]>a[3])swap(a[2],a[3]); //we have potentially applied out symmetry reductions
  if(a[0]>a[2])swap(a[0],a[2]);
  if(a[1]>a[3])swap(a[1],a[3]);
  if(a[1]>a[2])swap(a[1],a[2]);

#if symred==1
  uint16_t tmp=srposcent[binpos(a,4)];
  symcenters(a,tmp%4);
  res+=tmp/4;
#endif
  for (uint8_t i=4;i<12;i+=4){
    if(a[0+i]>a[1+i])swap(a[0+i],a[1+i]);
    if(a[2+i]>a[3+i])swap(a[2+i],a[3+i]);
    if(a[0+i]>a[2+i])swap(a[0+i],a[2+i]);
    if(a[1+i]>a[3+i])swap(a[1+i],a[3+i]);
    if(a[1+i]>a[2+i])swap(a[1+i],a[2+i]);
  }
  uint32_t curr=0,last=0;           //keep track which bits are set and have been set
  for(uint8_t b=0;b<12;b+=4){       //for every block
    for(uint8_t i=b;i<b+4;i++){     //for every element
      curr+=(1<<a[i]);              //add it to the bit pile
      uint32_t mask=last&((1<<a[i])-1);        //create a mask including only x<a[i]
      for(uint8_t j=0;j<24;j+=8)    //and reduce a[i] appropiatly
        a[i]-=BitsSetTable256[(mask>>j)%256];
    }
    last=curr;
  }
#if symred==0
  static const uint64_t factors[3] = {1,10626,51482970};
  for(int8_t i=0;i<12;i+=4)
#else
  static const uint64_t factors[3] = {1, 2706,13110570};
  for(int8_t i=4;i<12;i+=4)
#endif
    res+=factors[i/4]*binpos(a+i,4);
  return res;
}

void adrcenters(uint8_t* res,uint64_t x){
  uint16_t subc[3];
#if symred==1
  subc[0]=sradrcent[x%2706];x/=2706;
#else
  subc[0]=x%10626;x/=10626;
#endif
  subc[1]=x%4845;x/=4845;
  subc[2]=x;
    
  for(uint8_t i=0;i<3;i++)
    binadr(res+4*i,subc[i],4);
//Rewrite the rest of this another time
  for(uint8_t i=4;i<8;i++)
    for(uint8_t j=0;j<4;j++)
      if(res[j]<=res[i])
        res[i]++;

  uint8_t foo[8];
  merge(res,res+4,res+4,res+8,foo);
  for(uint8_t i=8;i<12;i++)
    for(uint8_t j=0;j<8;j++)
      if(foo[j]<=res[i])
        res[i]++;
}

uint8_t minDepth(cube Cube){     //make sure the destruction of the cube is without consequences
  uint8_t max=readtabval(0,posedges(Cube.edge));
#if centercount==12
  const uint8_t centerrots[2]={0,12};
#else
  const uint8_t centerrots[3]={0,0,0};  //Im not sure these do even exist without changing the movearrays?
#endif
  for(uint8_t i=0;i<24;i+=centercount){
    rotatecenters(Cube.center+i,Cube.center+i,centercount);
    uint8_t tmp=readtabval(1,poscenters(Cube.center+i));
    if(tmp>max)
      max=tmp;
  }
#if cornercount==8
  const uint8_t cornerrots[3]={0,13,22};
#else
  const uint8_t cornerrots[4]={0,0,0,0}; //Same here (Probably not?)?
#endif
  for(uint8_t i=0;i<24;i+=cornercount){
    rotatecorners(Cube.corner+i,Cube.corner+i,cornercount);
    uint8_t tmp=readtabval(2,poscorners(Cube.corner+i));
    if(tmp>max)
      max=tmp;
  }

  return max;
}
