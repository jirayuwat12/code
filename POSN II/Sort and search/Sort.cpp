#include <iostream>
#include <map>
using namespace std;
void swap_int(int *a,int *b){
  int tmp =*a;
  *a=*b;
  *b= tmp;
}
void swap_char(char *a,char *b){
  char tmp =*a;
  *a=*b;
  *b= tmp;
}
void sort_bubble(char arr[],int size){
  bool ck=true;
  while(ck){
    ck =false;
    for(int i=1;i< size;i++){
      if(arr[i] < arr[i-1]){
        swap(arr[i],arr[i-1]);
        ck=true;
      }
    }
    // for(int i=0;i<size;i++) cout<<arr[i];
    // cout<<endl;
  }
}
int find_min(char arr[],int size,int i){
  char min='z';
  int min_index;
  for(i;i<size;i++){
    if(arr[i]<min) min =arr[i],min_index=i;
  }
  return min_index;
}
void sort_selection(char arr[],int size,int k){
  for(int i=0;i<k;i ++){
    int in = find_min(arr,size,i);
    swap(arr[in],arr[i]);
  }
}
void insert(char arr[],int j,int i){
  char tmp=arr[j];
  for(int k=j;k>i;k--){
    swap(arr[k],arr[k-1]);
  }
  *(arr+i)=tmp;
}
int sort_insertion(char arr[],int size){
  int num=0;
  for(int i=1;i<size;i++){
    int j;
    char tmp = arr[i];
    for(j=0;j<i;j++){
      if(arr[j] > arr[i]) break;
    }
    for(int k=i;k>j;k--){
      arr[k] =arr[k-1];num++;
    }
    arr[j]=tmp;
  }
  // for(int j=0;j<size;j++){
  //   for(int  i=0;i<j;i++){
  //     if(arr[i] > arr[j]) num++;
  //   }
  // }
  return num;
}
void sort_shell(char arr[],int size){
  int group = size;
  int z;
  char tmp[size];
  while(group != 0){
    group/=2;
    z=-1;
    int j;
    for(int i = group;i<size;i++){
      char tmp= arr[i];
      for(j=i;j>=group && arr[j-group] > tmp;j -=group){
        arr[j]=arr[j-group];
      }
      arr[j]=tmp;
    }
  }
}

void sort_merge(int a[],int l,int r,int b[]){
  int m = (l+r)/2;
  if(l<r){
    sort_merge(a,l,m,b);
    sort_merge(a,m+1,r,b);
  }
  int pl=l,pr=m+1;
  for(int i=l;i<=r;i++){
    if(pl == m+1){
      b[i]=a[pr];
      pr++;
    }else if(pr == r+1){
      b[i]=a[pl];
      pl++;
    }else if(a[pr] <a[pl]){
      b[i] = a[pr];
      pr++;
    }else{
      b[i] = a[pl];
      pl++;
    }
  }
  for(int i=l;i<=r;i++) a[i]= b[i];
}

void sort_quick(int a[],int l,int r){
  if(l<r){
    int pv=a[r],i=l-1;
    for(int j=l;j<r;j++){
      if(a[j]<pv){
        i++;
        swap_int(a+j,a+i);
      }
    }
    swap_int(a+i+1,a+r);
    sort_quick(a,l,i);
    sort_quick(a,i+2,r);
  }
}
int main(){
  int n,k;
  cin>>n;
  int a[n],sort[n];
  for(int i=0;i<n;i++) {
    cin>>k;
    a[i]=k;
  }
  sort_quick(a,0,n-1);
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
