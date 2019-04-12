#include <bits/stdc++.h>
using namespace std;

struct student {
  int id;
  char name[50];
};
/*
input num
malloc
input name id
sort id
*/
void swap(struct student *a,struct student *b){
  struct student t = *a;
  *a = *b;
  *b = t;
}
void sort(struct student *t,int n){
  bool ck=true;
  while(ck){
    ck = false;
    for(int i=0;i<n;i++){
      if((*(t+i)).id > (*(t+i+1)).id){
        swap((t+i),(t+1+i));
        ck = true;
      }
    }
  }
}
int main(){
  int i,studentnumber ;
  cout<<"Enter number of student :";
  cin>>studentnumber;
  cout<<endl;
  struct student *db;
  db  = (struct student *)malloc(sizeof(struct student)*studentnumber);

  for(i=0;i<studentnumber;i++){
    cout<<"no."<<i+1<<" name:";
    cin>>(*(db+i)).name;
    cout<<"no."<<i+1<<" id:";
    cin>>(*(db+i)).id;
  }
  sort(db,studentnumber-1);
  cout<<"==========SORTED=========="<<endl;
  for(i=0;i<studentnumber;i++){
    cout<<"no."<<i+1<<" name:"<<(*(db+i)).name<<endl;
    cout<<"no."<<i+1<<" id:"<<(*(db+i)).id<<endl;
  }
  free(db);
}
