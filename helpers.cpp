/*
int LoadFile(unsigned char* mem, string filename, int size) {
	fstream File(filename.c_str(), ios::in | ios::binary);
	if(!File.read(mem, size)) {File.clear(); return 1;} else return 0;  // return 1 in case of read error
}

int WriteFile(unsigned char* mem, string filename, int size) {
	fstream File(filename.c_str(), ios::out | ios::binary);
	if(!File.write(mem, size)) {File.clear(); return 1;} else return 0;
}
*/

/*inline*/ void turncube (unsigned char* CubePos,unsigned char* WritePos,unsigned char Move){
 *WritePos=edgeturn[Move][*CubePos];
 *(WritePos+1)=edgeturn[Move][*(CubePos+1)];
 *(WritePos+2)=edgeturn[Move][*(CubePos+2)];
 *(WritePos+3)=edgeturn[Move][*(CubePos+3)];
 *(WritePos+4)=edgeturn[Move][*(CubePos+4)];
 *(WritePos+5)=edgeturn[Move][*(CubePos+5)];
 *(WritePos+6)=edgeturn[Move][*(CubePos+6)];
 *(WritePos+7)=cornerturn[Move][*(CubePos+7)];
 *(WritePos+8)=cornerturn[Move][*(CubePos+8)];
 *(WritePos+9)=cornerturn[Move][*(CubePos+9)];
 *(WritePos+10)=cornerturn[Move][*(CubePos+10)];
 *(WritePos+11)=cornerturn[Move][*(CubePos+11)];
 *(WritePos+12)=cornerturn[Move][*(CubePos+12)];
 *(WritePos+13)=cornerturn[Move][*(CubePos+13)];
 *(WritePos+14)=cornerturn[Move][*(CubePos+14)];
 *(WritePos+15)=cornerturn[Move][*(CubePos+15)];
 *(WritePos+16)=cornerturn[Move][*(CubePos+16)];
 *(WritePos+17)=cornerturn[Move][*(CubePos+17)];
 *(WritePos+18)=cornerturn[Move][*(CubePos+18)];
 *(WritePos+19)=cornerturn[Move][*(CubePos+19)];
 *(WritePos+20)=cornerturn[Move][*(CubePos+20)];
 *(WritePos+21)=cornerturn[Move][*(CubePos+21)];
 *(WritePos+22)=cornerturn[Move][*(CubePos+22)];
 *(WritePos+23)=cornerturn[Move][*(CubePos+23)];
 *(WritePos+24)=cornerturn[Move][*(CubePos+24)];
 *(WritePos+25)=cornerturn[Move][*(CubePos+25)];
 *(WritePos+26)=cornerturn[Move][*(CubePos+26)];
 *(WritePos+27)=cornerturn[Move][*(CubePos+27)];
 *(WritePos+28)=cornerturn[Move][*(CubePos+28)];
 *(WritePos+29)=cornerturn[Move][*(CubePos+29)];
 *(WritePos+30)=cornerturn[Move][*(CubePos+30)];
 *(WritePos+31)=centerturn[Move][*(CubePos+31)];
 *(WritePos+32)=centerturn[Move][*(CubePos+32)];
 *(WritePos+33)=centerturn[Move][*(CubePos+33)];
 *(WritePos+34)=centerturn[Move][*(CubePos+34)];
 *(WritePos+35)=centerturn[Move][*(CubePos+35)];
 *(WritePos+36)=centerturn[Move][*(CubePos+36)];
 *(WritePos+37)=centerturn[Move][*(CubePos+37)];
 *(WritePos+38)=centerturn[Move][*(CubePos+38)];
 *(WritePos+39)=centerturn[Move][*(CubePos+39)];
 *(WritePos+40)=centerturn[Move][*(CubePos+40)];
 *(WritePos+41)=centerturn[Move][*(CubePos+41)];
 *(WritePos+42)=centerturn[Move][*(CubePos+42)];
 *(WritePos+43)=centerturn[Move][*(CubePos+43)];
 *(WritePos+44)=centerturn[Move][*(CubePos+44)];
 *(WritePos+45)=centerturn[Move][*(CubePos+45)];
 *(WritePos+46)=centerturn[Move][*(CubePos+46)];
 *(WritePos+47)=centerturn[Move][*(CubePos+47)];
 *(WritePos+48)=centerturn[Move][*(CubePos+48)];
 *(WritePos+49)=centerturn[Move][*(CubePos+49)];
 *(WritePos+50)=centerturn[Move][*(CubePos+50)];
 *(WritePos+51)=centerturn[Move][*(CubePos+51)];
 *(WritePos+52)=centerturn[Move][*(CubePos+52)];
 *(WritePos+53)=centerturn[Move][*(CubePos+53)];
 *(WritePos+54)=centerturn[Move][*(CubePos+54)];
}

/*inline*/ void movecube (unsigned char* CubePos,unsigned char* WritePos,unsigned char Move){
 *WritePos=edgemove[Move][*CubePos];
 *(WritePos+1)=edgemove[Move][*(CubePos+1)];
 *(WritePos+2)=edgemove[Move][*(CubePos+2)];
 *(WritePos+3)=edgemove[Move][*(CubePos+3)];
 *(WritePos+4)=edgemove[Move][*(CubePos+4)];
 *(WritePos+5)=edgemove[Move][*(CubePos+5)];
 *(WritePos+6)=edgemove[Move][*(CubePos+6)];
 *(WritePos+7)=cornermove[Move][*(CubePos+7)];
 *(WritePos+8)=cornermove[Move][*(CubePos+8)];
 *(WritePos+9)=cornermove[Move][*(CubePos+9)];
 *(WritePos+10)=cornermove[Move][*(CubePos+10)];
 *(WritePos+11)=cornermove[Move][*(CubePos+11)];
 *(WritePos+12)=cornermove[Move][*(CubePos+12)];
 *(WritePos+13)=cornermove[Move][*(CubePos+13)];
 *(WritePos+14)=cornermove[Move][*(CubePos+14)];
 *(WritePos+15)=cornermove[Move][*(CubePos+15)];
 *(WritePos+16)=cornermove[Move][*(CubePos+16)];
 *(WritePos+17)=cornermove[Move][*(CubePos+17)];
 *(WritePos+18)=cornermove[Move][*(CubePos+18)];
 *(WritePos+19)=cornermove[Move][*(CubePos+19)];
 *(WritePos+20)=cornermove[Move][*(CubePos+20)];
 *(WritePos+21)=cornermove[Move][*(CubePos+21)];
 *(WritePos+22)=cornermove[Move][*(CubePos+22)];
 *(WritePos+23)=cornermove[Move][*(CubePos+23)];
 *(WritePos+24)=cornermove[Move][*(CubePos+24)];
 *(WritePos+25)=cornermove[Move][*(CubePos+25)];
 *(WritePos+26)=cornermove[Move][*(CubePos+26)];
 *(WritePos+27)=cornermove[Move][*(CubePos+27)];
 *(WritePos+28)=cornermove[Move][*(CubePos+28)];
 *(WritePos+29)=cornermove[Move][*(CubePos+29)];
 *(WritePos+30)=cornermove[Move][*(CubePos+30)];
 *(WritePos+31)=edgemove[Move][*(CubePos+31)];
 *(WritePos+32)=edgemove[Move][*(CubePos+32)];
 *(WritePos+33)=edgemove[Move][*(CubePos+33)];
 *(WritePos+34)=edgemove[Move][*(CubePos+34)];
 *(WritePos+35)=edgemove[Move][*(CubePos+35)];
 *(WritePos+36)=edgemove[Move][*(CubePos+36)];
 *(WritePos+37)=edgemove[Move][*(CubePos+37)];
 *(WritePos+38)=edgemove[Move][*(CubePos+38)];
 *(WritePos+39)=edgemove[Move][*(CubePos+39)];
 *(WritePos+40)=edgemove[Move][*(CubePos+40)];
 *(WritePos+41)=edgemove[Move][*(CubePos+41)];
 *(WritePos+42)=edgemove[Move][*(CubePos+42)];
 *(WritePos+43)=edgemove[Move][*(CubePos+43)];
 *(WritePos+44)=edgemove[Move][*(CubePos+44)];
 *(WritePos+45)=edgemove[Move][*(CubePos+45)];
 *(WritePos+46)=edgemove[Move][*(CubePos+46)];
 *(WritePos+47)=edgemove[Move][*(CubePos+47)];
 *(WritePos+48)=edgemove[Move][*(CubePos+48)];
 *(WritePos+49)=edgemove[Move][*(CubePos+49)];
 *(WritePos+50)=edgemove[Move][*(CubePos+50)];
 *(WritePos+51)=edgemove[Move][*(CubePos+51)];
 *(WritePos+52)=edgemove[Move][*(CubePos+52)];
 *(WritePos+53)=edgemove[Move][*(CubePos+53)];
 *(WritePos+54)=edgemove[Move][*(CubePos+54)];
}

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
//and the same again for the centers, this is more difficult because 4 center pieces are inperceptible and therefore the memory usage is reduced by 24.

//Hier bitte a-d und e-h der Größe nach aufsteigend sortieren.
 
  if (h>d) h--;
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

  h-=g;
  d-=c;
  g-=f;
  c-=b;
  f-=e;
  b-=a;

  return a+b+c+d+e+f+g+h;//DUMMY
}

