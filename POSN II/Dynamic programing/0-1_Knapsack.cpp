#include <iostream>
// #include <math.h>
using namespace std;
/*
0/1 Kanpsack
  Requirement
    1. Have LIMIT.
    2. Have weight and value of each item
    3. Choose items that sum. less than LIMIT.
  Ex 1 .
    4 items :
           item   1  2  3  4
              W   1  3  4  5
              V   1  4  5  7
        address   0  1  2  3
            limit weight : 7 ->> 1 & 2 (9)
    Solition :
    2x2 matrix :  Column <- limit + 1(start from 0)
                  Row <- items + 1 (start from 0)
                i
                |
                V  Matrix's name : T
            j->   0 1 2 3 4 5 6 7
                0 0 0 0 0 0 0 0 0 ROW #0 <- 0
                1 0
                2 0
                3 0
                4 0
                  COLUMN #0 <- 0
      Pseudo Code :
        loop start from 0 to item (i):
          loop start from 0 to w (j):
            if i is 0 or j = 0 then T[i][j] <- 0
            else :
              if j less than w[i-1] then T[i][j] <- T[i-1][j]
              else T[i][j] <- maximum of v[i-1] + T[i-1][j-w[i-1]] and T[i-1][j]
      Matrix :
              i
              |
              V  Matrix's name : T
          j->   0 1 2 3 4 5 6 7
              0 0 0 0 0 0 0 0 0
              1 0 1 1 1 1 1 1 1
              2 0 1 1 4 5 5 5 5
              3 0 1 1 4 5 6 6 9
              4 0 1 1 4 5 6 8 9

*/
int main(){
  int num,limit;
  num = 4;
  int w[] ={3,2,4,1};
  int v[] ={100,20,60,40};
  limit = 5;
  int t[num+1][limit+1];
  for(int i=0;i<num+1;i++){
    for(int j=0;j<limit+1;j++){
      if(i==0 || j==0) t[i][j] =0;
      else{
        if(j<w[i-1]) t[i][j] = t[i-1][j];
        else t[i][j] = max(v[i-1]+t[i-1][j-w[i-1]],t[i-1][j]);
      }
    }
  }
  cout<<"items :"<<num<<"\nlimit :"<<limit<<endl<<endl;
  for(int i=0;i<num;i++) cout<<i<<" -> "<<"w : "<<w[i]<<"  | v : "<<v[i]<<endl;
  cout<<endl;
  for(int i=1;i<num+1;i++){
    for(int j=1;j<limit+1;j++){
      cout<<t[i][j]<<"\t";
    }
    cout<<endl<<endl;
  }
}
