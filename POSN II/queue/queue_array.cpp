#include "queue.h"

bool empty(char *arr,int *f,int *r){
  if(*f == -1 && *r ==-1) return true;
  else return false;
}
bool enqueue(char a,char *arr,int *f,int *r,int size){
  if(*r < size-1){
    if(*f==-1&&*r==-1){
      arr[0] = a;
      *f =0;
      *r=0;
      return true;
    }
    else{ 
      arr[++(*r)] = a;
      return true;
    }
  }else{
    cout<<"-Queue overflow-"<<endl;
    return false;
  }
}

char dequeue(char *arr,int *f,int *r){
  char tmp;
  if(!empty(arr,f,r)){
    if(*r== *f){
      arr[*f] = '\0';
      *f = -1;
      *r = -1;
    }else{
      tmp = arr[(*f)];
      arr[*f] = '\0';
      *f ++;
    }
    *f ++;
    return tmp;
  }
  else{
    return '\0';
  }
}
void show(char *arr,int f,int r){
  cout<<"Member : ";
  while (f != r) {
    cout<<arr[f++]<<" ";
  }cout<<arr[f]<<endl;
}
int main(){
  char a[6];
  int f=-1,r=-1,j=0,size = 4;
  string i;
  cin>>i;
  while(i[j]!= '\0' && enqueue(i[j++],a,&f,&r,size));
  show(a,f,r);
  dequeue(a,&f,&r);
  show(a,f,r);
}
