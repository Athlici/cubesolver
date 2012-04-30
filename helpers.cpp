
bool CheckFile(string filename) {
  fstream File(filename.c_str());
  return File;
}

/* TODO
void LoadFile(Speicheradresse,Dateiname,Bytezahl){
Dein Teil mal wieder.
}
*/

//Dies muss zum macro werden.
unsigned char sethalfbyte(unsigned char a/*Eingangsbyte*/,unsigned char b/*Modifikation*/,bool c/*lower(0) or upper half(1)*/){
 return ((b<<4c) OR (a AND (240-225c)));
}

//Dies muss zum Macro werden.
unsigned char readhalfbyte(unsigned char a/*Eingangsbyte*/, bool b/*lower(0) or upper half(1)*/){
 return ((a AND (15+225c))<<4c);
}

//Wenn man dieses unsigned char-Sache iwie nur einmal schreiben muss, dann bitte entsprechend ändern.
int posedges(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g){
 if a<b b-=3;
 if a<c c-=3;
 if b<c c-=3;
 if a<d d-=3;
 if b<d d-=3; 
 if c<d d-=3;
 if a<e e-=3;
 if b<e e-=3;
 if c<e e-=3;
 if d<e e-=3;
 if a<f f-=3;
 if b<f f-=3;
 if c<f f-=3;
 if d<f f-=3;
 if e<f f-=3;
 if a<g g-=3;
 if b<g g-=3;
 if c<g g-=3;
 if d<g g-=3;
 if e<g g-=3;
 if f<g g-=3;
return (Xa+Xb+Xc+Xd+Xe+3f+g);
}

int poscorners(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f){
 if a<b b--;
 if a<c c--;
 if b<c c--;
 if a<d d--;
 if b<d d--;
 if c<d d--;
 if a<e e--;
 if b<e e--;
 if c<e e--;
 if d<e e--;
 if a<f f--;
 if b<f f--;
 if c<f f--;
 if d<f f--;
 if e<f f--;
return (Xa+Xb+Xc+Xd+Xe+f);
}

int poscenters(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g, unsigned char h){
//Hier bitte a-h nach der Größe von a nach h absteigend sortieren.
}
