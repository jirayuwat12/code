#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

string * search_binary(string *ani,int size,string target){
  if(*(ani+size/2) ==target){
    return ani+size/2;
  }
  if(*(ani+(size)/2) >target){
    return search_binary(ani,size/2,target);
  }
  if(*(ani+size/2) <target){
    ani = ani + size/2 +1;
    return search_binary(ani,size/2,target);
  }
}
int sum(char *r,int size){
  int nu=0;
  for(int i=0;i<size;i++){
    nu += *(r+i);
  }
  return nu;
}
char * binary (char *c,int size){

}

}
int main(){
  string ani[]={"zebra","bee","fog","ant","dog","elephant","giraffe","cat"};
  int size = sizeof(ani)/sizeof(ani[0]);
  sort(ani,ani+size);
  string target ="zebra";
  string *t = search_binary(ani,size,target);
  // cout<<t<<"->"<<*t;
  char tt[]="aaaabaaaa";
  char* tpp = binary(tt,10);
  cout<<*tpp;
}
