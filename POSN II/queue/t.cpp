#include <iostream>
using namespace std;
#define size 10
typedef struct queue{
  int price;
  int weight;
  int amount;
  int ave;
  struct queue *n;
  struct queue *p;
}Q;
void enqueue(Q *f,char i,int pri){
  Q *qnew = (Q *)malloc(sizeof(Q));
  while(f->pri <= pri) f= f->n;
    qnew->c = i;
    qnew->pri = pri;
    qnew->n = f;
    qnew->p = f->p;
    f->p->n = qnew;
    f->p = qnew;

}
char  dequeue(Q *f){
  char tmp =f->n->c;
  f->n = f->n->n;
  free(f->n->p);
  f->n->p = f;
  return tmp;
}
int main(){
  Q *f =(Q *)malloc(sizeof(Q));
  Q *r =(Q *)malloc(sizeof(Q));
  f->ave =0;
  r->ave =100;
  f->n = r;
  f->p = NULL;
  r->n = NULL;
  r->p = f;
  int s,k;
  cin>>s>>k;
}
