uint8_t sethalfbyte(const uint8_t &a/*Eingangsbyte*/,const uint8_t &b/*Modifikation*/,const uint8_t &c/*lower(0) or upper half(1)*/){
  return (b<<4*c)|(a&(240-225*c));			//returns the upper part of the byte when c==1 otherwise the lower part
}

uint8_t readhalfbyte(const uint8_t &a/*Eingangsbyte*/,const uint8_t &c/*lower(0) or upper half(1)*/){
  return (a>>4*c)&15;					//sets the upper part of the byte when c==1 otherwise the lower part
}

#if disktablegen==true
inline uint8_t set2bit(uint8_t a/*Eingangsbyte*/,uint8_t b/*Modifikation*/,uint8_t c/*which 2bit*/){
	  return (b<<2*c)|(a&(255-(3<<2*c)));
}

inline uint8_t read2bit(uint8_t a/*Eingangsbyte*/, uint8_t c/*which 2bit*/){
	  return (a>>2*c)&3;
}
#endif

//inline uint8_t sethalfbyte(uint8_t a/*Eingangsbyte*/,uint8_t b/*Modifikation*/,uint8_t c/*lower(0) or upper half(1)*/){
////  if(c)return (b<<4)|(a&15); else return b|(a&240);
//  return c ? (b<<4)|(a&15) : b|(a&240);
//}
//
//inline uint8_t readhalfbyte(uint8_t a/*Eingangsbyte*/, uint8_t c/*lower(0) or upper half(1)*/){
////  if(c)return a>>4; else return a&15
//  return c ? a>>4 : a&15;
//}

/*  functions to maybe use when switching to uint64_t
inline uint64_t setchar(uint64_t input,uint8_t shift,uint8_t change){
  shift*=8;
//  asm ( "rol %1,%0    \n\t"
//        "mov %2,%%al  \n\t"
//        "ror %1,%0    \n\t"
//        : "+a" (input) : "r" (shift), "r" (change) );
  input=(input<<(64-shift))^(input>>shift);
asm ("mov %1,%%al" : "+a" (input) : "r" (change) );
  return (input<<shift)^(input>>(64-shift));
}

inline uint8_t getchar(uint64_t input,uint8_t shift){
  return (input>>(8*shift))&255;
}

uint64_t touint64(uint8_t val[]){
  uint64_t result=0;
  for (uint8_t i=0,i<8,i++)result+=val[i]*(1<<(8*i));
  return result;
  //return val[0]+256*(val[1]+256*(val[2]+256*(val[3]+...)))
}

uint8_t (*touint8(uint64_t val))[8]{}
*/

//The amount of comparisons can be reduced from n^2 to n*log(n) by using binary trees:
//inserting the nth value und subtracting from it the amount of nodes on the left
//of the element delivers the result.

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

uint64_t adredges(uint64_t x){
  
  uint8_t pos[7];				//Array for orriginal values
  for(uint8_t i=6;i<=24;i+=3){			//which can be extracted from the argument
    pos[i/3-2] = x % i;				//in reduced form
    x /= i;
  }

  for(uint8_t i=0;i<6;i++)			//therefore we increase them dependently
    for(uint8_t j=i+1;j<7;j++)
      if(pos[j]/3<=pos[i]/3) 
	pos[i]+=3;

  uint64_t result=pos[6];			//store result in uin64_t bytewise
  for(int8_t i=5;i>=0;i--){
    result*=256;
    result+=pos[i];
  }

  return result;
}

#if cornercount==6
uint64_t poscorners(const uint8_t &A,const uint8_t &b,const uint8_t &c,
		    const uint8_t &d,const uint8_t &e,const uint8_t &f){
  uint8_t B=b,C=c,D=d,E=e,F=f;			//the same for the corners
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
uint64_t adrcorners(uint64_t x){
  uint8_t pos[cornercount];			//Array for orriginal values
  for(uint8_t i=25-cornercount;i<=24;i++){	//which can be extracted from the argument
    pos[i+cornercount-25] = x % i;		//in reduced form
    x /= i;
  }

  for(uint8_t i=0;i<cornercount-1;i++)		//therefore we increase them dependently
    for(uint8_t j=i+1;j<cornercount;j++)
      if(pos[j]<=pos[i]) 
	pos[i]++;

  uint64_t result=pos[cornercount-1];			//store result in uin64_t bytewise
  for(int8_t i=cornercount-2;i>=0;i--){
    result*=256;
    result+=pos[i];
  }
//watch for order,alternatively:
//  uint64_t result=0;
//  for(uint8_t i=0;i<8;i++)
//    result+=elem[i]<<(8*i);

  return result;
}

#if centercount==8
uint64_t poscenters(uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g, uint8_t h){
#else
uint64_t poscenters(uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,
		    uint8_t g,uint8_t h,uint8_t i,uint8_t j,uint8_t k,uint8_t l){
#endif
//and the same again for the centers, this is more difficult because 4 center pieces are equivalent
//but therefore the memory usage is also reduced by a factor of 24^2.

  if (a>b)swap(a,b);              			//the values are sorted by size, each group of 4 elements on its own,
  if (c>d)swap(c,d);              			//with increasing size from a-d;e-h
  if (a>c)swap(a,c);
  if (b>d)swap(b,d);
  if (b>c)swap(b,c);

  if (e>f)swap(e,f);
  if (g>h)swap(g,h);
  if (e>g)swap(e,g);
  if (f>h)swap(f,h);
  if (f>g)swap(f,g);
#if centercount==8
  decdependently(a,b,c,d,e,f,g,h);  //decrease some values of the secondary positions, if these are already taken

  return (a*(192084870+a*(-13425495+(416670-4845*a)*a))+b*(28120380+b*(-1279080+19380*b))+(2616300-58140*c)*c+
   116280*d+e*(21350+e*(-1835+(70-e)*e))+f*(3884+f*(-216+4*f))+(444-12*g)*g+24*h-32214144)/24;
#else
  if (i>j)swap(i,j);
  if (k>l)swap(k,l);
  if (i>k)swap(i,k);
  if (j>l)swap(j,l);
  if (j>k)swap(j,k);

  decdependently(a,b,c,d,e,f,g,h,i,j,k,l);              //do all the combinatorical magic in an ugly function.

  return (a*(349594463400+a*((758339400-8817900*(int64_t)a)*a-24434400900))+b*(51179091600+b*(35271600*(int64_t)b-2327925600))+(4761666000-105814800*(int64_t)c)*c+211629600*(int64_t)d+
    e*(38857000+e*((127400-1820*e)*e-3339700))+f*(7068880+f*(7280*f-393120))+(808080-21840*g)*g+43680*h+i*(9774+i*((54-i)*i-1091))+j*(2348+j*(4*j-168))+(348-12*k)*k+24*l-58629744984)/24;

#endif
}

uint64_t adrcenters(uint64_t x){
#if centercount==12
  uint64_t z = x % 1820; x /= 1820;
#endif
  uint64_t y = x % 4845; x /= 4845;

  uint64_t a = (45-sqrt(5+4*sqrt(255025-24*x)))/2;
  double bar = cbrtf(1147608+a*(1070442+a*(-74817+(2322-27*a)*a))-648*x+sqrt(1317004119936+x*(-1487299968+419904*x)+a*(2456895605472-1387292832*x
    +a*(974124899892+96962832*x+a*(-154845026676-3009312*x+a*(10506745305+a*(-405254016+a*(9431802+a*(-125388+729*a)))+34992*x))))));
  double btmp = 23-2/bar-bar/6;
  uint64_t b = btmp;
  if(b+1-btmp<0.00001 && (a*(39646+a*((86-a)*a-2771))+b*(5804+b*(4*b-264))<=24*x))b++;
  uint64_t c = (141-sqrt(9+a*(118938+a*((258-3*a)*a-8313))+b*(17412+b*(12*b-792))-72*x))/6;
  uint64_t d = (6648+a*(a*(2771+(a-86)*a)-39646)+b*((264-4*b)*b-5804)+c*(12*c-540)+24*x)/24;

  uint64_t e = (37-sqrt(5+4*sqrt(116281-24*y)))/2;
  double foo = cbrtf(627912+e*(576450+e*(-49545+(1890-27*e)*e))-648*y+sqrt(394273478016+y*(-813773952+419904*y)+e*(723919744800-747079200*y
    +e*(270074802420+64210320*y+e*(-54746923140-2449440*y+e*(4599780777+e*(-218408400+e*(6247530+e*(-102060+729*e)))+34992*y))))));
  double ftmp = 19-2/foo-foo/6;
  uint64_t f = ftmp; 
  if(f+1-ftmp<0.00001 && (e*(21350+e*((70-e)*e-1835))+f*(3884+f*(4*f-216))<=24*y))f++;
  uint64_t g = (117-sqrt(9+e*(64050+e*((210-3*e)*e-5505))+f*(11652+f*(12*f-648))-72*y))/6;
  uint64_t h = (4584+e*(e*(1835+(e-70)*e)-21350)+f*((216-4*f)*f-3884)+g*(12*g-444)+24*y)/24;

#if centercount==12
  uint64_t i = (29-sqrt(5+4*sqrt(43681-24*z)))/2;
  double jee  = cbrtf(294840+i*(263898+i*((1458-27*i)*i-29457))-648*z+sqrt(86930623872+z*(419904*z-382112640)+i*(155615372640-342011808*z+
    i*(52271950644+38176272*z+i*(i*(1621320057+i*(i*(3716442+i*(729*i-78732))-100147104)+34992*z)-14687533332-1889568*z)))));
  double jtmp = 15-2/jee-jee/6;
  uint64_t j = jtmp;
  if(j+1-jtmp<0.00001 && ((i*(9774+i*((54-i)*i-1091))+j*(2348+j*(4*j-168)))<=24*z))j++;
  uint64_t k = (93-sqrt(9+i*(29322+i*((162-3*i)*i-3273))+j*(7044+j*(12*j-504))-72*z))/6;
  uint64_t l = (2904+i*(i*(1091+(i-54)*i)-9774)+j*((168-4*j)*j-2348)+k*(12*k-348)+24*z)/24;
#endif
  uint64_t first[] = {a,b,c,d};
  uint64_t second[]= {e,f,g,h};

  for(uint8_t m=0;m<4;m++)
    for(uint8_t n=0;n<4;n++)
      if(first[n]<=second[m])
        second[m]++;
#if centercount==12
  uint64_t third[] = {i,j,k,l};
  uint8_t res[8];
  merge(first,first+4,second,second+4,res);

  for(uint8_t m=0;m<4;m++)
    for(uint8_t n=0;n<8;n++)
      if(res[n]<=third[m])
        third[m]++;
//do return in a loop, adjust the offset in centers=8 case everywhere else
  return (third[3]+32*(third[2]+32*(third[1]+32*(third[0]+32*(second[3]+32*(second[2]+32*(second[1]+32*(second[0]+32*(first[3]+32*(first[2]+32*(first[1]+32*first[0])))))))))));
#else
  return second[3]+32*(second[2]+32*(second[1]+32*(second[0]+32*(first[3]+32*(first[2]+32*(first[1]+32*first[0]))))));
#endif
}


uint8_t minDepth(const cube &Cube){

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
    poscenters(centerturn[3][Cube.center[12]],centerturn[3][Cube.center[13]],centerturn[3][Cube.center[14]],centerturn[3][Cube.center[15]],
      centerturn[3][Cube.center[16]],centerturn[3][Cube.center[17]],centerturn[3][Cube.center[18]],centerturn[3][Cube.center[19]],
      centerturn[3][Cube.center[20]],centerturn[3][Cube.center[21]],centerturn[3][Cube.center[22]],centerturn[3][Cube.center[23]]),
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
    uint8_t tmp=readhalfbyte(~table[1][address[i]/2],address[i]%2);
    if(max<tmp) max=tmp;}
  for(uint8_t i=1+24/centercount;i<1+24/centercount+24/cornercount;i++){
    uint8_t tmp=readhalfbyte(~table[2][address[i]/2],address[i]%2);
    if(max<tmp) max=tmp;}

  return max;
}
