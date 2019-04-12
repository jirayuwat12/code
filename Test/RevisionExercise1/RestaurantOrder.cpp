#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct node{
  int c,t;
  struct node *n,*p;
}N;
void insert(N *h,int c,int t){
  while(c> h->c ) h = h->n;
  while(c==h->c && t<=h->t) h= h->n;
  N *nd= (N *)malloc(sizeof(N));
  nd->c=c;
  nd->t=t;
  nd->n=h;
  nd->p=h->p;
  h->p->n=nd;
  h->p=nd;
}
int main(){
  N *h = (N *)malloc(sizeof(N));
  N *r = (N *)malloc(sizeof(N));
  h->c=0;
  h->t=51;
  h->p=NULL;
  h->n=r;
  r->c=16;
  r->t=0;
  r->n=NULL;
  r->p=h;
  int n,c,t;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>c>>t;
    insert(h,c,t);
  }
  cout<<endl;
  for(int i=0;i<n;i++){
    h = h->n;
    cout<<h->c<<' '<<h->t<<endl;
  }
}
