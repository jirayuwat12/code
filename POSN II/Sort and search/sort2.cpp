#include <iostream>
using namespace std;

int main(){
  int a[100],sort[100],n;
  cin>>n;
  for(int i=0;i<100 && n != 9999;i++){
    a[i]=n;
    cin>>n;
  }
  cout<<n;
}
