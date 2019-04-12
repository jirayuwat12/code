#include <iostream>
using namespace std;
/*
Minimum jump to reach end :
    input  <- { 2 , 3 , 1 , 1 , 2 , 4 , 2 , 0 , 1 , 1 } ( n <- size )
  create 2 arrays
    t(jump)<- memset to infinity
    actual <-
  Pseudo code:
    loop i from 1 to n-1 do
      loop j from 0 to i-1 do
        if i less or equal j + input[j] then t[i] <- minimum of t[i] and t[j]+1
*/
int main(){
  int l=3,r=10;
  int db[r] = {2,4,3,5,6,7,8,3,2,1};
  int t[r];
  int sum,re[r];
  t[0]=0;
  for(int i=0;i<r;i++){
    sum =0;
    for(int j=0;j<=i;j++){
      sum+=db[j];
    }
    re[i] =sum;
  }
  for(int i=0;i<r;i++){
    for(int j=1;j<=3 && i-j>=0;j++){
      re[i] = min(re[i],db[i]+re[i-j]);
    }
  }
  r--;
  cout<<re[r]<<" : ";
  for(int i=re[r];r>=0;r--){
    if(i == re[r]) cout<<db[r]<<" ",i=re[r]-db[r];
  }
}
