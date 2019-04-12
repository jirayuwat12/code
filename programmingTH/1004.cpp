#include <map>
#include <iostream>
using namespace std;

typedef struct queue{
  int id;
  struct queue *n;
}q;

void add(q *h,int id,map <int,int> db){
  while(h->n != NULL && db[id] != db[h->id]) h = h->n;
  while(h->n != NULL && db[id] == db[h->n->id]) h = h->n;
  q *nq = new q;
  nq->id = id;
  nq->n  = h->n;
  h->n   = nq;
}
int de(q *h){
  if(h->n != NULL){
    int tmp;
    tmp = h->n->id;
    h->n = h->n->n;
    return tmp;
  }
  return 0;
}
int main(){
  int j=-1;
  char x ;
  q *h = new q;
  h->n = NULL;
  h->id=0;
  map <int,int> db;
  db[0] = 0;
  int ns,nc;
  cin>>nc>>ns;
  int ans[ns];
  for(int i=0;i<ns;i++){
    int id,c;
    cin>>c>>id;
    db[id] = c;
  }
  cin>>x;
  while(x != 'X'){
    if(x == 'E') {
      int id;
      cin>>id;
      add(h,id,db);
    }
    else{
      ans[++j] = de(h);
    }
    cin>>x;
  }
  // while(h->n != NULL){
  //   h = h->n;
  //   ans[++j] = h->id;
  // }
  for(int i=0;i<=j;i++){
    cout<<ans[i]<<endl;
  }
  cout<<0;
}

/*
2 6
1 41
1 42
1 43
2 201
2 202
2 203
E 41
E 201
D
E 202
E 42
E 43
D
E 203
D
D
D
X

/41
//201
///202
////203
/////42
43

*/
