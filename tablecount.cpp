const uint64_t tablecount[3] = {
    88179840,
  #if symred==0
    #if centercount==8
      51482970,
    #else
      93699005400,
    #endif
    #if cornercount==6
      96909120,
    #else
      29654190720
    #endif
  #else
    23861237400,1869678720
  #endif
};

#if tablecompression==1 //irellevant for now
uint8_t *cotab[3];
const uint64_t cotabsize[3] = {13,108089320,34977176};  //TODO: fix the sizes here as well
#endif
