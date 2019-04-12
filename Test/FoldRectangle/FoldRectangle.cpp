#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int y=1,sum=0;
  int f[]={2,3,5,1,4};
  sort(f,f+4);
  for(int i=0;i<5;i++) sum+= f[i]*y,y++;
  cout<<sum;
}
