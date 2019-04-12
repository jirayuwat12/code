#include <iostream>
using namespace std;
/*
Subset sum problem
 input <- { 2 , 3 , 7 , 8 , 10 } ( n = 5 )
 input <- total
 output -> true, false
 use array 2D -> t[n + 1][total + 1]
 Ex.
  total <- 8
  input <- {1,2,5,7} (n = 4)
  Array t[5][9]
  Start : set value in array
  input | sum-> | 0  1  2  3  4  5  6  7  8
  [0] 0           T  F  F  F  F  F  F  F  F  #t[0][1:] = F
  [1] 1           T (S)
  [2] 2           T
  [3] 5           T
  [4] 7           T
                  #t[:][0] = T
  Pseudo code:
    loop i from 1 to n do
      loop j from 1 to total do
        if j less than input[i] then
          t[i][j] <- t[i-1][j]
        else do
          t[i][j] <- t[i-1][j] or t[i-1][j-input[i]]
*/
int main(){
  int total = 193;
  int input[]= {1,2,5,7,103,2,3,4,5,6,7,8,8,9,9,0,5,3,2,2,1,1,2,2,39499,5,9,5,5,4,4,2,2};
  int n = sizeof(input) / sizeof(input[0]);
  bool t[n+1][total+1];
  for(int i=1;i<=total;i++) t[0][i] = false;
  for(int i=0;i<=n;i++) t[i][0] = true;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=total;j++){
      if(j < input[i-1]) t[i][j] = t[i-1][j];
      else t[i][j] = (t[i-1][ j] || t[i-1][j-input[i-1]]);
    }
  }
  cout<<t[1][1];
 }
