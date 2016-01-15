inline uint8_t set2bit(uint8_t a/*Eingangsbyte*/,uint8_t b/*Modifikation*/,uint8_t c/*which 2bit*/){
  return (b<<2*c)|(a&(255-(3<<2*c)));
}

inline uint8_t read2bit(uint8_t a/*Eingangsbyte*/, uint8_t c/*which 2bit*/){
  return (a>>2*c)&3;
}

inline uint8_t sethalfbyte(uint8_t a/*Eingangsbyte*/,uint8_t b/*Modifikation*/,uint8_t c/*lower(0) or upper half(1)*/){
  return (b<<4*c)|(a&(240-225*c));                      //returns the upper part of the byte when c==1 otherwise the lower part
}

inline uint8_t readhalfbyte(uint8_t a/*Eingangsbyte*/, uint8_t c/*lower(0) or upper half(1)*/){
  return (a>>4*c)&15;                                   //sets the upper part of the byte when c==1 otherwise the lower part
}

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
//Rewriting the routines in assembler to only use registers could furthermore improve speed.

uint64_t posedges(uint8_t A,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g){
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
  uint64_t g = x % 6; x /= 6;
  uint64_t f = x % 9; x /= 9;
  uint64_t e = x % 12; x /= 12;
  uint64_t d = x % 15; x /= 15;
  uint64_t c = x % 18; x /= 18;
  uint64_t b = x % 21; x /= 21;
  uint64_t a = x;

  if(f/3<=g/3) g+=3;
  if(e/3<=g/3) g+=3;
  if(d/3<=g/3) g+=3;
  if(c/3<=g/3) g+=3;
  if(b/3<=g/3) g+=3;
  if(a/3<=g/3) g+=3;
  if(e/3<=f/3) f+=3;
  if(d/3<=f/3) f+=3;
  if(c/3<=f/3) f+=3;
  if(b/3<=f/3) f+=3;
  if(a/3<=f/3) f+=3;
  if(d/3<=e/3) e+=3;
  if(c/3<=e/3) e+=3;
  if(b/3<=e/3) e+=3;
  if(a/3<=e/3) e+=3;
  if(c/3<=d/3) d+=3;
  if(b/3<=d/3) d+=3;
  if(a/3<=d/3) d+=3;
  if(b/3<=c/3) c+=3;
  if(a/3<=c/3) c+=3;
  if(a/3<=b/3) b+=3;

  return (g+256*(f+256*(e+256*(d+256*(c+256*(b+256*a))))));
}

uint64_t poscorners(uint64_t a,uint64_t b,uint64_t c,uint64_t d,uint64_t e,uint64_t f,uint64_t g,uint64_t h){
 uint64_t B=b,C=c,D=d,E=e,F=f,G=g,H=h;			//the same for the corners

 if (a<B) b--;		//the order might be changed by using <= signs
 if (a<C) c--;
 if (B<C) c--;
 if (a<D) d--;
 if (B<D) d--;
 if (C<D) d--;
 if (a<E) e--;
 if (B<E) e--;
 if (C<E) e--;
 if (D<E) e--;
 if (a<F) f--;
 if (B<F) f--;
 if (C<F) f--;
 if (D<F) f--;
 if (E<F) f--;
 if (a<G) g--;
 if (B<G) g--;
 if (C<G) g--;
 if (D<G) g--;
 if (E<G) g--;
 if (F<G) g--;
 if (a<H) h--;
 if (B<H) h--;
 if (C<H) h--;
 if (D<H) h--;
 if (E<H) h--;
 if (F<H) h--;
 if (G<H) h--;

 return (h+17*(g+18*(f+19*(e+20*(d+21*(c+22*(b+23*a)))))));
}

uint64_t adrcorners(uint64_t x){
/*
  uint8_t elem[8];
  for(uint8_t i=0;i<8;i++){
    elem[i] = x % (i+17);
    x /= i+17;
  }

  for(uint8_t i=7;i>0;i--)
    for(int8_t j=i-1;j>=0;j--)
      if(elem[j]<=elem[i])elem[i]++;

  uint64_t result=0;
  for(uint8_t i=0;i<8;i++)
    result+=elem[i]<<(8*i);

  return result;
*/
  uint64_t h = x % 17; x /= 17;
  uint64_t g = x % 18; x /= 18;
  uint64_t f = x % 19; x /= 19;                         //Do a simple base conversion, could be done in a loop, but that would need an array
  uint64_t e = x % 20; x /= 20;
  uint64_t d = x % 21; x /= 21;
  uint64_t c = x % 22; x /= 22;
  uint64_t b = x % 23; x /= 23;
  uint64_t a = x;

  if(g<=h) h++;
  if(f<=h) h++;
  if(e<=h) h++;
  if(d<=h) h++;
  if(c<=h) h++;
  if(b<=h) h++;
  if(a<=h) h++;
  if(f<=g) g++;
  if(e<=g) g++;
  if(d<=g) g++;
  if(c<=g) g++;
  if(b<=g) g++;
  if(a<=g) g++;
  if(e<=f) f++;
  if(d<=f) f++;
  if(c<=f) f++;
  if(b<=f) f++;
  if(a<=f) f++;
  if(d<=e) e++;
  if(c<=e) e++;
  if(b<=e) e++;
  if(a<=e) e++;
  if(c<=d) d++;
  if(b<=d) d++;
  if(a<=d) d++;
  if(b<=c) c++;
  if(a<=c) c++;
  if(a<=b) b++;

  return (h+256*(g+256*(f+256*(e+256*(d+256*(c+256*(b+256*a)))))));

}

uint64_t poscenters(uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g,uint8_t h,uint8_t i,uint8_t j,uint8_t k,uint8_t l){
//and the same again for the centers, this is more difficult because 4 center pieces are equivalent
//but therefore the memory usage is also reduced by a factor of 24^3

  if (a>b)swap(a,b);              			//the values are sorted by size, each group of 4 elements on its own,
  if (c>d)swap(c,d);              			//with increasing size from a-d;e-h;i-l
  if (a>c)swap(a,c);
  if (b>d)swap(b,d);
  if (b>c)swap(b,c);

  if (e>f)swap(e,f);
  if (g>h)swap(g,h);
  if (e>g)swap(e,g);
  if (f>h)swap(f,h);
  if (f>g)swap(f,g);

  if (i>j)swap(i,j);
  if (k>l)swap(k,l);
  if (i>k)swap(i,k);
  if (j>l)swap(j,l);
  if (j>k)swap(j,k);

  decdependently(a,b,c,d,e,f,g,h,i,j,k,l);		//do all the combinatorical magic in an ugly function.

//  cout << a+0 << ";" << b+0 << ";" << c+0 << ";" << d+0 << ";" << e+0 << ";" << f+0 << ";" << g+0 << ";" << h+0 << ";" << i+0 << ";" << j+0 << ";" << k+0 << ";" << l+0 << "\n";

  return (a*(349594463400+a*((758339400-8817900*(int64_t)a)*a-24434400900))+b*(51179091600+b*(35271600*(int64_t)b-2327925600))+(4761666000-105814800*(int64_t)c)*c+211629600*(int64_t)d+
    e*(38857000+e*((127400-1820*e)*e-3339700))+f*(7068880+f*(7280*f-393120))+(808080-21840*g)*g+43680*h+i*(9774+i*((54-i)*i-1091))+j*(2348+j*(4*j-168))+(348-12*k)*k+24*l-58629744984)/24;

}

uint64_t adrcenters(uint64_t x){
  uint64_t z = x % 1820; x /= 1820;
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

  uint64_t i = (29-sqrt(5+4*sqrt(43681-24*z)))/2;
  double jee  = cbrtf(294840+i*(263898+i*((1458-27*i)*i-29457))-648*z+sqrt(86930623872+z*(419904*z-382112640)+i*(155615372640-342011808*z+
    i*(52271950644+38176272*z+i*(i*(1621320057+i*(i*(3716442+i*(729*i-78732))-100147104)+34992*z)-14687533332-1889568*z)))));
  double jtmp = 15-2/jee-jee/6;
  uint64_t j = jtmp;
  if(j+1-jtmp<0.00001 && ((i*(9774+i*((54-i)*i-1091))+j*(2348+j*(4*j-168)))<=24*z))j++;
  uint64_t k = (93-sqrt(9+i*(29322+i*((162-3*i)*i-3273))+j*(7044+j*(12*j-504))-72*z))/6;
  uint64_t l = (2904+i*(i*(1091+(i-54)*i)-9774)+j*((168-4*j)*j-2348)+k*(12*k-348)+24*z)/24;

  uint64_t first[] = {a,b,c,d};
  uint64_t second[]= {e,f,g,h};
  uint64_t third[] = {i,j,k,l};

  for(uint8_t m=0;m<4;m++)
    for(uint8_t n=0;n<4;n++)
      if(first[n]<=second[m])
        second[m]++;

  uint8_t res[8];
  merge(first,first+4,second,second+4,res);

  for(uint8_t m=0;m<4;m++)
    for(uint8_t n=0;n<8;n++)
      if(res[n]<=third[m])
        third[m]++;
/*
  for(uint8_t m=0;m<4;m++)cout << first[m]+0 << ";";
  for(uint8_t m=0;m<4;m++)cout << second[m]+0 << ";";
  for(uint8_t m=0;m<4;m++)cout << third[m]+0 << ";";
  cout << "\n";
*/
  return (third[3]+32*(third[2]+32*(third[1]+32*(third[0]+32*(second[3]+32*(second[2]+32*(second[1]+32*(second[0]+32*(first[3]+32*(first[2]+32*(first[1]+32*first[0])))))))))));

}

uint64_t centerequivalence(uint8_t *oc,uint16_t m){
  uint8_t c[12];
  for(uint8_t i=0;i<12;i++)
    c[i]=oc[i];
  for(uint8_t i=0;i<6;i++)
    if((m>>(2*i))&3)
      for(uint8_t j=0;j<12;j++)
        c[j]=centermove[3*i+6*((i+1)/2)+((m>>(2*i))&3)-1][c[j]];
  return poscenters(c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7],c[8],c[9],c[10],c[11]);
}

uint8_t minDepth(cube &Cube){

  uint64_t address[6]={posedges(Cube.edge[0],Cube.edge[1],Cube.edge[2],Cube.edge[3],Cube.edge[4],Cube.edge[5],Cube.edge[6]),  //TODO:adjust the covering
    poscenters(Cube.center[0],Cube.center[1],Cube.center[2],Cube.center[3],Cube.center[4],Cube.center[5],Cube.center[6],Cube.center[7],Cube.center[8],Cube.center[9],Cube.center[10],Cube.center[11]),
    poscenters(centerturn[3][Cube.center[12]],centerturn[3][Cube.center[13]],centerturn[3][Cube.center[14]],centerturn[3][Cube.center[15]],
      centerturn[3][Cube.center[16]],centerturn[3][Cube.center[17]],centerturn[3][Cube.center[18]],centerturn[3][Cube.center[19]],
      centerturn[3][Cube.center[20]],centerturn[3][Cube.center[21]],centerturn[3][Cube.center[22]],centerturn[3][Cube.center[23]]),
    poscorners(Cube.corner[0],Cube.corner[1],Cube.corner[5],Cube.corner[4],Cube.corner[8],Cube.corner[9],Cube.corner[10],Cube.corner[11]),
    poscorners(cornerturn[15][Cube.corner[2]],cornerturn[15][Cube.corner[3]],cornerturn[15][Cube.corner[7]],cornerturn[15][Cube.corner[6]],
      cornerturn[15][Cube.corner[21]],cornerturn[15][Cube.corner[20]],cornerturn[15][Cube.corner[23]],cornerturn[15][Cube.corner[22]]),
    poscorners(cornerturn[0][Cube.corner[17]],cornerturn[0][Cube.corner[16]],cornerturn[0][Cube.corner[15]],cornerturn[0][Cube.corner[14]],
      cornerturn[0][Cube.corner[13]],cornerturn[0][Cube.corner[12]],cornerturn[0][Cube.corner[19]],cornerturn[0][Cube.corner[18]])};

  uint8_t max=0;
  for(uint8_t i=0;i<6;i++){
    uint8_t tmp=readhalfbyte(~table[(i+2)/3][address[i]/2],address[i]%2);		//TODO: FIX THE MAGIC FORMULA
    if(max<tmp) max=tmp;
  }
  return max;
}

//cout << Cube.corner[0]+0 << ";" << Cube.corner[1]+0 << ";" << Cube.corner[5]+0 << ";" << Cube.corner[4]+0 << ";"
//     << Cube.corner[8]+0 << ";" << Cube.corner[9]+0 << ";" << Cube.corner[10]+0 << ";" << Cube.corner[11]+0 << "\n";
//for(uint8_t i=0;i<23;i++)
//  cout << i+0 << ":" << cornerturn[i][Cube.corner[2]]+0 << ";" << cornerturn[i][Cube.corner[3]]+0 << ";" << cornerturn[i][Cube.corner[7]]+0 << ";" << cornerturn[i][Cube.corner[6]]+0 << ";"
//       << cornerturn[i][Cube.corner[21]]+0 << ";" << cornerturn[i][Cube.corner[20]]+0 << ";" << cornerturn[i][Cube.corner[23]]+0 << ";" << cornerturn[i][Cube.corner[22]]+0 << "\n";
//for(uint8_t i=0;i<23;i++)
//  cout << i+0 << ":" << cornerturn[i][Cube.corner[17]]+0 << ";" << cornerturn[i][Cube.corner[16]]+0 << ";" << cornerturn[i][Cube.corner[15]]+0 << ";" << cornerturn[i][Cube.corner[14]]+0 << ";"
//       << cornerturn[i][Cube.corner[13]]+0 << ";" << cornerturn[i][Cube.corner[12]]+0 << ";" << cornerturn[i][Cube.corner[19]]+0 << ";" << cornerturn[i][Cube.corner[18]]+0 << "\n";
