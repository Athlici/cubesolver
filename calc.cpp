inline uint8_t sethalfbyte(uint8_t a/*Eingangsbyte*/,uint8_t b/*Modifikation*/,uint8_t c/*lower(0) or upper half(1)*/){
  return (b<<4*c)|(a&(240-225*c));			//returns the upper part of the byte when c==1 otherwise the lower part
}

inline uint8_t readhalfbyte(uint8_t a/*Eingangsbyte*/, uint8_t c/*lower(0) or upper half(1)*/){
  return (a>>4*c)&15;					//sets the upper part of the byte when c==1 otherwise the lower part
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

uint64_t posedges(uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g){
  uint8_t B=b,C=c,D=d,E=e,F=f,G=g; 		//calculates a unique linear position for every possible edgeposition

  if (a<B) b-=3;
  if (a<C) c-=3;
  if (B<C) c-=3;
  if (a<D) d-=3;
  if (B<D) d-=3; 
  if (C<D) d-=3;
  if (a<E) e-=3;
  if (B<E) e-=3;
  if (C<E) e-=3;
  if (D<E) e-=3;
  if (a<F) f-=3;
  if (B<F) f-=3;
  if (C<F) f-=3;
  if (D<F) f-=3;
  if (E<F) f-=3;
  if (a<G) g-=3;
  if (B<G) g-=3;
  if (C<G) g-=3;
  if (D<G) g-=3;
  if (E<G) g-=3;
  if (F<G) g-=3;
  return (g+6*(f+9*(e+12*(d+15*(c+18*(b+21*a))))));
}

uint64_t adredges(uint64_t x){
  uint64_t g = x % 6; x /= 6;
  uint64_t f = x % 9; x /= 9;
  uint64_t e = x % 12; x /= 12;
  uint64_t d = x % 15; x /= 15;
  uint64_t c = x % 18; x /= 18;
  uint64_t b = x % 21; x /= 21;
  uint64_t a = x;

  if(f<=g) g+=3;
  if(e<=g) g+=3;
  if(d<=g) g+=3;
  if(c<=g) g+=3;
  if(b<=g) g+=3;
  if(a<=g) g+=3;
  if(e<=f) f+=3;
  if(d<=f) f+=3;
  if(c<=f) f+=3;
  if(b<=f) f+=3;
  if(a<=f) f+=3;
  if(d<=e) e+=3;
  if(c<=e) e+=3;
  if(b<=e) e+=3;
  if(a<=e) e+=3;
  if(c<=d) d+=3;
  if(b<=d) d+=3;
  if(a<=d) d+=3;
  if(b<=c) c+=3;
  if(a<=c) c+=3;
  if(a<=b) b+=3;

  return (g+256*(f+256*(e+256*(d+256*(c+256*(b+256*a))))));
}

uint64_t poscorners(uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f){
 uint8_t B=b,C=c,D=d,E=e,F=f;			//the same for the corners

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
return (f+19*(e+20*(d+21*(c+22*(b+23*a)))));
}

uint64_t adrcorners(uint64_t x){
  uint64_t f = x % 19; x /= 19;                         //Do a simple base conversion, could be done in a loop, but that would need an array
  uint64_t e = x % 20; x /= 20;
  uint64_t d = x % 21; x /= 21;
  uint64_t c = x % 22; x /= 22;
  uint64_t b = x % 23; x /= 23;
  uint64_t a = x;
  
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

  return (f+256*(e+256*(d+256*(c+256*(b+256*a)))));

}

uint64_t poscenters(uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g, uint8_t h){
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

  if (h>d) h--;						//decrease some values of the secondary positions, if these are already taken
  if (h>c) h--;
  if (g>d) g--;
  if (h>b) h--;
  if (f>d) f--;
  if (g>c) g--;
  if (h>a) h--;
  if (e>d) e--;
  if (f>c) f--;
  if (g>b) g--;
  if (e>c) e--;
  if (f>b) f--;
  if (g>a) g--;
  if (e>b) e--;
  if (f>a) f--;
  if (e>a) e--;

  h-=g;							//decrease every value so that the magic formula can be applied
  d-=c;
  g-=f;
  c-=b;
  f-=e;
  b-=a;

  h--;
  g--;
  f--;
  d--;
  c--;
  b--;

//  return 4842-(1615*(a*a*a*a-90*a*a*a+a*a*(3035-12*b)-6*a*(7575-88*b+2*b*b-4*c)-4*(-66*b*b+b*b*b+b*(1451-6*c)+129*c-3*c*c+6*d)))/8- 
//     ((e-17)*(1094*e-57*e*e+e*e*e-7104))/24+((1+f)*(1032+3*e*e+3*e*(f-37)-55*f+f*f))/6-((1+g)*(2*e+2*f+g-36))/2+h;
  return (b*(28120380+b*(19380*b-1279080)-116280*c)+a*(220205250+b*(58140*b-2558160)+a*((436050-4845*a)*a+58140*b-14704575)-116280*c)+
   (2500020-58140*c)*c+116280*d+f*(3884+f*(4*f-216)-24*g)+e*(25234+f*(12*f-432)+e*((74-e)*e+12*f-2051)-24*g)+(420-12*g)*g+24*h)/24;
// This is the Horner-Form of the commented Formula, hopefully faster to calculate
}

uint8_t minDepth(cube Cube){

  uint64_t address[8]={posedges(Cube.edge[0],Cube.edge[1],Cube.edge[2],Cube.edge[3],Cube.edge[4],Cube.edge[5],Cube.edge[6]),
    poscorners(Cube.corner[0],Cube.corner[1],Cube.corner[2],Cube.corner[3],Cube.corner[4],Cube.corner[5]),
    poscorners(cornerturn[0][Cube.corner[17]],cornerturn[0][Cube.corner[16]],cornerturn[0][Cube.corner[7]],cornerturn[0][Cube.corner[6]],
      cornerturn[0][Cube.corner[14]],cornerturn[0][Cube.corner[15]]),
    poscorners(cornerturn[1][Cube.corner[11]],cornerturn[1][Cube.corner[10]],cornerturn[1][Cube.corner[21]],cornerturn[1][Cube.corner[20]],
      cornerturn[1][Cube.corner[8]],cornerturn[1][Cube.corner[9]]),
    poscorners(cornerturn[2][Cube.corner[18]],cornerturn[2][Cube.corner[19]],cornerturn[2][Cube.corner[23]],cornerturn[2][Cube.corner[22]],
      cornerturn[2][Cube.corner[13]],cornerturn[2][Cube.corner[12]]),
    poscenters(Cube.center[0],Cube.center[1],Cube.center[2],Cube.center[3],Cube.center[8],Cube.center[9],Cube.center[10],Cube.center[11]),
    poscenters(centerturn[3][Cube.center[4]],centerturn[3][Cube.center[5]],centerturn[3][Cube.center[6]],centerturn[3][Cube.center[7]],
      centerturn[3][Cube.center[12]],centerturn[3][Cube.center[13]],centerturn[3][Cube.center[14]],centerturn[3][Cube.center[15]]),
    poscenters(centerturn[0][Cube.center[16]],centerturn[0][Cube.center[17]],centerturn[0][Cube.center[18]],centerturn[0][Cube.center[19]],
      centerturn[0][Cube.center[20]],centerturn[0][Cube.center[21]],centerturn[0][Cube.center[22]],centerturn[0][Cube.center[23]])};

  uint8_t max=255;
  for(uint8_t i=0;i<8;i++){
    uint8_t tmp=readhalfbyte(~table[(i+3)/4][address[i]/2],address[0]%2);
    if(max>tmp) max=tmp;}
  
  return max;
}
