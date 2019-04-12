#include <iostream>
using namespace std;
void swap(int *a,int *b){
  int tmp = *b;
  *b= *a;
  *a= tmp;
}
int sort_bubble(int arr[],int size){
  bool ck=true;
  while (ck) {
    ck = false;
    for(int i=1;i<size;i++){
      if(arr[i] < arr[i-1]){
        swap(arr+i,arr+i-1);
        ck = true;
      }
    }
  }
  return 0;
}
int sort_merge(int arr[],int l,int r,int re[]){
  int m = (l+r)/2;
  if(l<r){
    sort_merge(arr,l,m,re);
    sort_merge(arr,m+1,r,re);
  }
  m =r;
  int j=l;
  for(int i=l;i<=r;i++){
    if(arr[l] > arr[m]) re[++j] = arr[m++];
    else if(arr[l] < arr[m]) re[++j] = arr[l++];
  }
  for(int i=l;i<r;i++){
    arr[i]=re[i];
  }
  return 0;
}

int main(){
  int arr[] = {23,56,78,76,54,32,45,35,67,88,99,11,12,1,4,43,37,62};
  int size = sizeof(arr) / sizeof(arr[0]);
  int result[size];
  sort_merge(arr,0,size-1,result);
  for(int i=0;i<size;i++) cout<<result[i]<<" ";
}
