#include "queue.h"
int size = 4;
int add_index(int a){
//  cout<<"=="<<a<<"=="<<endl;
  if(a ==size-1) a=0;
  else a ++;
  return a;
}
bool full(int f,int r){
  if((add_index(r))==f) return true;
  else return false;
}
void enqueue(int *q,int *f,int *r,int i){
  if(!full(*f,*r)){
    (*r) = add_index(*r);
    *(q+(*r)) = i;
    if(*f ==-1) *f =0;
  }
  else cout<<"Queue is full"<<endl;
}
int dequeue(int *q,int *f,int *r){
//  cout<<*f<<" "<<*r<<endl;
  int i= (*(q+(*f)));
  (*(q+(*f))) = 0;
  if((*f == *r)&& *f !=-1){
    *f = -1;
    *r = -1;
  }
  else {
    *f = add_index(*f);
  }
  return i;
}
int main(){
  int *a = (int *)malloc(sizeof(int)*4);
  int f=-1,r=-1;
}
