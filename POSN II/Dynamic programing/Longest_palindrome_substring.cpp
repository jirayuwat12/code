#include <iostream>
using namespace std;
/*
Longest palindrome substring
  Ex "racecar" , "anna"
  "anna" -> n = 4
  bool t[n][n]
          a n n a
        a T F F T -> start=0 , max = 4
        n   T T F -> start=1 , max = 2
        n     T F
        a       T
  "geeker" -> n = 6
          g e e k e r
        g T F F F F F
        e   T T F F F -> start = 1 , max = 2
        e     T F T F -> start = 2 , max = 3
        k       T F F
        e         T F
        r           T
  Pseudo code:
    loop i from 0 to n-1 do
      t[i][i] <- true      // 1 letter
    loop i from 0 to n-2 do
      if str[i] equal str[i + 1] then
        t[i][i+1] <- true
        start <- i
        max <- 2
      else  t[i][i+1] <- false
    loop k from 3 to n do
      loop i from 0 to n-k do
        j <- i + k - 1
        if t[i+1][j-1] and str[i] + str[j] then
          t[i][j] <- true
          if k greater or equal max then
            max <- k
            start <- i
    k = lenght of word that we processing
    i = index that start processing
    j = index that stop processing
*/
int main(){
  char str[] = "pqoqpdrp";
  int n = sizeof(str) / sizeof(str[0])-1,start=0,max=0;
  bool t[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      t[i][j] = false;
    }
  }
  for(int i=0;i<n;i++){
    t[i][i] = true;
  }
  for(int i=0;i<n-1;i++){
    if( str[i] == str[i+1]) {
      t[i][i+1] = true;
      start = i;
      max = 2;
    }
    else t[i][i+1] =false;
  }
  for(int k=3;k<=n;k++){
    for(int i=0;i<n-k+1;i++){
      int j = i+k-1;
      if(t[i+1][j-1] && str[i] == str[j] ){
        t[i][j] = true;
        if(k>=max){
          max = k;
          start = i;
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<t[i][j]<<" ";
    }cout<<endl;
  }
  cout<<"Max lenght :"<<max<<endl;
  cout<<"Palindrome string :";
  for(int i=0;i<max;i++){
    cout<<str[start+i]<<" ";
  }
}
