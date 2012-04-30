void getcenters() {
 centers = (char*) malloc(centersize);
 if(!LoadFile(centers,"centers",centersize)) {
   for(int i=0;i<centersize;i++) *(centers+i) = 255;
 }
}

void getedges() {
 edges   = (char*) malloc(edgesize);
 if(!LoadFile(edges,"edges",edgesize)) {
   *edges=240;
   for(int i=1;i<edgesize;i++) *(edges+i) = 255;
 }
}

void getcorners() {
 corners = (char*) malloc(cornersize);
 if (!LoadFile(corners,"corners",cornersize)) {
   for(int i=0;i<cornersize;i++) *(corners+i) = 255;	
 }
}
