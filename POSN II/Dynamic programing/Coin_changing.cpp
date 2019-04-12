#include <iostream>
using namespace std;
/*
Coin changing : minimun number of coins
  Ex 1 .
    Array C [p] <- coin's number
    Array S [p] <- last used coin
    Array D [x] <- value of each coin
      Ex.  16 $ -> p = 17(16 + 1)

      D [x]<-   { 1 ,5 ,12 ,25 }
      x -> 4

            index  0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16
      C [p]->      0  1  2  3  4  1  2  3  4  5  2   3   1   2   3   3   4
      S [p]->      0  0  0  0  0  1  0  0  0  0  1   0   3   0   0   1   0
      so minimum of coin changing for 16 $ is 4 coins by take
       1$ x 1 coin
       5$ x 3 coins
      total 4 coins
    Pseudo code:
      D[] <- each coin's value
      value <- value of monney
      C[] <- number of coins for these value
      S[] <- last used coin for these value
      min <- minimum for number of each coin
      C[0] <- 0 'cause 0 $ used 0 coin only
      loop from 1 to value-1 (p) :
        min <- 100
        loop from 0 to 4 and stop when D[i] less than p :
          if min less than C[p-D[i]] +1 then min <- C[p- D[i]] +1 and S[p] <- D[i];
        C[p] <- min;
      while i greater than 0 :
        print S[i]
        i <- i-S[i]
*/
int main(){
  int D[] = {1,5,12,25};
  int coin =4;
  int value;
  cout<<"Enter value ";cin>>value;
  value += 1;
  int C[value];
  int S[value];
  int min=10000;
  C[0] = 0; // 0 coin for 0$.It's fare.

  for(int p=1;p<value;p++){
    min = 100;
    for(int i=0;i<coin && D[i] <= p;i++){
      if(min > C[p-D[i]] +1) min = C[p- D[i]] +1,S[p]=D[i];
    }
    C[p]=min;
  }
  cout<<C[value -1]<<" for "<<value-1<<" $\n";
  int i=value-1;
  while(i>0){
    cout<<S[i]<<" ";
    i -=S[i];
  }
}
