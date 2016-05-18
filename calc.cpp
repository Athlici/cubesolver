//Might be faster with seperate permution/orientation encoding, but it's working this way and isn't the bottleneck.
uint64_t posedges(const uint8_t &A,const uint8_t &b,const uint8_t &c,const uint8_t &d,
		  const uint8_t &e,const uint8_t &f,const uint8_t &g){
  uint8_t B=b,C=c,D=d,E=e,F=f,G=g; 		//calculates a unique linear position for every possible edgeposition

  if (A<b) B-=3;
  if (A<c) C-=3;
  if (b<c) C-=3;
  if (A<d) D-=3;
  if (b<d) D-=3; 
  if (c<d) D-=3;
  if (A<e) E-=3;
  if (b<e) E-=3;
  if (c<e) E-=3;
  if (d<e) E-=3;
  if (A<f) F-=3;
  if (b<f) F-=3;
  if (c<f) F-=3;
  if (d<f) F-=3;
  if (e<f) F-=3;
  if (A<g) G-=3;
  if (b<g) G-=3;
  if (c<g) G-=3;
  if (d<g) G-=3;
  if (e<g) G-=3;
  if (f<g) G-=3;

  return (G+6*(F+9*(E+12*(D+15*(C+18*(B+21*A))))));
}

void adredges(uint8_t* res,uint64_t x){     //stores the result in the array of the first argument
  
  for(uint8_t i=6;i<=24;i+=3){		//which can be extracted from the argument
    res[i/3-2] = x % i;				//in reduced form
    x /= i;
  }

  for(uint8_t i=0;i<6;i++)			//therefore we increase them dependently
    for(uint8_t j=i+1;j<7;j++)
      if(res[j]/3<=res[i]/3) 
	res[i]+=3;

}

//Idea, implement permutation ranking once, use it on corners and edges
#if cornercount==6
uint64_t poscorners(const uint8_t &A,const uint8_t &b,const uint8_t &c,
		    const uint8_t &d,const uint8_t &e,const uint8_t &f){
  uint8_t B=b,C=c,D=d,E=e,F=f;
#else
uint64_t poscorners(const uint8_t &A,const uint8_t &b,const uint8_t &c,const uint8_t &d,
		    const uint8_t &e,const uint8_t &f,const uint8_t &g,const uint8_t &h){
  uint8_t B=b,C=c,D=d,E=e,F=f,G=g,H=h;
#endif

  if (A<b) B--;
  if (A<c) C--;
  if (b<c) C--;
  if (A<d) D--;
  if (b<d) D--;
  if (c<d) D--;
  if (A<e) E--;
  if (b<e) E--;
  if (c<e) E--;
  if (d<e) E--;
  if (A<f) F--;
  if (b<f) F--;
  if (c<f) F--;
  if (d<f) F--;
  if (e<f) F--;
#if cornercount==8 
  if (A<g) G--;
  if (b<g) G--;
  if (c<g) G--;
  if (d<g) G--;
  if (e<g) G--;
  if (f<g) G--;
  if (A<h) H--;
  if (b<h) H--;
  if (c<h) H--;
  if (d<h) H--;
  if (e<h) H--;
  if (f<h) H--;
  if (g<h) H--;
 
  return (H+17*(G+18*(F+19*(E+20*(D+21*(C+22*(B+23*((uint64_t)A))))))));
#else
  return (F+19*(E+20*(D+21*(C+22*(B+23*A)))));
#endif
}

//adjust this to match the cornercount definition
void adrcorners(uint8_t* res,uint64_t x){
  for(uint8_t i=25-cornercount;i<=24;i++){  //same principle as for the edges
    res[i+cornercount-25] = x % i;
    x /= i;
  }

  for(uint8_t i=0;i<cornercount-1;i++)		//reincrease them dependently
    for(uint8_t j=i+1;j<cornercount;j++)
      if(res[j]<=res[i]) 
        res[i]++;

}

static const uint8_t BitsSetTable256[256] = 
{
#   define B2(n) n,     n+1,     n+1,     n+2
#   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
    B6(0), B6(1), B6(1), B6(2)
};

static const uint16_t bin[3][24] = 
  {{0,0,1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136,153,171,190,210,231,253}, 
  {0,0,0,1,4,10,20,35,56,84,120,165,220,286,364,455,560,680,816,969,1140,1330,1540,1771}, 
  {0,0,0,0,1,5,15,35,70,126,210,330,495,715,1001,1365,1820,2380,3060,3876,4845,5985,7315,8855}};

#if symred==1
uint64_t id(uint8_t x){return x;}

uint64_t mod4(uint8_t x){return x%4;}

uint64_t div4(uint8_t x){return x/4;}

uint64_t binpos(uint8_t* a,uint8_t n,uint64_t (*f)(uint8_t)=id){
    uint64_t res=(*f)(a[0]);
    for(uint8_t i=1;i<n;i++)
      res+=bin[i][(*f)(a[i])];
    return res;
}
#endif

uint64_t poscenters(uint8_t* a){
  uint64_t res=0;

  if(a[0]>a[1])swap(a[0],a[1]); //Sort the white pieces, hold off on the rest until
  if(a[2]>a[3])swap(a[2],a[3]); //we have potentially applied out symmetry reductions
  if(a[0]>a[2])swap(a[0],a[2]);
  if(a[1]>a[3])swap(a[1],a[3]);
  if(a[1]>a[2])swap(a[1],a[2]);

#if symred==1
  switch((a[0]/4==a[1]/4)*4+(a[1]/4==a[2]/4)*2+(a[2]/4==a[3]/4)){
    case 0:
      symcenters(a,a[0]%4);   //a[0]%4==0 after this;
      res=binpos(a,4,div4)*64+(a[3]%4)*16+(a[2]%4)*4+(a[1]%4);
    break;
    case 1:
      symcenters(a,a[0]%4);
      if(a[2]>a[3])swap(a[2],a[3]);
      res=960+4*(20*binpos(a+2,2,mod4)+binpos(a,3,div4))+a[1]%4;
    break;
    case 2:
      symcenters(a,a[0]);
      uint8_t b[3]={a[0],a[1],a[3]};
      if(a[1]>a[2])swap(a[1],a[2]);
      res=1440+4*(20*binpos(a+1,2,mod4)+binpos(b,3i,div4))+a[3]%4;
    break;
    case 4:
      symcenters(a,a[2]%4);
      if(a[0]>a[1])swap(a[0],a[1]);
      res=1920+4*(20*binpos(a,2,mod4)+binpos(a+1,3i,div4))+a[3]%4;
    break;
    case 3:
      symcenters(a,a[0]%4);
      if(a[1]>a[2])swap(a[1],a[2]);
      if(a[2]>a[3])swap(a[2],a[3]);
      if(a[1]>a[2])swap(a[1],a[2]);
      res=2400+4*binpos(a,2,div4)+binpos(a+1,3,mod4);
    break;
    case 6:
      symcenters(a,a[3]%4);
      if(a[0]>a[1])swap(a[0],a[1]);
      if(a[1]>a[2])swap(a[1],a[2]);
      if(a[0]>a[1])swap(a[0],a[1]);
      res=2460+4*binpos(a+2,2,div4)+binpos(a,3,mod4);
    break;
    case 5://this is suboptimal by 3%
      symcenters(a,a[0]%4);
      if(a[2]>a[3])swap(a[2],a[3]);
      res=2520+3*(6*binpos(a+1,2,div4)+binpos(a+2,2,mod4))+(a[1]-1);
    break;
    case 7:
      res=2790+a[0]/4;
  }
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
  static const uint64_t factors[3] = {1, 2796,13546620};
  for(int8_t i=4;i<12;i+=4)
#endif
    res+=factors[i/4]*(binomials[2][a[3+i]]+binomials[1][a[2+i]]+binomials[0][a[1+i]]+a[0+i]);
  return res;
}

#if symred==1
void binadr(uint8_t* res,uint64_t x,int8_t n){
  for(int8_t i=n-2;i>=0;i--){
    uint8_t pos=23;
    while(bin[i][pos]>x) pos--;
    res[i+1]=pos;
    x-=bin[i][pos];
  }
  res[0]=x;
}
#endif

void adrcenters(uint8_t* res,uint64_t x){
  uint16_t subc[3];
#if symred==1
  static const uint64_t factors[2] = {2796,4845,1};
#else
  static const uint64_t factors[2] = {10626,4845,1};
#endif
  for(uint8_t i=0;i<3;i++){
    subc[i]=x%factors[i];
    x/=factors[i];
  }
#if symred==1
  if(subc[0]<2400){
    if(subc[0]<1440){
      if(subc[0]<960){
        res[0]=0;
      }else{
        
      }
    }else{
      if(subc[0]<1920){
        
      }else{
        
      }
    }
  }else{
    if(subc[0]<2520){
      if(subc[0]<2460){
        
      }else{
        
      }
    }else{
      if(subc[0]<2790){

      }else{
        for(uint8_t i=0;i<4;i++)
          res[i]=4*(subc[0]-2790)+i;
      }
    }
  }

  for(uint8_t i=1;i<3;i++)
#else
  for(uint8_t i=0;i<3;i++)
#endif
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

uint8_t minDepth(const cube &Cube){
//WTF
  uint64_t address[]={posedges(Cube.edge[0],Cube.edge[1],Cube.edge[2],Cube.edge[3],Cube.edge[4],Cube.edge[5],Cube.edge[6]),
#if centercount==8
    poscenters(Cube.center[0],Cube.center[1],Cube.center[2],Cube.center[3],Cube.center[8],Cube.center[9],Cube.center[10],Cube.center[11]),
    poscenters(centerturn[3][Cube.center[4]],centerturn[3][Cube.center[5]],centerturn[3][Cube.center[6]],centerturn[3][Cube.center[7]],
      centerturn[3][Cube.center[12]],centerturn[3][Cube.center[13]],centerturn[3][Cube.center[14]],centerturn[3][Cube.center[15]]),
    poscenters(centerturn[0][Cube.center[16]],centerturn[0][Cube.center[17]],centerturn[0][Cube.center[18]],centerturn[0][Cube.center[19]],
      centerturn[0][Cube.center[20]],centerturn[0][Cube.center[21]],centerturn[0][Cube.center[22]],centerturn[0][Cube.center[23]]),
#else
    poscenters(Cube.center[0],Cube.center[1],Cube.center[2],Cube.center[3],Cube.center[4],Cube.center[5],
	       Cube.center[6],Cube.center[7],Cube.center[8],Cube.center[9],Cube.center[10],Cube.center[11]),
    poscenters(centerturn[8][Cube.center[16]],centerturn[8][Cube.center[17]],centerturn[8][Cube.center[18]],centerturn[8][Cube.center[19]],
          centerturn[8][Cube.center[12]],centerturn[8][Cube.center[13]],centerturn[8][Cube.center[14]],centerturn[8][Cube.center[15]],
          centerturn[8][Cube.center[20]],centerturn[8][Cube.center[21]],centerturn[8][Cube.center[22]],centerturn[8][Cube.center[23]]),
#endif
#if cornercount==6
    poscorners(Cube.corner[0],Cube.corner[1],Cube.corner[2],Cube.corner[3],Cube.corner[4],Cube.corner[5]),
    poscorners(cornerturn[0][Cube.corner[17]],cornerturn[0][Cube.corner[16]],cornerturn[0][Cube.corner[7]],cornerturn[0][Cube.corner[6]],
      cornerturn[0][Cube.corner[14]],cornerturn[0][Cube.corner[15]]),
    poscorners(cornerturn[1][Cube.corner[11]],cornerturn[1][Cube.corner[10]],cornerturn[1][Cube.corner[21]],cornerturn[1][Cube.corner[20]],
      cornerturn[1][Cube.corner[8]],cornerturn[1][Cube.corner[9]]),
    poscorners(cornerturn[2][Cube.corner[18]],cornerturn[2][Cube.corner[19]],cornerturn[2][Cube.corner[23]],cornerturn[2][Cube.corner[22]],
      cornerturn[2][Cube.corner[13]],cornerturn[2][Cube.corner[12]])};
#else
    poscorners(Cube.corner[0],Cube.corner[1],Cube.corner[5],Cube.corner[4],Cube.corner[8],Cube.corner[9],Cube.corner[10],Cube.corner[11]),
    poscorners(cornerturn[15][Cube.corner[2]],cornerturn[15][Cube.corner[3]],cornerturn[15][Cube.corner[7]],cornerturn[15][Cube.corner[6]],
      cornerturn[15][Cube.corner[21]],cornerturn[15][Cube.corner[20]],cornerturn[15][Cube.corner[23]],cornerturn[15][Cube.corner[22]]),
    poscorners(cornerturn[0][Cube.corner[17]],cornerturn[0][Cube.corner[16]],cornerturn[0][Cube.corner[15]],cornerturn[0][Cube.corner[14]],
      cornerturn[0][Cube.corner[13]],cornerturn[0][Cube.corner[12]],cornerturn[0][Cube.corner[19]],cornerturn[0][Cube.corner[18]])};
#endif

  uint8_t max=readhalfbyte(~table[0][address[0]/2],address[0]%2);
  for(uint8_t i=1;i<1+24/centercount;i++){
#if splitcomp==0
    uint8_t tmp = readhalfbyte(~table[1][address[i]/2],address[i]%2);
#else
    uint8_t tmp = read2bit(table[1][address[i]/4],address[i]%4) + 7;
    if(tmp==7)
      tmp = colookup(1,address[i]);
#endif
    if(max<tmp) max=tmp;
  }
  for(uint8_t i=1+24/centercount;i<1+24/centercount+24/cornercount;i++){
#if splitcomp==0
    uint8_t tmp = readhalfbyte(~table[2][address[i]/2],address[i]%2);
#else
    uint8_t tmp = read2bit(table[2][address[i]/4],address[i]%4) + 7;
    if(tmp==7)
      tmp = colookup(2,address[i]);
#endif
    if(max<tmp) max=tmp;
  }

  return max;
}
