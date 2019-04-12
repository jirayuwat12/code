#include "queue.h"

char enqueue(Q *f,Q *r,int size,char i){
  Q *qnew =  (Q *)malloc(sizeof(Q));
  int j=1;
  while(f->n != r){ j++;f = f->n;}
  if(j>size){
      cout<<"-Queue Overflow : Can not ENQUEUE-> "<<i<<endl;
      return i;
  }else{
    qnew->c =i;
    qnew->n = r;
    qnew->bf= r->bf;
    r->bf->n = qnew;
    r->bf = qnew;
    return 27;
  }
}
char dequeue(Q *f,Q*r){
  Q *tmp;
  char i;
  i = f->n->c;
  tmp = f->n;
  f->n = f->n->n;
  free(tmp);
  return i;
}
bool empty(Q *f,Q *r){
  if(f->n == r) return true;
  else return false;
}
int main(){
    Q *front = (Q *)malloc(sizeof(Q));
    Q *rear =(Q *)malloc(sizeof(Q));
    int size = 4,j=0;
    front->c ='s';
    front->n = rear;
    rear->bf = front;
    string i;
    cin>>i;
    string tmp="";char buff;
    for(auto i :i) {
      buff= enqueue(front,rear,size,i);
      if(buff != 27) tmp += buff;
    }
    cout<<"List-> ";
    while(!empty(front,rear)) cout<<dequeue(front,rear);
    free(front);
    free(rear);

    cout<<endl<<"tmp -> "<<tmp;
}
