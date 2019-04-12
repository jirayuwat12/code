#include <bits/stdc++.h>
using namespace std;

long long prime(int n){
  sum=1;
  while(n>0) sum *=n--;
  return sum;
}

int main(){
  cout<<prime(100);
}
