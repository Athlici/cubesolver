void getcenters() {
 centers = (char*) malloc(centersize);  // TODO "centers" not declarated
 if (CheckFile("centers")) /*LoadFile(centers,"centers",centersize)*/;
 else {
   for(int i=0;i<centersize;i++) *(centers+i) =255;
 }
}

void getedges() {
 edges   = (char*) malloc(edgesize);
 if (CheckFile("edges")) /*LoadFile(edges,"edges",edgesize)*/;
 else {
   for(int i=0;i<edgesize;i++) *(edges+i) =255;
 }
}

void getcorners() {
 corners = (char*) malloc(cornersize);
 if (CheckFile("corners")) /*LoadFile(corners,"corners",cornersize)*/;
 else {
   for(int i=0;i<cornersize;i++) *(corners+i) =255;
	
 }
}
