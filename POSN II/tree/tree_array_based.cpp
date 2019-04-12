#include <iostream>
#include <vector>
using namespace std;

typedef struct bt{
  int l;
  int r;
  int data;
}binary;
binary tmp;

void MakeRoot(vector <binary> &v,int i){
  tmp = {-1,-1,i};
  v.push_back(tmp);
}
void add(vector <binary> &v,int i,int isright,int pa){
  int j;
  for(j=0;j<v.size();j++){
    if(v[j].data == pa) break;
  }
  v.push_back({-1,-1,i});
  if(isright) v[j].r = v.size()-1;
  else v[j].l = v.size()-1;
}


int main(){
  vector <binary> v;
  MakeRoot(v,25);
  add(v,67,0,25);
  add(v,47,1,67);
  add(v,37,1,47);
  add(v,57,1,25);
  add(v,17,1,37);
  for(int i=0;i<v.size();i++){
    cout<<i<<" : "<<v[i].l<<" "<<v[i].data<<" "<<v[i].r<<endl;
  }
}
