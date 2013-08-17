#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "../arrays.cpp"
#include "../helpers.cpp"
#include "../calc.cpp"

using namespace std;

unsigned char taken[20]={4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};		//if I would only know how to pass arrays.
unsigned char pos[24]={128,128,128,128,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};	//position of the number in the array


inline void fix(unsigned char a){		//number to be corrected. (easy because the list is already sorted)
  taken[pos[a+1]]=a;pos[a]=pos[a+1];pos[a+1]=128;
}

inline void fix2(unsigned char a,unsigned char b){
  pos[a]=128;
  for(unsigned char i=pos[a+1];i<20;i++){pos[taken[i]]--;taken[pos[taken[i]-1]]=taken[i];}	//shift the whole array one to the left
  pos[b]=19;taken[19]=b;						//and set the old value of D at the end.
}

void regenerate(unsigned char a, unsigned char b, unsigned char c, unsigned char d){
  unsigned char tmp=0;
  for(unsigned char i=0;i<a;i++){taken[tmp]=i;tmp++;}
  for(unsigned char i=a+1;i<b;i++){taken[tmp]=i;tmp++;}
  for(unsigned char i=b+1;i<c;i++){taken[tmp]=i;tmp++;}
  for(unsigned char i=c+1;i<d;i++){taken[tmp]=i;tmp++;}
  for(unsigned char i=d+1;i<24;i++){taken[tmp]=i;tmp++;}
}

int main(void){

//generate all the numbers which are independent when sorted by size and don't contain equal numbers
//only iterate through the numbers which are bigger than the prestanding ones

unsigned char A=0,B=1,C=2,D=3,E=4,F=5,G=6,H=7,e=0,f=0,g=0,h=0;
int count=0;

do{
  if(count!=poscenters(A,B,C,D,E,F,G,H)) cout << A+0 << ";" << B+0 << ";" << C+0 << ";" << D+0 << ";" << E+0 << ";" << F+0 << ";" 
	<< G+0 << ";" << H+0 << ";" << count+0 << ";" << poscenters(A,B,C,D,E,F,G,H) << "\n";
  count++;
  if(h!=16){h++;H=taken[h+3];}									//take the next free number
  else{
    if(g!=16){g++;G=taken[g+2];h=g;H=taken[h+3];}						//same, but reset h
    else{
      if(f!=16){f++;F=taken[f+1];g=f;G=taken[g+2];h=g;H=taken[h+3];}				//and so on
      else{
	if(e!=16){e++;E=taken[e];f=e;F=taken[f+1];g=f;G=taken[g+2];h=g;H=taken[h+3];}
	else{
	  if(D!=23){/*fix(D);*/D++;regenerate(A,B,C,D);}					//increase, but update the taken numbers
	  else{
	    if(C!=22){/*fix(C);C++;D=C+1;fix2(D,23);*/
	      C++;D=C+1;regenerate(A,B,C,D);}
	    else{
	      if(B!=21){/*fix(B);B++;C=B+1;fix2(C,22);D=C+1;fix2(D,23);*/
		B++;C=B+1;D=C+1;regenerate(A,B,C,D);}
	      else{
		/*fix(A);A++;B=A+1;fix2(B,21);C=B+1;fix2(C,22);D=C+1;fix2(D,23);*/
		A++;B=A+1;C=B+1;D=C+1;regenerate(A,B,C,D);
		cout << A+0 << "\n";
	      }
	    }
	  }
	  e=0;f=0;g=0;h=0;E=taken[e];F=taken[f+1];G=taken[g+2];H=taken[h+3];	//and reset the lower bytes;this would be TWO asm instructions :( 
	}
      }
    }
  }
}while(A<21);

}
