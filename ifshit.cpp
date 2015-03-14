#if centercount==8
void decdependently(const uint8_t &a,const uint8_t &b,const uint8_t &c,const uint8_t &d,
		          uint8_t &e,      uint8_t &f,      uint8_t &g,      uint8_t &h){
  if(d<h){
    if(d<g){
      if(d<f){
        if(d<e){e-=4;} else {
          if(c<e){e-=3;} else {
            if(b<e){e-=2;} else {
              if(a<e){e-=1;} 
            }
          }
        }
        f-=4;} else {
        if(c<f){
          if(c<e){e-=3;} else {
            if(b<e){e-=2;} else {
              if(a<e){e-=1;} 
            }
          }
          f-=3;} else {
          if(b<f){
            if(b<e){e-=2;} else {
              if(a<e){e-=1;} 
            }
            f-=2;} else {
            if(a<f){
              if(a<e){e-=1;} f-=1;} 
          }
        }
      }
      g-=4;} else {
      if(c<g){
        if(c<f){
          if(c<e){e-=3;} else {
            if(b<e){e-=2;} else {
              if(a<e){e-=1;} 
            }
          }
          f-=3;} else {
          if(b<f){
            if(b<e){e-=2;} else {
              if(a<e){e-=1;} 
            }
            f-=2;} else {
            if(a<f){
              if(a<e){e-=1;} 
            f-=1;} 
          }
        }
        g-=3;} else {
        if(b<g){
          if(b<f){
            if(b<e){e-=2;} else {
              if(a<e){e-=1;} 
            }
            f-=2;} else {
            if(a<f){
              if(a<e){e-=1;} 
            f-=1;} 
          }
          g-=2;} else {
          if(a<g){
            if(a<f){
              if(a<e){e-=1;} 
            f-=1;} 
          g-=1;} 
        }
      }
    }
    h-=4;} else {
    if(c<h){
      if(c<g){
        if(c<f){
          if(c<e){e-=3;} else {
            if(b<e){e-=2;} else {
              if(a<e){e-=1;} 
            }
          }
          f-=3;} else {
          if(b<f){
            if(b<e){e-=2;} else {
              if(a<e){e-=1;} 
            }
            f-=2;} else {
            if(a<f){
              if(a<e){e-=1;} 
            f-=1;} 
          }
        }
        g-=3;} else {
        if(b<g){
          if(b<f){
            if(b<e){e-=2;} else {
              if(a<e){e-=1;} 
            }
            f-=2;} else {
            if(a<f){
              if(a<e){e-=1;} 
            f-=1;} 
          }
          g-=2;} else {
          if(a<g){
            if(a<f){
              if(a<e){e-=1;} 
            f-=1;} 
          g-=1;} 
        }
      }
      h-=3;} else {
      if(b<h){
        if(b<g){
          if(b<f){
            if(b<e){e-=2;} else {
              if(a<e){e-=1;} 
            }
            f-=2;} else {
            if(a<f){
              if(a<e){e-=1;} 
            f-=1;} 
          }g-=2;} else {
          if(a<g){
            if(a<f){
              if(a<e){e-=1;} 
            f-=1;} 
          g-=1;} 
        }
        h-=2;} else {
        if(a<h){
          if(a<g){
            if(a<f){
              if(a<e){e-=1;} 
            f-=1;} 
          g-=1;} 
        h-=1;} 
      }
    }
  }
}
#else
void v(const uint8_t &a,const uint8_t &b,const uint8_t &c,const uint8_t &d,
       const uint8_t &e,const uint8_t &f,const uint8_t &g,const uint8_t &h,
             uint8_t &i,      uint8_t &j,      uint8_t &k,      uint8_t &l){

if(h<l){if(h<k){if(h<j){if(h<i){i-=8;} else {
if(g<i){i-=7;} else {
if(f<i){i-=6;} else {
if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}}}}};j-=8;} else {
if(g<j){if(g<i){i-=7;} else {
if(f<i){i-=6;} else {
if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}}}};j-=7;} else {
if(f<j){if(f<i){i-=6;} else {
if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}}};j-=6;} else {
if(e<j){if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}};j-=5;} else {
if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}}}}}};k-=8;} else {
if(g<k){if(g<j){if(g<i){i-=7;} else {
if(f<i){i-=6;} else {
if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}}}};j-=7;} else {
if(f<j){if(f<i){i-=6;} else {
if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}}};j-=6;} else {
if(e<j){if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}};j-=5;} else {
if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}}}}};k-=7;} else {
if(f<k){if(f<j){if(f<i){i-=6;} else {
if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}}};j-=6;} else {
if(e<j){if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}};j-=5;} else {
if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}}}};k-=6;} else {
if(e<k){if(e<j){if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}};j-=5;} else {
if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}}};k-=5;} else {
if(d<k){if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}};k-=4;} else {
if(c<k){if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}};k-=3;} else {
if(b<k){if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}};k-=2;} else {
if(a<k){if(a<j){if(a<i){i-=1;};j-=1;};k-=1;}}}}}}}};l-=8;} else {
if(g<l){if(g<k){if(g<j){if(g<i){i-=7;} else {
if(f<i){i-=6;} else {
if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}}}};j-=7;} else {
if(f<j){if(f<i){i-=6;} else {
if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}}};j-=6;} else {
if(e<j){if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}};j-=5;} else {
if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}}}}};k-=7;} else {
if(f<k){if(f<j){if(f<i){i-=6;} else {
if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}}};j-=6;} else {
if(e<j){if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}};j-=5;} else {
if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}}}};k-=6;} else {
if(e<k){if(e<j){if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}};j-=5;} else {
if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}}};k-=5;} else {
if(d<k){if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}};k-=4;} else {
if(c<k){if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}};k-=3;} else {
if(b<k){if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}};k-=2;} else {
if(a<k){if(a<j){if(a<i){i-=1;};j-=1;};k-=1;}}}}}}};l-=7;} else {
if(f<l){if(f<k){if(f<j){if(f<i){i-=6;} else {
if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}}};j-=6;} else {
if(e<j){if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}};j-=5;} else {
if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}}}};k-=6;} else {
if(e<k){if(e<j){if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}};j-=5;} else {
if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}}};k-=5;} else {
if(d<k){if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}};k-=4;} else {
if(c<k){if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}};k-=3;} else {
if(b<k){if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}};k-=2;} else {
if(a<k){if(a<j){if(a<i){i-=1;};j-=1;};k-=1;}}}}}};l-=6;} else {
if(e<l){if(e<k){if(e<j){if(e<i){i-=5;} else {
if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}}};j-=5;} else {
if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}}};k-=5;} else {
if(d<k){if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}};k-=4;} else {
if(c<k){if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}};k-=3;} else {
if(b<k){if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}};k-=2;} else {
if(a<k){if(a<j){if(a<i){i-=1;};j-=1;};k-=1;}}}}};l-=5;} else {
if(d<l){if(d<k){if(d<j){if(d<i){i-=4;} else {
if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}}};j-=4;} else {
if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}}};k-=4;} else {
if(c<k){if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}};k-=3;} else {
if(b<k){if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}};k-=2;} else {
if(a<k){if(a<j){if(a<i){i-=1;};j-=1;};k-=1;}}}};l-=4;} else {
if(c<l){if(c<k){if(c<j){if(c<i){i-=3;} else {
if(b<i){i-=2;} else {
if(a<i){i-=1;}}};j-=3;} else {
if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}}};k-=3;} else {
if(b<k){if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}};k-=2;} else {
if(a<k){if(a<j){if(a<i){i-=1;};j-=1;};k-=1;}}};l-=3;} else {
if(b<l){if(b<k){if(b<j){if(b<i){i-=2;} else {
if(a<i){i-=1;}};j-=2;} else {
if(a<j){if(a<i){i-=1;};j-=1;}};k-=2;} else {
if(a<k){if(a<j){if(a<i){i-=1;};j-=1;};k-=1;}};l-=2;} else {
if(a<l){if(a<k){if(a<j){if(a<i){i-=1;};j-=1;};k-=1;};l-=1;}}}}}}}}

}

void decdependently(const uint8_t &a,const uint8_t &b,const uint8_t &c,const uint8_t &d,uint8_t &e,uint8_t &f,uint8_t &g,uint8_t &h,uint8_t &i,uint8_t &j,uint8_t &k,uint8_t &l){

if(d<h){if(d<g){if(d<f){if(d<e){v(a,b,c,d,e,f,g,h,i,j,k,l);e-=4;} else {
if(c<e){v(a,b,c,e,d,f,g,h,i,j,k,l);e-=3;} else {
if(b<e){v(a,b,e,c,d,f,g,h,i,j,k,l);e-=2;} else {
if(a<e){v(a,e,b,c,d,f,g,h,i,j,k,l);e-=1;} else {
v(e,a,b,c,d,f,g,h,i,j,k,l);}}}};f-=4;} else {
if(c<f){if(c<e){v(a,b,c,e,f,d,g,h,i,j,k,l);e-=3;} else {
if(b<e){v(a,b,e,c,f,d,g,h,i,j,k,l);e-=2;} else {
if(a<e){v(a,e,b,c,f,d,g,h,i,j,k,l);e-=1;} else {
v(e,a,b,c,f,d,g,h,i,j,k,l);}}};f-=3;} else {
if(b<f){if(b<e){v(a,b,e,f,c,d,g,h,i,j,k,l);e-=2;} else {
if(a<e){v(a,e,b,f,c,d,g,h,i,j,k,l);e-=1;} else {
v(e,a,b,f,c,d,g,h,i,j,k,l);}};f-=2;} else {
if(a<f){if(a<e){v(a,e,f,b,c,d,g,h,i,j,k,l);e-=1;} else {
v(e,a,f,b,c,d,g,h,i,j,k,l);};f-=1;} else {
v(e,f,a,b,c,d,g,h,i,j,k,l);}}}};g-=4;} else {
if(c<g){if(c<f){if(c<e){v(a,b,c,e,f,g,d,h,i,j,k,l);e-=3;} else {
if(b<e){v(a,b,e,c,f,g,d,h,i,j,k,l);e-=2;} else {
if(a<e){v(a,e,b,c,f,g,d,h,i,j,k,l);e-=1;} else {
v(e,a,b,c,f,g,d,h,i,j,k,l);}}};f-=3;} else {
if(b<f){if(b<e){v(a,b,e,f,c,g,d,h,i,j,k,l);e-=2;} else {
if(a<e){v(a,e,b,f,c,g,d,h,i,j,k,l);e-=1;} else {
v(e,a,b,f,c,g,d,h,i,j,k,l);}};f-=2;} else {
if(a<f){if(a<e){v(a,e,f,b,c,g,d,h,i,j,k,l);e-=1;} else {
v(e,a,f,b,c,g,d,h,i,j,k,l);};f-=1;} else {
v(e,f,a,b,c,g,d,h,i,j,k,l);}}};g-=3;} else {
if(b<g){if(b<f){if(b<e){v(a,b,e,f,g,c,d,h,i,j,k,l);e-=2;} else {
if(a<e){v(a,e,b,f,g,c,d,h,i,j,k,l);e-=1;} else {
v(e,a,b,f,g,c,d,h,i,j,k,l);}};f-=2;} else {
if(a<f){if(a<e){v(a,e,f,b,g,c,d,h,i,j,k,l);e-=1;} else {
v(e,a,f,b,g,c,d,h,i,j,k,l);};f-=1;} else {
v(e,f,a,b,g,c,d,h,i,j,k,l);}};g-=2;} else {
if(a<g){if(a<f){if(a<e){v(a,e,f,g,b,c,d,h,i,j,k,l);e-=1;} else {
v(e,a,f,g,b,c,d,h,i,j,k,l);};f-=1;} else {
v(e,f,a,g,b,c,d,h,i,j,k,l);};g-=1;} else {
v(e,f,g,a,b,c,d,h,i,j,k,l);}}}};h-=4;} else {
if(c<h){if(c<g){if(c<f){if(c<e){v(a,b,c,e,f,g,h,d,i,j,k,l);e-=3;} else {
if(b<e){v(a,b,e,c,f,g,h,d,i,j,k,l);e-=2;} else {
if(a<e){v(a,e,b,c,f,g,h,d,i,j,k,l);e-=1;} else {
v(e,a,b,c,f,g,h,d,i,j,k,l);}}};f-=3;} else {
if(b<f){if(b<e){v(a,b,e,f,c,g,h,d,i,j,k,l);e-=2;} else {
if(a<e){v(a,e,b,f,c,g,h,d,i,j,k,l);e-=1;} else {
v(e,a,b,f,c,g,h,d,i,j,k,l);}};f-=2;} else {
if(a<f){if(a<e){v(a,e,f,b,c,g,h,d,i,j,k,l);e-=1;} else {
v(e,a,f,b,c,g,h,d,i,j,k,l);};f-=1;} else {
v(e,f,a,b,c,g,h,d,i,j,k,l);}}};g-=3;} else {
if(b<g){if(b<f){if(b<e){v(a,b,e,f,g,c,h,d,i,j,k,l);e-=2;} else {
if(a<e){v(a,e,b,f,g,c,h,d,i,j,k,l);e-=1;} else {
v(e,a,b,f,g,c,h,d,i,j,k,l);}};f-=2;} else {
if(a<f){if(a<e){v(a,e,f,b,g,c,h,d,i,j,k,l);e-=1;} else {
v(e,a,f,b,g,c,h,d,i,j,k,l);};f-=1;} else {
v(e,f,a,b,g,c,h,d,i,j,k,l);}};g-=2;} else {
if(a<g){if(a<f){if(a<e){v(a,e,f,g,b,c,h,d,i,j,k,l);e-=1;} else {
v(e,a,f,g,b,c,h,d,i,j,k,l);};f-=1;} else {
v(e,f,a,g,b,c,h,d,i,j,k,l);};g-=1;} else {
v(e,f,g,a,b,c,h,d,i,j,k,l);}}};h-=3;} else {
if(b<h){if(b<g){if(b<f){if(b<e){v(a,b,e,f,g,h,c,d,i,j,k,l);e-=2;} else {
if(a<e){v(a,e,b,f,g,h,c,d,i,j,k,l);e-=1;} else {
v(e,a,b,f,g,h,c,d,i,j,k,l);}};f-=2;} else {
if(a<f){if(a<e){v(a,e,f,b,g,h,c,d,i,j,k,l);e-=1;} else {
v(e,a,f,b,g,h,c,d,i,j,k,l);};f-=1;} else {
v(e,f,a,b,g,h,c,d,i,j,k,l);}};g-=2;} else {
if(a<g){if(a<f){if(a<e){v(a,e,f,g,b,h,c,d,i,j,k,l);e-=1;} else {
v(e,a,f,g,b,h,c,d,i,j,k,l);};f-=1;} else {
v(e,f,a,g,b,h,c,d,i,j,k,l);};g-=1;} else {
v(e,f,g,a,b,h,c,d,i,j,k,l);}};h-=2;} else {
if(a<h){if(a<g){if(a<f){if(a<e){v(a,e,f,g,h,b,c,d,i,j,k,l);e-=1;} else {
v(e,a,f,g,h,b,c,d,i,j,k,l);};f-=1;} else {
v(e,f,a,g,h,b,c,d,i,j,k,l);};g-=1;} else {
v(e,f,g,a,h,b,c,d,i,j,k,l);};h-=1;} else {
v(e,f,g,h,a,b,c,d,i,j,k,l);}}}}

}
#endif 
