#include <iostream>
using namespace std;
int sell(int y,int b,int en,int t[]){
  int num;
  if(b<=en)  num = max( sell(y+1,b+1,en,t) + y*t[b] , sell(y+1,b,en-1,t) + y*t[en] );
  return num;
}

int main(){
  int t[]={2,3};
  int sum = sell(1,0,1,t);
  cout<<sum;
}
