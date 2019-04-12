#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

typedef struct t{
  int data;
  struct t *l;
  struct t *r;
}T;

T *findpa(struct t *t,int pa){
  stack<T *> st;
  T *tmp;
  st.push(t);
  while(!st.empty()){
    tmp = st.top();
    st.pop();
    if(tmp->data == pa) break;
    if(tmp->l != NULL ) st.push(tmp->l) ;
    else if(tmp->r != NULL ) st.push(tmp->r) ;

  }
  return tmp;
}

void add(T *t,int i,int isright,int pa){
  T *nt= (T *)malloc(sizeof(T));
  nt->r=NULL;
  nt->l=NULL;
  nt->data=i;
  T *pap = findpa(t,pa);
  if(isright) pap->r=nt;
  else pap->l = nt;
}

int main(){
  T *root = (T *)malloc(sizeof(T));
  root->r=NULL;
  root->l=NULL;
  root->data = 25;
  add(root,67,0,25);
  add(root,47,1,67);
  add(root,37,1,47);
  add(root,57,1,25);
  add(root,17,1,37);
  T *run = root;
  stack <T *> st;
  st.push(run);
  while(!st.empty()){
    run = st.top();
    st.pop();
    if(run->l == NULL) cout<<"NULL  ";
    else {cout<<run->l->data<<"    ";st.push(run->l);}
    cout<<" "<<run->data<<"   ";
    if(run->r == NULL) cout<<"NULL";
    else {cout<<run->r->data<<"    ";st.push(run->r);}
    cout<<endl;

  }
}
