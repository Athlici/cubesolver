
bool CheckFile(string filename) {
  fstream File(filename.c_str());
  return File;
}

/* TODO
void LoadFile(Speicheradresse,Dateiname,Bytezahl){
Dein Teil mal wieder.
}

void sethalfbyte(Speicheradresse,Position*2,Wert){
4 bits setzen, die anderen unverändert lassen --> bithacks
}
*/

//Wenn man dieses unsigned char-Sache iwie nur einmal schreiben muss, dann bitte entsprechend ändern.

int posedges(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g, unsigned char h){
//Keine Ahnung bis jetzt.
}

int poscorners(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f){
//Bedingte dekrementierung, danach einfache Formel, welche ich gerade nicht wiederfinde.
}

int poscenters(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g, unsigned char h){
//Hier bitte a-h nach der Größen von a-h absteigend sortieren.
}
