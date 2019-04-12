#include <iostream>
using namespace std;
int main(){
  int sum;
  cin>>sum;
  int db[sum+1];
  db[1]=1;
  db[2]=1;
  db[3]=2;
  db[4]=4;
  for(int i=5;i<=sum;i++){
    db[i] = db[i-1] + db[i-3] +db[i-4];
  }
  cout<<db[sum];
}
