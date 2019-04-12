#include<iostream>
using namespace std;
int fib(int n){
//second solution using space optimized
  if( n == 0) return 0;
  int c , b = 1, a =0;
  for(int i=2;i<=n;i++){
    c = b+a;
    a=b;
    b=c;
  }
  return b;
}
int main(){
// first solution using dynamic programing
  /*int n=100000;
  int db[n+1];
  db[0]=0;
  db[1]=1;
  for(int i=2;i<=n;i++){
    db[i] = db[i-1] + db[i-2];
  }*/

  cout<<fib(100000);
}
