#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct node{
  char name[20];
  struct node *next;
};
void add_index(struct node *p,char name[],int i){
  struct node *pnew = p;
  struct node *newbox = (struct node *)malloc(sizeof(struct node));
  strcpy(newbox->name,name);
  p = p->next;
  int j=1;
  while (j++<i && p->next != NULL) {
    pnew =p;
    p = p->next;
  }
  newbox->next = pnew->next;
  pnew->next = newbox;
}
void  add_front(struct node *p,char name[]) {
  struct node *pnew = (struct node *)malloc(sizeof(struct node));
  strcpy(pnew->name,name);
  pnew->next = p->next;
  p->next = pnew;
}
void add_back(struct node *p,char name[]){
  struct node *pnew = (struct node *)malloc(sizeof(struct node));
  strcpy(pnew->name,name);
  pnew->next = NULL;
  while(p->next !=NULL)  p = p->next;
  p->next = pnew;
}
void show(struct node *run){
  run = run->next;
  cout<<"==============="<<endl;
  int i=1;
  while(run->next !=NULL){
      if(i<10) cout<<" "<<i++<<"  :"<<" "<<run->name<<endl;
      else cout<<" "<<i++<<" :"<<" "<<run->name<<endl;
      run = run->next;
  }cout<<" "<<i<<" :"<<" "<<run->name<<endl;
}
void del_index(struct node *p,int i){
  struct node *pre = p;
  int j=1;
  p = p->next;
  while((i==0 || j<i) && p->next!=NULL){
    pre = p;
    p = p->next;
    j++;
  }
  pre->next = p->next;
  free(p);
}
void swapname(struct node *a,struct node *b){
  char tmp[20];
  strcpy(tmp,a->name);
  strcpy(a->name,b->name);
  strcpy(b->name,tmp);
}
void Sorting(struct node *head){
 struct node *temp ;
 struct node *pre ;
 bool ck =true;
 while(ck){
   ck = false;
   for(temp = head->next->next,pre=head->next;temp != NULL;temp = temp ->next,pre = pre->next){
     if(strcmp(temp->name,pre->name) <0) {
       swapname(pre,temp);
       ck =true;
     }
   }
 }
}
void del_name(struct node *p,char name[]){
  struct node *pre = p;
  p = p->next;
  while((strcmp(p->name,name)!=0) && p->next!=NULL){
    pre = p;
    p = p->next;
  }
  if(strcmp(p->name,name)==0) pre->next = p->next;
  free(p);
}
int search_index(struct node *p,char name[]){
  struct node *pre = p->next;
  int index=1;
  p = p->next->next;
  while (p->next !=NULL) {
    index++;
    if((strcmp(pre->name,name) <0) && (strcmp(p->name,name) >0)) {
      return index;
    }
    pre = p;
    p = p->next;
  }
  return 0;
}
int main(){
  struct node *header = (struct node *)malloc(sizeof(struct node));
  header->next =NULL;
  cout<<"Input 'end' if you entered name."<<endl;
  char x[20];
  while(true){
    cin>>x;
    if(strcmp(x,"end") == 0) break;
    add_front(header,x);
  }
  Sorting(header);
  show(header);
  strcpy(x,"Jarunee");
  int i=search_index(header,x);
  add_index(header,x,i);
  //Sorting(header);
  show(header);
  del_index(header,1);
  del_index(header,0);
  strcpy(x,"Jarunee");
  del_name(header,x);
  show(header);
}
