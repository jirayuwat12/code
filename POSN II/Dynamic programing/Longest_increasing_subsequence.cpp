#include <iostream>
using namespace std;
/*
  Longest increasing subsequence

    #1 start          i(compare each number before i)(start from 1)
    input [11]  -> 0  4  12 2  10 6  9  13 3  11 7  15 (n = 12)
    lenght [11] -> 1  1  1  1  1  1  1  1  1  1  1  1 set all member to 1
    sub [11]    ->

    #2            0  1  2  3  4  5  6  7  8  9  10 11
    input      -> 0  4  12 2  10 6  9  13 3  11 7  15 (11)
    lenght [11]-> 1  2  3  2  3  3  4  5  3  5  4  6
    sub [11]   -> -  0  1  0  3  3  5  6  3  6  8  9
    so longest subsequence is 6 order by 15  11  9  6  2  0

  Pseudo code:
    loop i from 1 to n-1 do
      loop j from 0 to i-1 do
        if input[i] greater than input[j] then
          if lenght[i] less or equal lenght[j]+1 then
            lenght[i] <- lenght[j]+1
            sub[i] <- j;

*/
int main(){
  int input[] = {9,21,8,32,20,49,40,60,70};
  int size = sizeof(input) / sizeof(input[0]);
  int lenght[size],sub[size];
  lenght[0]=1;

  for(int i=1;i<size;i++){
    lenght[i]=1;
    for(int j=0;j<i;j++){
      if(input[i] > input[j] && lenght[i]<=lenght[j]+1) lenght[i] = lenght[j]+1,sub[i] = j;
    }
  }

  int max = 0,maxindex;
  for(int i=0;i<size ;i++) if (max<lenght[i]) max=lenght[i],maxindex =i;
  cout<<max<<" : ";
  while(maxindex >=0) cout<<input[maxindex]<<" ",maxindex = sub[maxindex];
}
