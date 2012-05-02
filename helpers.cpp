int LoadFile(unsigned char* mem, string filename, int size) {
	fstream File(filename.c_str(), ios::in | ios::binary);
	if(!File.read(mem, size)) {File.clear(); return 1;} else return 0;  // return 1 in case of read error
}

int WriteFile(unsigned char* mem, string filename, int size) {
	fstream File(filename.c_str(), ios::out | ios::binary);
	if(!File.write(mem, size)) {File.clear(); return 1;} else return 0;
}

//Dies sollte zum macro werden.
unsigned char sethalfbyte(unsigned char a/*Eingangsbyte*/,unsigned char b/*Modifikation*/,bool c/*lower(0) or upper half(1)*/){
// return ((b<<4c) OR (a AND (240-225c)));}
}

//Dies sollte zum Macro werden.
unsigned char readhalfbyte(unsigned char a/*Eingangsbyte*/, bool b/*lower(0) or upper half(1)*/){
// return ((a AND (15+225c))<<4c);
}

//Wenn man dieses unsigned char-Sache iwie nur einmal schreiben muss, dann bitte entsprechend ändern.
int posedges(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g){
 if (a<b) b-=3;
 if (a<c) c-=3;
 if (b<c) c-=3;
 if (a<d) d-=3;
 if (b<d) d-=3; 
 if (c<d) d-=3;
 if (a<e) e-=3;
 if (b<e) e-=3;
 if (c<e) e-=3;
 if (d<e) e-=3;
 if (a<f) f-=3;
 if (b<f) f-=3;
 if (c<f) f-=3;
 if (d<f) f-=3;
 if (e<f) f-=3;
 if (a<g) g-=3;
 if (b<g) g-=3;
 if (c<g) g-=3;
 if (d<g) g-=3;
 if (e<g) g-=3;
 if (f<g) g-=3;
return (3674160*a+174960*b+9720*c+648*d+54*e+6*f+g);
}

int poscorners(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f){
 if (a<b) b--;
 if (a<c) c--;
 if (b<c) c--;
 if (a<d) d--;
 if (b<d) d--;
 if (c<d) d--;
 if (a<e) e--;
 if (b<e) e--;
 if (c<e) e--;
 if (d<e) e--;
 if (a<f) f--;
 if (b<f) f--;
 if (c<f) f--;
 if (d<f) f--;
 if (e<f) f--;
return (4037880*a+175560*b+7980*c+380*d+19*e+f);
}

int poscenters(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g, unsigned char h){
//Hier bitte a-h nach der Größen von a-h absteigend sortieren.
// Und denn? --Felix
//Danach wird mittels multiplikation und addition ein Integer zurückgegeben, weil die Mittelstückke nur leider nicht unterscheidbar sind, 
//ist das nicht so ganz leicht zu berechnen wie die anderen Sachen.
}
