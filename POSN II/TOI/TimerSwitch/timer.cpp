#include <iostream>
#include <fstream>
using namespace std;
/*

*/
int main(){
  ifstream file;
  file.open("F:\\code\\POSN II\\TOI\\TimerSwitch\\20.txt");
  char r;
  int n=432432,i=0;
  bool db[n];
  while(file >>r && i<n){
    if(r=='0') db[i++] = false;
    else if(r=='1') db[i++] = true;
  }
  cout<<i;
  // cout<<"a";

  file.close();
  int j;
  int m=1;
  i=0;
  j= i+m;
  while(j<n){
    j =i+m;
    if(db[j] == db[i]) i++;
    else i=0,m++;
  }m--;
  // cout<<m;
}
