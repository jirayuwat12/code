#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  if(n<6){
    cout<<"no";
    return 0;
  }
  bool db[n+1];
  for (int i=1;i<=n;i++) db[i] = false;
  db[0] = true;
  for(int i=6;i<=n;i++){
    bool ck = false;
    if(i-20 >=0) ck |= db[i-6] || db[i-9] || db[i-20];
    else if(i-9 >=0) ck |= db[i-6] || db[i-9];
    else ck = db[i-6];
    db[i] = ck;
    if(ck) cout<<i<<endl;
  }
}
