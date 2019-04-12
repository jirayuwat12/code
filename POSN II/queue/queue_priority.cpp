#include "queue.h"

void add(Q *f,int p,int w,int a){
  int ave = p/w;
  Q *qnew =(Q *)malloc(sizeof(Q));
  while(ave <= (f->ave)) f=f->n;
  qnew->n = f;
  qnew->bf= f->bf;
  f->bf=qnew;
  qnew->bf->n =qnew;
  qnew->price=p;
  qnew->weight=w;
  qnew->amount=a;
  qnew->ave = ave;
}
void del(Q *f){
  Q *tmp =f->n;
  f=f->n->n;
  free(tmp);
}
int del_once(Q *f){
    f = f->n;
    f->amount --;
    if(f->amount ==0 ) del(f);
}

int main(){
  Q *f = (Q *)malloc(sizeof(Q));
  Q *r = (Q *)malloc(sizeof(Q));
  f->ave = 1000000;
  r->ave = 0;
  f->n =r;
  f->bf=NULL;
  r->bf=f;
  r->n =NULL;
  add(f,10,10,10);
  int i,s;
  int p,w,a;
  cin>>s>>i;
  while(i>0){

    i++;
  }
}
