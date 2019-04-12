#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  int max,ans=0;
  cin>>max;
  int d[n],sum=0;
  for(int i=0;i<n;i++) cin>>d[i],sum+=d[i];
  if(max <= 6*n && max >=n){
    sort(d,d+n);
    if(sum > max){
      n--;
      while(sum >max) ans++,sum -=d[n--] -1;
    }
    else if(sum <max) {
      int i=0;
      while(sum<max) ans++,sum += 6-d[i++];
    }
    cout<<ans;
  }
  else cout<<"Error";
}
// 7
// 42
// 1
// 3
// 5
// 3
// 6
// 4
// 2
// 24
// ans=6
