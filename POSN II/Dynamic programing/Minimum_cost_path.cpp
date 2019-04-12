#include <iostream>
using namespace std;
/*
   1(s) 3    5    8
   4    2    1    7
   4    3    8    3(s)
   (s) -> (s)

*/
int main(){
  int m=3;
  int n=4;
  int cost[m][n] = { {1,3,5,8},
                     {4,2,1,7},
                     {4,3,8,3}
                   };
  cout<<endl;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cout<<" "<<cost[i][j];
    }cout<<endl;
  }
  cout<<endl;
  int result[m][n];
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(i==0 && j == 0) result[i][j] = cost[i][j];
      else if(i==0) result[i][j] = cost[i][j] + result[i][j-1];
      else if(j==0) result[i][j] = cost[i][j] + result[i-1][j];
      else result[i][j] = cost[i][j] +min(result[i-1][j-1],(min(result[i][j-1],result[i-1][j]))) ;
      cout<<" "<<result[i][j];
    }cout<<endl;
  }
  cout<<endl<<" "<<result[m-1][n-1];
  int arr[max(m,n)];
  int i=0;
  m--;n--;
  /*
  0 = d && r
  1 = d
  2 = r
  */
  while(m != 0 || n != 0 ){
    if(result[m][n] - cost[m][n] == result[m][n-1]) arr[i++]  = 2,n--;
    if(result[m][n] - cost[m][n] == result[m-1][n]) arr[i++]  = 1,m--;
    if(result[m][n] - cost[m][n] == result[m-1][n-1]) arr[i++]= 0,m--,n--;
  }
  cout<<endl<<" ";
  for(i--;i>=0;i--){
    cout<<arr[i]<<" ";
  }

}
