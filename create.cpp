void getcenters(void){
 centers = (char*) malloc(centersize);
 if (CheckFile("centers")) /*LoadFile(centers,"centers",centersize)*/;
 else {
   for(int i=0;i<centersize;i++) *(centers+i) =255;
 }
}

void getedges(void){
 edges   = (char*) malloc(edgesize);
 if (CheckFile("edges")) /*LoadFile(edges,"edges",edgesize)*/;
 else {
   *edges=240;
   for(int i=1;i<edgesize;i++) *(edges+i) =255;

 }
}

void getcorners(void){
 corners = (char*) malloc(cornersize);
 if (CheckFile("corners")) /*LoadFile(corners,"corners",cornersize)*/;
 else {
   for(int i=0;i<cornersize;i++) *(corners+i) =255;
	
 }
}
