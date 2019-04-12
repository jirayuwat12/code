#include <iostream>
#include <utility>
#include <math.h>
using namespace std;
typedef struct tree {
  int d;
  struct tree *l,*r,*p;
}T;
int h (T *t){
  if(t ==NULL) return 0;
  else return 1+ max(h(t->l),h(t->r));
}
pair <int,T*> find(T *r,int data){
  if(r->d == data) return {-1,r};
  if(r->r == NULL && r->d <data ) return{1,r};
  if(r->l == NULL && r->d >data ) return{0,r};
  if(r->d < data) return find(r->r,data);
  if(r->d > data) return find(r->l,data);
  return {-1,NULL};
  /*
  1 == r;
  0 == l;
  */
}
void add(T *r,int data){
  T *nt= new T;
  nt->r = nt->l = NULL;
  nt->d=data;
  pair<int,T*> tmp =find(r,data);
  if(tmp.first != -1){  if(tmp.first ==1) tmp.second->r =nt;
  else tmp.second->l =nt;
  nt->p = tmp.second;}
}
void cout_in(T *r){
  if(r->r != NULL) cout_in(r->r);
  // cout<<r->d<<"="<<r->p->d<<" ";
  cout<<r->d<<" ";
  if(r->l != NULL) cout_in(r->l);
}
void cout_inrange(T *r,int a,int b){
    if(r->l != NULL) cout_inrange(r->l,a,b);
    if(r->d >=a && r->d <=b) cout<<r->d<<" ";
    if(r->r != NULL ) cout_inrange(r->r,a,b);
}
void cout_inrange_1(T *r,int a,int b){
  if(r->l != NULL && r->l->d >=a) cout_inrange(r->l,a,b);
  if(r->d >=a && r->d <=b) cout<<r->d<<" ";
  if(r->r != NULL && r->r->d <=b) cout_inrange(r->r,a,b);
 }
T *find_min(T *r){
  if(r->l != NULL) return find_min(r->l);
  else return r;
}
T *find_max(T *r){
  if(r->r != NULL) return find_max(r->r);
  else return r;
 }
pair<int,T *> find_del(T *r,int data){
    if(r->d    == data) return {2,r};
    if(r->l != NULL) if(r->l->d == data) return {0,r};
    if(r->r != NULL) if(r->r->d == data) return {1,r};
    if(r->d < data) return find_del(r->r,data);
    if(r->d > data) return find_del(r->l,data);
    return {-1,NULL};
}

pair<int,T *> del(T *r,int target){
  pair <int,T*> pairtmp =find_del(r,target);
  if(pairtmp.first == -1) return {0,NULL};
  else{
    if(pairtmp.first ==2){
      if(r->l ==NULL && r->r == NULL) {r->r=NULL;r->l=NULL;r->d=0;return {2,NULL};}
      if(r->l ==NULL) {r = r->r;return {2,r};}
      if(r->r ==NULL) {r = r->l;return {2,r};}
      T *tmp =r->l;
      tmp = find_max(tmp);
      r->d = tmp->d;
      if(tmp->p != r)tmp->p->r=NULL;
      else tmp->p->l =tmp->p->l->l;
      return {2,r};
      // free(tmp);
    }
    else if(pairtmp.first ==0){
      if(r->l->l ==NULL && r->l->r == NULL) {free(r->l);r->l = NULL;return {1,r};}
      if(r->l->l ==NULL) {r->l = r->l->r;return {1,r};}
      if(r->l->r ==NULL) {r->l = r->l->l;return {1,r};}
      T *tmp =r->l;
      tmp = find_max(tmp);
      r->l->d = tmp->d;
      if(tmp->p != r)tmp->p->r=NULL;
      else tmp->p->l =NULL;
      return {2,r};
      // free(tmp);
    }
    else{
      if(r->r->l ==NULL && r->r->r == NULL) {free(r->r);r->r = NULL;return {1,r};}
      if(r->r->l ==NULL) {r->r = r->r->r;return {1,r};}
      if(r->r->r ==NULL) {r->r = r->r->l;return {1,r};}
      T *tmp =r->r;
      tmp = find_max(tmp);
      r->r->d = tmp->d;
      if(tmp->p != r)tmp->p->r=NULL;
      else tmp->p->l =NULL;
      return {2,r};
      // free(tmp);
    }
  }
  return{-1,NULL};
}
int balance(int h1,int h2){
  if(h1-h2 >1) return 1;
  if(h2-h1 >1) return 1;
  return 0;
}
int main(){
  T *root = new T;
  int i,j,d,b;
  cout<<"Enter root";cin>>d;
  root->d = d;
  root->l =NULL;
  root->r =NULL;
  root->p =root;
  char a;cin>>a;
  cin>>d;
  pair <int,T *> t;
  while(a != 'e'){
    if(a =='a') add(root,d);
    if(a =='d') {t =del(root,d);root=t.second;}
    cout<<"====="<<balance(h(root->l),h(root->r))<<endl;
    cout_in(root);
    cout<<"\n====="<<endl;
    cin>>a>>d;
  }
  // cout<<"= = = = = = = = = = = = = = = = = = = = = "<<endl;
  // cout<< " Sorted(Inorder)   :";
  // cout_in(root);
  // cout<<endl;
  // T * min = find_min(root);
  // T * max = find_max(root);
  // cout<<" Minimum           :"<<min->d<<endl;
  // cout<<" Maximum           :"<<max->d<<endl;
  // cout<<" Show from         :";cin>>a;
  // cout<<" to                :";cin>>b;
  // if(a>9 || b>9) cout<<" Show from "<<a<<"t o "<<b<< " :";
  // else if(a>9 && b>9) cout<<" Show from "<<a<<"to "<<b<< ":";
  // else cout<<" Show from "<<a<<" to "<<b<< "  :";
  // cout_inrange_1(root,a,b);
  // int t;
  // cout<<endl<<" Target to delete  :";cin>>t;
  // pair<int,T*> tmp =del(root,t);
  // root = tmp.second;
  //
  // cout<<" Delete code       :"<<tmp.first<<endl;
  // cout<<" Deleted           :";cout_in(root);
}
