#include <iostream>
#include <algorithm>
using namespace std;

int binary(int db[],int l,int r){
  int m = (l+r)/2;
  if( (db[m]-db[l]) * (r-m)   >  (db[r]-db[m]) * (m-l)  ){
    if(l+1 == m ) return(db[l] + db[m])/2;
    else return binary(db,l,m);
  }
  if( (db[m]-db[l]) * (r-m)   <  (db[r]-db[m]) * (m-l)  ){
    if(r-1 == m ) return(db[r] + db[m])/2;
    else return binary(db,m,r);
  }
  return 0;
}

int main(){
  int db[] ={1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,2,1,1,1};
  int size = sizeof(db) / sizeof(db[0]);
  sort(db,db+size);
  int base = db[size/2];
  int tmp;
  cout<<base;
}
