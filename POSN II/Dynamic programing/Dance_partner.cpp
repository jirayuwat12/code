#include <iostream>
using namespace std;
int main(){
  int n=15;
  int db[n+1];
  for(int i=0;i<=n;i++)
    if(i<=2) db[i] = i;
    else db[i] = db[i-1] + (i-1)*db[i-2];
  cout<<db[n];
}
