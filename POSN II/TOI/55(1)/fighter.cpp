/*
TASK:fighter.cpp
LANG:C++
AUTHOR:Jirayuwat Boonchan
CENTER:PSU
*/
#include <iostream>
using namespace std;
bool issame(int i,int j){
  if(i%2 == j%2) return true;
  else return false;
}
int main(){
 int po,pe,comb=0,b,i,d=1;
 cin>>po;
 pe=po;
 cin>>i;
 b=i;
 while(1){
   if(issame(i,b)) comb++;
   else {
     comb = 1;
     d=1;
   }
   if(comb >=3) d= 3;
   if(issame(i,2)) po-=d;
   else pe-=d;
   if(po<1) {cout<<0<<endl<<i;return 0;}
   else if(pe<1) {cout<<1<<endl<<i;return 0;}
   b=i;
   cin>>i;
 }
}
