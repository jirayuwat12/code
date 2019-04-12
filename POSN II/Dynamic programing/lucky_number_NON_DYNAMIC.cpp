#include <iostream>
using namespace std;
/*
  2 5 7 8
8 t t t f
7 t t f f
5 t f f f
2 f f f f

  8 7 5 2
2 f f f f
5 f f f t
7 f f t t
8 f t t t

  2 5 4 7
7 f f f f
4 t f f f
5 t f t f
2 f f f f

  1 2 3 3
3 t t f f
3 t t f f
2 t f f f
1 f f f f

  1 2 3 5
5 t t t f
3 t t f f
2 t f f f
1 f f f f

n * n
*/
int main(){
  int n=4;
  char t[n];
  int ck=0;
  for(int i=0;i<n;i++) cin>>t[i];
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<n;j++){
      if(t[i] > t[j] ) ck++;
    }
  }
  if(ck ==6) cout<<"a";
  
}
