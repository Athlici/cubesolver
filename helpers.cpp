
int ReadFile(char* mem, string filename, int size) {
	fstream File(filename.c_str(), ios::in | ios::binary);
	if(!File.read(mem, size)) {File.clear(); return 1;} else return 0;  // return 1 in case of read error
}

int WriteFile(char* mem, string filename, int size) {
	fstream File(filename.c_str(), ios::out | ios::binary);
	if(!File.write(mem, size)) {File.clear(); return 1;} else return 0;
}

/*
void sethalfbyte(Speicheradresse,Position*2,Wert){
4 bits setzen, die anderen unverändert lassen --> bithacks
}
*/

int posedges(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g, unsigned char h){
//Keine Ahnung bis jetzt.
}

int poscorners(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f){
//Bedingte dekrementierung, danach einfache Formel, welche ich gerade nicht wiederfinde.
}

int poscenters(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g, unsigned char h){
//Hier bitte a-h nach der Größen von a-h absteigend sortieren.
// Und denn? --Felix
}
