#include <iostream>
using namespace std;
#define MAX 32

int main(){
  int t[MAX],i;
  int data[] = {25,67,48,54,12,21,66,43,95};
  int pa[]   = {0 ,25,25,67,67,48,54,21,66};
  int child[]= {-1, 0, 1, 0, 1, 0, 0, 0, 0}; //0 L : 1 R

  int k,n = sizeof(data) / sizeof(data[0]);

  for(i=0;i<MAX;i++) t[i]=0;

  t[0]=n;
  t[1]=data[0];

  for(int j=1;j<9;j++){
    for(k=0;k<n;k++) if(pa[j] ==t[k]) break;

    if(child[j] == 1) i = 2*k +1;
    else i = 2*k;

    t[i] = data[j];
  }
  for(k=0;k<MAX;k++) cout<<t[k]<<" ";
}
