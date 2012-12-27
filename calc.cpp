inline unsigned char sethalfbyte(unsigned char a/*Eingangsbyte*/,unsigned char b/*Modifikation*/,unsigned char c/*lower(0) or upper half(1)*/){
  return ((b<<4*c) | (a & (240-225*c)));		//returns the upper part of the byte when c==1 otherwise the lower part
}

inline unsigned char readhalfbyte(unsigned char a/*Eingangsbyte*/, unsigned char b/*lower(0) or upper half(1)*/){
  return ((a & (15+225*b))>>4*b);			//sets the upper part of the byte when c==1 otherwise the lower part
}

int posedges(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g){
 unsigned char B=b,C=c,D=d,E=e,F=f,G=g; 		//calculates a unique linear position for every possible edgeposition

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
return (3674160*a+174960*b+9720*c+648*d+54*e+6*f+g);
}

int poscorners(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f){
 unsigned char B=b,C=c,D=d,E=e,F=f;			//the same for the corners

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
return (4037880*a+175560*b+7980*c+380*d+19*e+f);
}

int poscenters(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g, unsigned char h){
//and the same again for the centers, this is more difficult because 4 center pieces are inperceptible
//but therefore the memory usage is also reduced by a factor of 24.

  if (a>b){unsigned char tmp=b;b=a;a=tmp;}		//the values are sorted by size, each group of 4 elements on its own,
  if (b>c){unsigned char tmp=c;c=b;b=tmp;}		//with increasing size from a-d;e-h
  if (c>d){unsigned char tmp=d;d=c;c=tmp;}
  if (a>b){unsigned char tmp=b;b=a;a=tmp;}
  if (b>c){unsigned char tmp=c;c=b;b=tmp;}
  if (a>b){unsigned char tmp=b;b=a;a=tmp;}

  if (e>f){unsigned char tmp=f;f=e;e=tmp;}
  if (f>g){unsigned char tmp=g;g=f;f=tmp;}
  if (g>h){unsigned char tmp=h;h=g;g=tmp;}
  if (e>f){unsigned char tmp=f;f=e;e=tmp;}
  if (f>g){unsigned char tmp=g;g=f;f=tmp;}
  if (e>f){unsigned char tmp=f;f=e;e=tmp;}
 
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

  return (436050*a*a*a-4845*a*a*a*a-1279080*b*b+19380*b*b*b+4845*a*a*(12*b-3035)+29070*a*(7575-88*b+2*b*b-4*c)+2500020*c-58140*c*c
		-19380*b*(6*c-1451)+116280*d+25234*e-2051*e*e+e*e*e*(74-e)+3884*f-432*e*f+12*e*e*f-216*f*f+12*e*f*f+4*f*f*f+420*g
		-24*e*g-24*f*g-12*g*g+24*h)/24;		//This is the magic formula

}
