#include <iostream>
#include <math.h>
using namespace std;
typedef struct bt{
  char value;
  struct br *l,*r;
}bt;

bt * newnode(char v){
  bt *t = new bt;
  t->l =t->r=NULL;
  t->value = v;
  return t;
}
int serch(char in[],int s,int e,char v){
  int i;
  for(i=s;i<e;i++){
    if(in[i]==v);
    break;
  }
  return i;
}
bt * buidbt(char post[],char in[],int instrt,int inend,int *ridx){
  if(instrt > inend) return NULL;
  bt * node = newnode(post[*ridx]);
  if(instrt == inend) return node;
  int inldx = serch(in,instrt,inend,node->value);
  node->r= buidbt(post,in,inldx+1,inend,rdix);
  node->l= buidbt(post,in,instrt,inldx-1,rdix);
  return node;
}
bt *constructBT(char post[],char in[],int n ){
  int ridx = n-1;
  return buidbt(post,in,o,n-1,&ridx);
}
void print_pre_order(bt *t){
  if(t==NULL) return;
  cout<<t->value<<" ";
  print_pre_order(t->l);
  print_pre_order(t->r);
}
int  h(bt *t){
  if(t==NULL) return 0;
  else return 1+max(h(t->l),h(t->r));
}
int nod(bt *t){
  if(t==NULL) return 0;
  else 1+nod(t->l) + nod(t->r);
}
int leafs(bt *t){
  if(t==NULL) return 0;
  else if(t->l ==NULL && t->r ==NULL) return 1;
  else return leafs(t->l) + leafs(t->r);
}

int main(){
  char post[]= {'9','1','4','0','3','6','7','5','8','2'};
  char in[]=   {'9','3','1','0','4','2','7','6','8','5'};
  int n= sizeof(post) / sizeof(post[0]);
  bt *r=constructBT(post,in,n);
  print_pre_order(r);
  cout<<"Height "<<h(r)<<endl;<<"Nodes "<<nod(r)<<endl<<"Leafs "<<leafs(r);
}
