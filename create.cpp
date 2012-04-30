void getcenters() {
 centers = (char*) malloc(centersize);  // TODO "centers" not declarated (and so on)
 if(!LoadFile(centers,"centers",centersize)) {
   for(int i=0;i<centersize;i++) *(centers+i) = 255;
 }
}

void getedges() {
 edges   = (char*) malloc(edgesize);
 if(!LoadFile(edges,"edges",edgesize)) {
   for(int i=0;i<edgesize;i++) *(edges+i) = 255;
 }
}

void getcorners() {
 corners = (char*) malloc(cornersize);
 if (!LoadFile(corners,"corners",cornersize)) {
   for(int i=0;i<cornersize;i++) *(corners+i) = 255;	
 }
}
